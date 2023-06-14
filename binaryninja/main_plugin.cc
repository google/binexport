// Copyright 2019-2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "third_party/zynamics/binexport/binaryninja/main_plugin.h"

#include <cstdint>
#include <string>

#include "third_party/absl/log/log.h"
#include "third_party/absl/status/status.h"
#include "third_party/absl/status/statusor.h"
#include "third_party/absl/strings/escaping.h"
#include "third_party/absl/strings/match.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/str_format.h"
#include "third_party/zynamics/binexport/binaryninja/log_sink.h"
#include "third_party/zynamics/binexport/binexport2_writer.h"
#include "third_party/zynamics/binexport/call_graph.h"
#include "third_party/zynamics/binexport/entry_point.h"
#include "third_party/zynamics/binexport/flow_analysis.h"
#include "third_party/zynamics/binexport/flow_graph.h"
#include "third_party/zynamics/binexport/instruction.h"
#include "third_party/zynamics/binexport/util/filesystem.h"
#include "third_party/zynamics/binexport/util/format.h"
#include "third_party/zynamics/binexport/util/logging.h"
#include "third_party/zynamics/binexport/util/status_macros.h"
#include "third_party/zynamics/binexport/util/timer.h"
#include "third_party/zynamics/binexport/version.h"

namespace security::binexport {

absl::StatusOr<std::string> GetInputFileSha256(BinaryNinja::BinaryView* view) {
  auto transform = BinaryNinja::Transform::GetByName("SHA256");
  if (!transform) {
    return absl::FailedPreconditionError("SHA256 not available");
  }

  auto raw_view = view->GetParentView();
  if (!raw_view) {
    return absl::InternalError("Failed to load SHA256 hash of input file");
  }
  BinaryNinja::DataBuffer buffer =
      raw_view->ReadBuffer(0, raw_view->GetLength());

  BinaryNinja::DataBuffer sha256_hash(32);
  if (!transform->Encode(buffer, sha256_hash)) {
    return absl::UnknownError("SHA256 transform failed");
  }

  return absl::BytesToHexString(
      absl::string_view(static_cast<const char*>(sha256_hash.GetData()),
                        sha256_hash.GetLength()));
}

std::string GetArchitectureName(BinaryNinja::BinaryView* view) {
  auto default_arch = view->GetDefaultArchitecture();
  std::string name = default_arch->GetName();
  std::string architecture;
  // Binary Ninja documentation has a list of architectures here:
  // https://api.binary.ninja/binaryninja.architecture-module.html#binaryninja.architecture.Architecture
  // Note: Like with IDA Pro, we're ignoring the endianness here completely.
  if (absl::StartsWith(name, "x86")) {
    architecture = "x86";
  } else if (absl::StartsWith(name, "arm") || name == "aarch64" ||
             name == "thumb") {
    architecture = "ARM";
  } else if (absl::StartsWith(name, "mips")) {
    architecture = "MIPS";
  } else if (absl::StartsWith(name, "ppc")) {
    architecture = "PowerPC";
  } else {
    architecture = "GENERIC";
  }

  switch (size_t address_size = default_arch->GetAddressSize(); address_size) {
    case 8:
      absl::StrAppend(&architecture, "-64");
      break;
    case 4:
      absl::StrAppend(&architecture, "-32");
      break;
    case 2:
      absl::StrAppend(&architecture, "-16");
      break;
    default:
      LOG(WARNING) << "Unexpected address size " << address_size
                   << " for architecture \"" << architecture
                   << "\", export may be incorrect";
      LOG_IF(WARNING, architecture != "GENERIC")
          << "If you're not using a custom processor module, you may want to "
             "file a bug";
      break;
  }
  return architecture;
}

int GetArchitectureBitness(BinaryNinja::BinaryView* view) {
  return view->GetDefaultArchitecture()->GetAddressSize() * 8;
}

template <typename T>
T GetBytes(BinaryNinja::BinaryView* view, uint64_t start, size_t length) {
  BinaryNinja::DataBuffer buffer = view->ReadBuffer(start, length);
  const size_t bytes_read = buffer.GetLength();

  LOG_IF(ERROR, bytes_read != length) << absl::StrFormat(
      "Expected %d bytes at %08X, got %d", length, start, bytes_read);

  auto* data = reinterpret_cast<typename T::value_type*>(buffer.GetData());
  return T(data, data + bytes_read);
}

std::string GetBytes(BinaryNinja::BinaryView* view,
                     const Instruction& instruction) {
  return GetBytes<std::string>(view, instruction.GetAddress(),
                               instruction.GetSize());
}

std::vector<Byte> GetSegmentBytes(BinaryNinja::BinaryView* view, uint64_t start,
                                  size_t length) {
  return GetBytes<std::vector<Byte>>(view, start, length);
}

int GetPermissions(BinaryNinja::BinaryView* view,
                   const BinaryNinja::Segment& segment) {
  int segment_flags = segment.GetFlags();
  int permissions = 0;
  if (segment_flags & SegmentDenyExecute) {
    permissions |= AddressSpace::kExecute;
  }
  if (segment_flags & SegmentWritable) {
    permissions |= AddressSpace::kWrite;
  }
  if (segment_flags & SegmentReadable) {
    permissions |= AddressSpace::kRead;
  }
  return permissions;
}

std::string GetMnemonic(
    const std::vector<BinaryNinja::InstructionTextToken>& instruction_tokens) {
  for (const auto& token : instruction_tokens) {
    if (token.type == BNInstructionTextTokenType::InstructionToken) {
      return token.text;
    }
  }
  return "";
}

bool IsPossibleFunction(BinaryNinja::BinaryView* view, Address address) {
  return !view->GetBasicBlocksForAddress(address).empty();
}

Instruction ParseInstructionBinaryNinja(
    Address address, const BinaryNinja::InstructionInfo& instruction,
    const std::vector<BinaryNinja::InstructionTextToken>& instruction_tokens,
    CallGraph* call_graph, FlowGraph* flow_graph) {
  // TODO(cblichmann): Return if no code at address

  std::string mnemonic = GetMnemonic(instruction_tokens);
  if (mnemonic.empty()) {
    return Instruction(address);
  }

  // Inside of a basic block, this is always true in Binary Ninja
  const Address next_instruction = address + instruction.length;

  // TODO(cblichmann): Create expression trees for operands
  std::string operand;
  for (int i = 1; i < instruction_tokens.size(); ++i) {
    const auto& token = instruction_tokens[i];
    absl::StrAppend(&operand, token.text);
  }
  absl::StripAsciiWhitespace(&mnemonic);
  absl::StripAsciiWhitespace(&operand);

  Operands operands;
  Expressions expressions;
  if (!operand.empty()) {
    expressions.push_back(
        Expression::Create(0, operand, 0, Expression::TYPE_SYMBOL, 0));
    operands.push_back(Operand::CreateOperand(expressions));
  }
  return Instruction(address, next_instruction, instruction.length, mnemonic,
                     operands);
}

void AnalyzeFlow(
    BinaryNinja::BinaryView* view,
    const BinaryNinja::InstructionInfo& bn_instruction,
    Instruction* instruction, FlowGraph* flow_graph, CallGraph* call_graph,
    AddressReferences* address_references,
    EntryPointManager* entry_point_manager /*, const ModuleMap& modules*/) {
  const Address address = instruction->GetAddress();
  bool has_flow = bn_instruction.branchCount == 0;
  bool handled = false;
  bool unresolved = false;
  for (int i = 0; i < bn_instruction.branchCount; ++i) {
    const uint64_t branch_target = bn_instruction.branchTarget[i];
    const BNBranchType branch_type = bn_instruction.branchType[i];
    switch (branch_type) {
      case BNBranchType::UnconditionalBranch:
      case BNBranchType::IndirectBranch:
      case BNBranchType::UserDefinedBranch:
      case BNBranchType::ExceptionBranch:
        if (branch_target != 0) {
          flow_graph->AddEdge(FlowGraphEdge(address, branch_target,
                                            FlowGraphEdge::TYPE_UNCONDITIONAL));
          address_references->emplace_back(
              address, GetSourceExpressionId(*instruction, branch_target),
              branch_target, TYPE_UNCONDITIONAL);
          entry_point_manager->Add(branch_target,
                                   branch_type == BNBranchType::IndirectBranch
                                       ? EntryPoint::Source::JUMP_INDIRECT
                                       : EntryPoint::Source::JUMP_DIRECT);
          handled = true;
        }
        break;
      case BNBranchType::CallDestination:
        if (IsPossibleFunction(view, branch_target /*, modules*/)) {
          call_graph->AddFunction(branch_target);
          call_graph->AddEdge(address, branch_target);
          entry_point_manager->Add(branch_target,
                                   EntryPoint::Source::CALL_TARGET);
        }
        ABSL_FALLTHROUGH_INTENDED;  // Do not add entry points for syscalls
      case BNBranchType::SystemCall:
        instruction->SetFlag(FLAG_CALL, true);
        address_references->emplace_back(
            address, GetSourceExpressionId(*instruction, branch_target),
            branch_target, TYPE_CALL_DIRECT);
        has_flow = true;
        handled = true;
        break;
      case BNBranchType::TrueBranch:
        flow_graph->AddEdge(
            FlowGraphEdge(address, branch_target, FlowGraphEdge::TYPE_TRUE));
        address_references->emplace_back(
            address, GetSourceExpressionId(*instruction, branch_target),
            branch_target, TYPE_TRUE);
        entry_point_manager->Add(
            branch_target,
            EntryPoint::Source::JUMP_DIRECT);  // True is main branch
        handled = true;
        break;
      case BNBranchType::FalseBranch:
        flow_graph->AddEdge(
            FlowGraphEdge(address, branch_target, FlowGraphEdge::TYPE_FALSE));
        address_references->emplace_back(
            address, GetSourceExpressionId(*instruction, branch_target),
            branch_target, TYPE_FALSE);
        entry_point_manager->Add(
            branch_target,
            EntryPoint::Source::JUMP_DIRECT);  // True is main branch
        handled = true;
        break;
      case BNBranchType::FunctionReturn:
        handled = true;
        break;
      case BNBranchType::UnresolvedBranch:
        unresolved = true;
        handled = true;
        break;
      default:
        LOG(WARNING) << absl::StrCat("Unknown branch type ", branch_type,
                                     " at ", FormatAddress(address), " target ",
                                     FormatAddress(branch_target));
    }
  }

  if (has_flow) {
    // Regular code flow
    entry_point_manager->Add(instruction->GetNextInstruction(),
                             EntryPoint::Source::CODE_FLOW);
  } else {
    // Reset flow flag. Unlike with IDA, we don't have access to flow info in
    // ParseInstructionBinaryNinja() without using LLIL.
    instruction->SetFlag(FLAG_FLOW, false);
  }

  if (BinaryNinja::Ref<BinaryNinja::BasicBlock> bn_basic_block =
          view->GetRecentBasicBlockForAddress(address)) {
    if (BinaryNinja::Ref<BinaryNinja::Function> bn_function =
            bn_basic_block->GetFunction()) {
      BinaryNinja::ReferenceSource ref_source = {
          /*func=*/bn_function,
          /*arch=*/bn_function->GetArchitecture(),
          /*addr=*/address};
      std::vector<uint64_t> xrefs = view->GetCodeReferencesFrom(ref_source);

      auto table_address = std::numeric_limits<Address>::max();
      for (const auto& xref : xrefs) {
        // TODO(cblichmann): If we have a basic block, then it's an actual
        //                   code reference (see Binary Ninja #3559).
        const bool code_reference = view->GetRecentBasicBlockForAddress(xref);
        if (unresolved && code_reference) {
          flow_graph->AddEdge(
              FlowGraphEdge(address, xref, FlowGraphEdge::TYPE_SWITCH));
          address_references->emplace_back(
              address, GetSourceExpressionId(*instruction, xref), xref,
              AddressReferenceType::TYPE_SWITCH);
          entry_point_manager->Add(xref, EntryPoint::Source::JUMP_TABLE);
          table_address = std::min(table_address, static_cast<Address>(xref));
          handled = true;
        }
        // TODO(cblichmann): All address references
      }
      if (table_address != std::numeric_limits<Address>::max()) {
        // Add a data reference to first address in switch table
        address_references->emplace_back(
            address, GetSourceExpressionId(*instruction, table_address),
            table_address, AddressReferenceType::TYPE_DATA);
      }
    }
  }
}

void AnalyzeFlowBinaryNinja(BinaryNinja::BinaryView* view,
                            EntryPoints* entry_points, Writer* writer,
                            detego::Instructions* instructions,
                            FlowGraph* flow_graph, CallGraph* call_graph) {
  Timer<> timer;
  AddressReferences address_references;

  // Add initial entry points as functions.
  for (const auto& entry_point : *entry_points) {
    if ((entry_point.IsFunctionPrologue() || entry_point.IsExternal() ||
         entry_point.IsCallTarget())) {
      call_graph->AddFunction(entry_point.address_);
    }
  }

  AddressSpace address_space;
  AddressSpace flags;
  for (const auto& segment_ref : view->GetSegments()) {
    const uint64_t segment_start = segment_ref->GetStart();
    const size_t segment_length = segment_ref->GetLength();
    const int segment_permissions = GetPermissions(view, *segment_ref);
    address_space.AddMemoryBlock(
        segment_start, GetSegmentBytes(view, segment_start, segment_length),
        segment_permissions);
    flags.AddMemoryBlock(segment_start,
                         AddressSpace::MemoryBlock(segment_length),
                         segment_permissions);
  }

  Instruction::SetBitness(GetArchitectureBitness(view));
  Instruction::SetGetBytesCallback([view](const Instruction& instruction) {
    return GetBytes(view, instruction);
  });
  Instruction::SetMemoryFlags(&flags);

  LOG(INFO) << "flow analysis";
  for (EntryPointManager entry_point_manager(entry_points, "flow analysis");
       !entry_points->empty();) {
    const Address address = entry_points->back().address_;
    entry_points->pop_back();

    if (!flags.IsValidAddress(address) || (flags[address] & FLAG_VISITED)) {
      continue;
    }
    flags[address] |= FLAG_VISITED;

    auto bn_functions = view->GetAnalysisFunctionsContainingAddress(address);
    if (bn_functions.empty()) {
      continue;
    }

    BinaryNinja::Ref<BinaryNinja::Function> bn_function = bn_functions[0];
    if (!bn_function) {
      continue;
    }

    BinaryNinja::Ref<BinaryNinja::Architecture> bn_function_architecture =
        bn_function->GetArchitecture();
    if (!bn_function_architecture) {
      continue;
    }

    size_t max_instr_len = bn_function_architecture->GetMaxInstructionLength();

    auto instr_bytes =
        GetBytes<std::vector<Byte>>(view, address, max_instr_len);
    BinaryNinja::InstructionInfo bn_instruction;
    if (instr_bytes.empty() ||
        !bn_function_architecture->GetInstructionInfo(
            &instr_bytes[0], address, max_instr_len, bn_instruction)) {
      continue;
    }

    std::vector<BinaryNinja::InstructionTextToken> bn_tokens;
    size_t instr_len = bn_instruction.length;
    if (!bn_function_architecture->GetInstructionText(&instr_bytes[0], address,
                                                      instr_len, bn_tokens)) {
      continue;
    }

    Instruction new_instruction = ParseInstructionBinaryNinja(
        address, bn_instruction, bn_tokens, call_graph, flow_graph);
    if (new_instruction.HasFlag(FLAG_INVALID)) {
      continue;
    }
    AnalyzeFlow(view, bn_instruction, &new_instruction, flow_graph, call_graph,
                &address_references, &entry_point_manager);
    // call_graph->AddStringReference(address, GetStringReference(address));
    // GetComments(ida_instruction, &call_graph->GetComments());

    instructions->push_back(new_instruction);
  }

  LOG(INFO) << "sorting instructions";
  SortInstructions(instructions);

  LOG(INFO) << "reconstructing flow graphs";
  std::sort(address_references.begin(), address_references.end());
  // TODO(cblichmann): Remove duplicates if any.
  ReconstructFlowGraph(instructions, *flow_graph, call_graph);

  LOG(INFO) << "reconstructing functions";
  flow_graph->ReconstructFunctions(instructions, call_graph,
                                   FlowGraph::NoReturnHeuristic::kNone);

  // Must be called after ReconstructFunctions() since that may remove source
  // basic blocks for an edge.
  flow_graph->PruneFlowGraphEdges();

  // Note: PruneFlowGraphEdges might add comments to the callgraph so the
  // post processing must happen afterwards.
  call_graph->PostProcessComments();

  LOG(INFO) << "Binary Ninja specific post processing";
  for (const auto& [address, function] : flow_graph->GetFunctions()) {
    // Find function name
    BinaryNinja::Ref<BinaryNinja::Symbol> bn_symbol =
        view->GetSymbolByAddress(address);
    if (!bn_symbol) {
      continue;
    }

    function->SetName(bn_symbol->GetRawName(),
                      BNRustSimplifyStrToStr(bn_symbol->GetFullName().c_str()));

    if (bn_symbol->GetType() == BNSymbolType::ImportedFunctionSymbol) {
      function->SetType(Function::TYPE_IMPORTED);
      // TODO(cblichmann): Figure out how to access the module that the symbol
      //                   was imported from.
    }
    if (function->GetType(true) == Function::TYPE_NONE ||
        function->GetType(false) == Function::TYPE_STANDARD) {
      if (function->GetBasicBlocks().empty()) {
        function->SetType(Function::TYPE_IMPORTED);
      } else {
        function->SetType(Function::TYPE_STANDARD);
      }
    }
  }

  const auto processing_time = absl::Seconds(timer.elapsed());
  timer.restart();

  LOG(INFO) << "writing...";
  writer
      ->Write(*call_graph, *flow_graph, *instructions, address_references,
              address_space)
      .IgnoreError();

  Operand::EmptyCache();
  Expression::EmptyCache();

  const auto writing_time = absl::Seconds(timer.elapsed());
  LOG(INFO) << absl::StrCat(view->GetFile()->GetOriginalFilename(), ": ",
                            HumanReadableDuration(processing_time),
                            " processing, ",
                            HumanReadableDuration(writing_time), " writing");
}

absl::Status ExportBinaryView(BinaryNinja::BinaryView* view, Writer* writer) {
  const std::string filename = view->GetFile()->GetOriginalFilename();
  LOG(INFO) << filename << ": starting export";
  Timer<> timer;
  EntryPoints entry_points;

  {
    EntryPointManager function_manager(&entry_points, "functions");
    EntryPointManager call_manager(&entry_points, "calls");
    for (const BinaryNinja::Ref<BinaryNinja::Function>& bn_function :
         view->GetAnalysisFunctionList()) {
      BinaryNinja::Ref<BinaryNinja::Symbol> bn_symbol =
          bn_function->GetSymbol();
      switch (bn_symbol->GetType()) {
        case BNSymbolType::FunctionSymbol:
          function_manager.Add(bn_symbol->GetAddress(),
                               EntryPoint::Source::FUNCTION_PROLOGUE);
          break;
        case BNSymbolType::ImportedFunctionSymbol:
          call_manager.Add(bn_symbol->GetAddress(),
                           EntryPoint::Source::CALL_TARGET);
          break;
        default:
          LOG(WARNING) << bn_symbol->GetShortName()
                       << " has unimplemented type " << bn_symbol->GetType();
      }
    }
  }

  Instructions instructions;
  FlowGraph flow_graph;
  CallGraph call_graph;
  AnalyzeFlowBinaryNinja(view, &entry_points, writer, &instructions,
                         &flow_graph, &call_graph);

  LOG(INFO) << absl::StrCat(
      filename, ": exported ", flow_graph.GetFunctions().size(),
      " functions with ", instructions.size(), " instructions in ",
      HumanReadableDuration(timer.elapsed()));
  return absl::OkStatus();
}

absl::Status ExportBinary(const std::string& filename,
                          BinaryNinja::BinaryView* view) {
  NA_ASSIGN_OR_RETURN(std::string sha256_hash, GetInputFileSha256(view));

  BinExport2Writer writer(filename, view->GetFile()->GetOriginalFilename(),
                          sha256_hash, GetArchitectureName(view));
  NA_RETURN_IF_ERROR(ExportBinaryView(view, &writer));
  return absl::OkStatus();
}

void Plugin::Run(BinaryNinja::BinaryView* view) {
  const std::string filename =
      ReplaceFileExtension(view->GetFile()->GetFilename(), ".BinExport");
  if (auto status = ExportBinary(filename, view); !status.ok()) {
    LOG(ERROR) << "Error exporting: " << std::string(status.message());
  }
}

bool Plugin::Init() {
  if (auto status =
          InitLogging(LoggingOptions{}, std::make_unique<BinaryNinjaLogSink>());
      !status.ok()) {
    BinaryNinja::LogError(
        "Error initializing logging, skipping BinExport plugin: %s",
        std::string(status.message()).c_str());
    return false;
  }

  LOG(INFO) << kBinExportName << " " << kBinExportDetailedVersion << ", "
            << kBinExportCopyright;

  BinaryNinja::PluginCommand::Register(
      kBinExportName, kDescription,
      [](BinaryNinja::BinaryView* view) { Plugin::instance()->Run(view); });

  return true;
}

}  // namespace security::binexport

extern "C" BINARYNINJAPLUGIN uint32_t CorePluginABIVersion() {
  // Previously, BinExport worked around Binary Ninja's ABI version handling,
  // to make sure to have it try and load the plugin unconditionally. This
  // was done in order to be able to support both the fast moving "dev"
  // channel as well as the stable one. The intention was for BinExport to
  // use "mostly stable" API functions to work on both and have Binary Ninja
  // ignore the plugin if it used functionality that was not available.
  // However, this proved to be no longer feasible at some point with
  // BinExport leading to crashes.
  return BN_MINIMUM_CORE_ABI_VERSION;
}

extern "C" BINARYNINJAPLUGIN bool CorePluginInit() {
  return security::binexport::Plugin::instance()->Init();
}

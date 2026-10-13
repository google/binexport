// Copyright 2026 Google LLC
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

#include <cstdint>
#include <fstream>
#include <ios>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

// clang-format off
#include "third_party/zynamics/binexport/ida/begin_idasdk.inc"  // NOLINT
#define IDA_KERNEL_PRIVATE_BYTES_ACCESS
#include <bytes.hpp>                                            // NOLINT
#include <ida.hpp>                                              // NOLINT
#include <idp.hpp>                                              // NOLINT
#include <intel.hpp>                                            // NOLINT
#include <kernwin.hpp>                                          // NOLINT
#include <lines.hpp>                                            // NOLINT
#include <loader.hpp>                                           // NOLINT
#include <name.hpp>                                             // NOLINT
#include <segment.hpp>                                          // NOLINT
#include <ua.hpp>                                               // NOLINT
#include <xref.hpp>                                             // NOLINT
#include "third_party/zynamics/binexport/ida/end_idasdk.inc"    // NOLINT
// clang-format on

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "third_party/absl/log/log.h"
#include "third_party/absl/status/status.h"
#include "third_party/absl/status/status_matchers.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/zynamics/binexport/binexport2.pb.h"
#include "third_party/zynamics/binexport/binexport2_writer.h"
#include "third_party/zynamics/binexport/call_graph.h"
#include "third_party/zynamics/binexport/comment.h"
#include "third_party/zynamics/binexport/dump_writer.h"
#include "third_party/zynamics/binexport/entry_point.h"
#include "third_party/zynamics/binexport/expression.h"
#include "third_party/zynamics/binexport/flow_graph.h"
#include "third_party/zynamics/binexport/function.h"
#include "third_party/zynamics/binexport/ida/arm.h"
#include "third_party/zynamics/binexport/ida/dalvik.h"
#include "third_party/zynamics/binexport/ida/digest.h"
#include "third_party/zynamics/binexport/ida/flow_analysis.h"
#include "third_party/zynamics/binexport/ida/generic.h"
#include "third_party/zynamics/binexport/ida/ida_test_util.h"
#include "third_party/zynamics/binexport/ida/log_sink.h"
#include "third_party/zynamics/binexport/ida/metapc.h"
#include "third_party/zynamics/binexport/ida/mips.h"
#include "third_party/zynamics/binexport/ida/names.h"
#include "third_party/zynamics/binexport/ida/ppc.h"
#include "third_party/zynamics/binexport/ida/ui.h"
#include "third_party/zynamics/binexport/ida/util.h"
#include "third_party/zynamics/binexport/instruction.h"
#include "third_party/zynamics/binexport/operand.h"
#include "third_party/zynamics/binexport/util/filesystem.h"
#include "third_party/zynamics/binexport/util/logging.h"
#include "third_party/zynamics/binexport/virtual_memory.h"

namespace security::binexport {
namespace {

using ::absl_testing::IsOk;
using ::absl_testing::IsOkAndHolds;
using ::absl_testing::StatusIs;
using ::testing::ElementsAre;
using ::testing::Eq;
using ::testing::HasSubstr;
using ::testing::IsEmpty;
using ::testing::Optional;
using ::testing::Pair;
using ::testing::SizeIs;

TEST_F(IdaTest, QstringToStringConversion) {
  qstring empty_qstr;
  EXPECT_THAT(ToString(empty_qstr), IsEmpty());
  EXPECT_THAT(ToStringView(empty_qstr), IsEmpty());

  qstring hello("BinExport IDA Test");
  EXPECT_THAT(ToString(hello), Eq("BinExport IDA Test"));
  EXPECT_THAT(ToStringView(hello), Eq("BinExport IDA Test"));
}

TEST_F(IdaTest, DigestSha256AndMd5) {
  db().SetInputFileSha256(std::string(32, '\xaa'));
  db().SetInputFileMd5(std::string(16, '\xbb'));

  EXPECT_THAT(GetInputFileSha256(), IsOkAndHolds(std::string(64, 'a')));
  EXPECT_THAT(GetInputFileMd5(), IsOkAndHolds(std::string(32, 'b')));
}

TEST_F(IdaTest, DigestHexFormattingAndErrors) {
  std::string sha256_raw(32, '\0');
  sha256_raw[0] = '\x01';
  sha256_raw[31] = '\xfe';
  db().SetInputFileSha256(sha256_raw);

  std::string md5_raw(16, '\0');
  md5_raw[0] = '\x12';
  md5_raw[15] = '\x34';
  db().SetInputFileMd5(md5_raw);

  EXPECT_THAT(GetInputFileSha256(),
              IsOkAndHolds(absl::StrCat("01", std::string(60, '0'), "fe")));
  EXPECT_THAT(GetInputFileMd5(),
              IsOkAndHolds(absl::StrCat("12", std::string(28, '0'), "34")));

  db().SetInputFileSha256("");
  db().SetInputFileMd5("");
  EXPECT_THAT(GetInputFileSha256(), StatusIs(absl::StatusCode::kInternal));
  EXPECT_THAT(GetInputFileMd5(), StatusIs(absl::StatusCode::kInternal));
}

TEST_F(IdaTest, LogSinkForwardsToIdaMsg) {
  db().ClearMessages();
  ASSERT_THAT(InitLogging(LoggingOptions().set_alsologtostderr(false),
                          std::make_unique<IdaLogSink>()),
              IsOk());
  LOG(INFO) << "Hello from IdaLogSink";
  ShutdownLogging();

  EXPECT_THAT(db().messages(), HasSubstr("Hello from IdaLogSink"));
}

class DummyAction : public ActionHandler<DummyAction> {
 public:
  static constexpr const char kName[] = "binexport:dummy";
  static constexpr const char kLabel[] = "Dummy Action";
  static constexpr const char kShortCut[] = "";
  static constexpr const char kTooltip[] = "Tooltip";

  int idaapi activate(action_activation_ctx_t* /*ctx*/) override {
    ++activations;
    return 1;
  }

  int activations = 0;
};

TEST_F(IdaTest, UiWaitBoxFileDialogsAndActionHandler) {
  {
    WaitBox wait_box("Initial progress...", WaitBox::kCancellable);
    EXPECT_TRUE(db().wait_box_visible());
    wait_box.ReplaceText("Updated progress...");
    EXPECT_THAT(db().wait_box_messages(),
                ElementsAre("Initial progress...", "Updated progress..."));
    EXPECT_FALSE(WaitBox::IsCancelled());
    db().SetUserCancelled(true);
    EXPECT_TRUE(WaitBox::IsCancelled());
  }
  EXPECT_FALSE(db().wait_box_visible());

  db().ClearAskFileResult();
  EXPECT_THAT(GetSaveFilename("Save", "out.BinExport",
                              {{"BinExport v2", "*.BinExport"}}),
              StatusIs(absl::StatusCode::kCancelled));

  db().SetAskFileResult("/tmp/exported.BinExport");
  EXPECT_THAT(GetSaveFilename("Save", "out.BinExport",
                              {{"BinExport v2", "*.BinExport"}}),
              IsOkAndHolds("/tmp/exported.BinExport"));
  EXPECT_THAT(GetOpenFilename("Open", "in.BinExport",
                              {{"BinExport v2", "*.BinExport"}}),
              IsOkAndHolds("/tmp/exported.BinExport"));

  action_desc_t desc = DummyAction::MakeActionDesc();
  EXPECT_STREQ(desc.name, "binexport:dummy");
  EXPECT_EQ(DummyAction::instance()->PerformActivate(nullptr), 1);
  EXPECT_EQ(DummyAction::instance()->activations, 1);
}

TEST_F(IdaTest, NamesArchitectureAndMetadata) {
  db().SetImageBase(0x400000);
  db().SetInputFilePath("/path/to/sample_program.elf");
  EXPECT_EQ(GetImageBase(), 0x400000);
  EXPECT_THAT(GetModuleName(), Eq("sample_program.elf"));

  db().SetProcessor("metapc", PLFM_386, 64);
  EXPECT_EQ(GetArchitecture(), kX86);
  EXPECT_EQ(GetArchitectureBitness(), 64);
  EXPECT_THAT(GetArchitectureName(), Optional(std::string("x86-64")));

  db().SetProcessor("ARM", PLFM_ARM, 32);
  EXPECT_EQ(GetArchitecture(), kArm);
  EXPECT_THAT(GetArchitectureName(), Optional(std::string("ARM-32")));

  db().SetProcessor("PPC", PLFM_PPC, 64);
  EXPECT_EQ(GetArchitecture(), kPpc);
  EXPECT_THAT(GetArchitectureName(), Optional(std::string("PowerPC-64")));

  db().SetProcessor("mipsl", PLFM_MIPS, 32);
  EXPECT_EQ(GetArchitecture(), kMips);
  EXPECT_THAT(GetArchitectureName(), Optional(std::string("MIPS-32")));

  db().SetProcessor("dalvik", PLFM_DALVIK, 32);
  EXPECT_EQ(GetArchitecture(), kDalvik);
  EXPECT_THAT(GetArchitectureName(), Optional(std::string("Dalvik-32")));

  db().SetProcessor("sparc", PLFM_SPARC, 64);
  EXPECT_EQ(GetArchitecture(), kGeneric);
  EXPECT_THAT(GetArchitectureName(), Optional(std::string("GENERIC-64")));
}

TEST_F(IdaTest, NamesSegmentsBytesStringsAndComments) {
  const std::vector<uint8_t> kCodeBytes = {0x55, 0x48, 0x89, 0xe5, 0xc3};
  const segment_t* code_seg =
      db().AddSegment(0x1000, 0x1010, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC,
                      /*bitness=*/2, kCodeBytes);
  EXPECT_EQ(GetSegmentSize(0x1000), 8);
  EXPECT_EQ(GetPermissions(code_seg),
            AddressSpace::kRead | AddressSpace::kExecute);
  EXPECT_THAT(GetSectionBytes(0x1000),
              ElementsAre(0x55, 0x48, 0x89, 0xe5, 0xc3));

  // Add a string literal in a data segment and reference it from 0x1000.
  const std::vector<uint8_t> kStrBytes = {'h', 'e', 'l', 'l', 'o', 0};
  db().AddSegment(0x2000, 0x2010, SEG_DATA, SEGPERM_READ, /*bitness=*/2);
  db().SetBytes(0x2000, kStrBytes, FF_DATA | FF_STRLIT | FF_IVL);
  db().SetName(0x2000, "aHello", /*user_name=*/true);
  db().AddXref(0x1000, 0x2000, dr_O, /*iscode=*/false);
  EXPECT_THAT(GetStringReference(0x1000), Eq("hello"));

  // Add function, names, and comments at 0x1000.
  db().AddFunction(0x1000, 0x1005, /*flags=*/0, "Function comment",
                   "Repeatable function comment");
  db().SetName(0x1000, "main", /*user_name=*/true);
  db().SetComment(0x1000, "Regular comment", /*repeatable=*/false);
  db().SetComment(0x1000, "Repeatable comment", /*repeatable=*/true);
  db().AddExtraComment(0x1000, E_PREV, "Anterior line");
  db().AddExtraComment(0x1000, E_NEXT, "Posterior line");

  EXPECT_THAT(GetName(0x1000, /*user_names_only=*/true), Eq("main"));
  Name target_name =
      GetName(0x1000, 0x2000, /*operand_num=*/0, /*user_names_only=*/true);
  EXPECT_THAT(target_name.name, Eq("aHello"));
  EXPECT_EQ(target_name.type, Expression::TYPE_GLOBALVARIABLE);

  insn_t insn{};
  insn.ea = 0x1000;
  insn.size = 1;
  Comments comments;
  GetComments(insn, &comments);
  EXPECT_GE(comments.size(), 6);
}

TEST_F(IdaTest, ParseInstructionIdaGeneric) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(64);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("sparc", PLFM_SPARC, 64);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 2);
  insn_t generic_insn{};
  generic_insn.ea = 0x1000;
  generic_insn.size = 4;
  db().AddInstruction(generic_insn, "add", "add %g1, %g2, %g3",
                      {0x86, 0x00, 0x40, 0x02});
  Instruction parsed =
      ParseInstructionIdaGeneric(generic_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("add"));
  EXPECT_EQ(parsed.GetOperandCount(), 1);
}

TEST_F(IdaTest, ParseInstructionIdaMetaPc) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(64);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("metapc", PLFM_386, 64);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 2);
  insn_t x86_insn{};
  x86_insn.ea = 0x1100;
  x86_insn.size = 4;
  x86_insn.ops[0].type = o_reg;
  x86_insn.ops[0].reg = 0;  // rax
  x86_insn.ops[0].dtype = dt_qword;
  x86_insn.ops[0].flags = OF_SHOW;
  x86_insn.ops[1].type = o_imm;
  x86_insn.ops[1].value = 0x2a;
  x86_insn.ops[1].dtype = dt_qword;
  x86_insn.ops[1].flags = OF_SHOW;
  db().AddInstruction(x86_insn, "mov", "mov rax, 2Ah",
                      {0x48, 0xc7, 0xc0, 0x2a});
  Instruction parsed =
      ParseInstructionIdaMetaPc(x86_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("mov"));
  EXPECT_EQ(parsed.GetOperandCount(), 2);
}

TEST_F(IdaTest, ParseInstructionIdaArm) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(32);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("ARM", PLFM_ARM, 32);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 1);
  db().SetRegisterName(0, 4, "R0");
  db().SetRegisterName(1, 4, "R1");
  insn_t arm_insn{};
  arm_insn.ea = 0x1200;
  arm_insn.size = 4;
  arm_insn.ops[0].type = o_reg;
  arm_insn.ops[0].reg = 0;
  arm_insn.ops[0].dtype = dt_dword;
  arm_insn.ops[0].flags = OF_SHOW;
  arm_insn.ops[1].type = o_idpspec0;  // shifted register (LSL)
  arm_insn.ops[1].reg = 1;
  arm_insn.ops[1].specflag2 = 0;  // LSL
  arm_insn.ops[1].value = 2;
  arm_insn.ops[1].dtype = dt_dword;
  arm_insn.ops[1].flags = OF_SHOW;
  db().AddInstruction(arm_insn, "MOV", "MOV R0, R1, LSL#2",
                      {0x01, 0x01, 0xa0, 0xe1});
  Instruction parsed =
      ParseInstructionIdaArm(arm_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("MOV"));
  EXPECT_EQ(parsed.GetOperandCount(), 2);
}

TEST_F(IdaTest, ParseInstructionIdaAArch64) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(64);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("ARM", PLFM_ARM, 64);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 2);
  db().SetRegisterName(0, 8, "X0");
  db().SetRegisterName(1, 8, "X1");
  insn_t aarch64_insn{};
  aarch64_insn.ea = 0x1240;
  aarch64_insn.size = 4;
  aarch64_insn.ops[0].type = o_reg;
  aarch64_insn.ops[0].reg = 0;
  aarch64_insn.ops[0].dtype = dt_qword;
  aarch64_insn.ops[0].flags = OF_SHOW;
  aarch64_insn.ops[1].type = o_reg;
  aarch64_insn.ops[1].reg = 1;
  aarch64_insn.ops[1].dtype = dt_qword;
  aarch64_insn.ops[1].flags = OF_SHOW;
  db().AddInstruction(aarch64_insn, "ADD", "ADD X0, X0, X1",
                      {0x00, 0x00, 0x01, 0x8b});
  Instruction parsed =
      ParseInstructionIdaArm(aarch64_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("ADD"));
  EXPECT_EQ(parsed.GetOperandCount(), 2);
}

TEST_F(IdaTest, ParseInstructionIdaMips) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(32);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("mipsl", PLFM_MIPS, 32);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 1);
  db().SetRegisterName(4, 4, "$a0");
  db().SetRegisterName(29, 4, "$sp");
  insn_t mips_insn{};
  mips_insn.ea = 0x1300;
  mips_insn.size = 4;
  mips_insn.ops[0].type = o_reg;
  mips_insn.ops[0].reg = 4;
  mips_insn.ops[0].dtype = dt_dword;
  mips_insn.ops[0].flags = OF_SHOW;
  mips_insn.ops[1].type = o_displ;
  mips_insn.ops[1].reg = 29;
  mips_insn.ops[1].addr = 0x10;
  mips_insn.ops[1].dtype = dt_dword;
  mips_insn.ops[1].flags = OF_SHOW;
  db().AddInstruction(mips_insn, "lw", "lw $a0, 0x10($sp)",
                      {0x10, 0x00, 0xa4, 0x8f});
  Instruction parsed =
      ParseInstructionIdaMips(mips_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("lw"));
  EXPECT_EQ(parsed.GetOperandCount(), 2);
}

TEST_F(IdaTest, ParseInstructionIdaPpc) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(64);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("PPC", PLFM_PPC, 64);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 2);
  db().SetRegisterName(3, 8, "r3");
  insn_t ppc_insn{};
  ppc_insn.ea = 0x1400;
  ppc_insn.size = 4;
  ppc_insn.ops[0].type = o_reg;
  ppc_insn.ops[0].reg = 3;
  ppc_insn.ops[0].dtype = dt_qword;
  ppc_insn.ops[0].flags = OF_SHOW;
  ppc_insn.ops[1].type = o_idpspec0;  // SPR (8 = lr)
  ppc_insn.ops[1].value = 8;
  ppc_insn.ops[1].dtype = dt_qword;
  ppc_insn.ops[1].flags = OF_SHOW;
  db().AddInstruction(ppc_insn, "mfspr", "mfspr r3, lr",
                      {0x7c, 0x68, 0x02, 0xa6});
  Instruction parsed =
      ParseInstructionIdaPpc(ppc_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("mfspr"));
  EXPECT_EQ(parsed.GetOperandCount(), 2);
}

TEST_F(IdaTest, ParseInstructionIdaDalvik) {
  AddressSpace flags;
  flags.AddMemoryBlock(0x1000, AddressSpace::MemoryBlock(0x1000),
                       AddressSpace::kRead | AddressSpace::kExecute);
  Instruction::SetBitness(32);
  Instruction::SetGetBytesCallback(&GetBytes);
  Instruction::SetMemoryFlags(&flags);
  CallGraph call_graph;
  FlowGraph flow_graph;

  db().SetProcessor("dalvik", PLFM_DALVIK, 32);
  db().AddSegment(0x1000, 0x2000, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC, 1);
  db().SetRegisterName(0, 4, "v0");
  db().SetRegisterName(1, 4, "v1");
  db().AddFunction(0x1500, 0x1510);
  db().AddRegvar(0x1500, "v0", "this_ptr");
  insn_t dalvik_insn{};
  dalvik_insn.ea = 0x1500;
  dalvik_insn.size = 4;
  dalvik_insn.ops[0].type = o_reg;
  dalvik_insn.ops[0].reg = 0;
  dalvik_insn.ops[0].dtype = dt_dword;
  dalvik_insn.ops[0].flags = OF_SHOW;
  dalvik_insn.ops[1].type = o_imm;
  dalvik_insn.ops[1].value = 1234;
  dalvik_insn.ops[1].dtype = dt_dword;
  dalvik_insn.ops[1].flags = OF_SHOW;
  db().AddInstruction(dalvik_insn, "const", "const v0, 1234",
                      {0x14, 0x00, 0xd2, 0x04});
  Instruction parsed =
      ParseInstructionIdaDalvik(dalvik_insn, &call_graph, &flow_graph);
  EXPECT_FALSE(parsed.HasFlag(FLAG_INVALID));
  EXPECT_THAT(parsed.GetMnemonic(), Eq("const"));
  EXPECT_EQ(parsed.GetOperandCount(), 2);

  Operand::EmptyCache();
  Expression::EmptyCache();
}

TEST_F(IdaTest, AnalyzeFlowIdaAndPluginExportEndToEnd) {
  db().SetProcessor("metapc", PLFM_386, 64);
  db().SetInputFilePath("/tmp/test_module.elf");
  db().SetIdbPath("/tmp/test_module.i64");
  db().AddSegment(0x1000, 0x1020, SEG_CODE, SEGPERM_READ | SEGPERM_EXEC,
                  /*bitness=*/2);
  db().AddSegment(0x2000, 0x2010, SEG_XTRN, SEGPERM_READ, /*bitness=*/2);

  // Imported function at 0x2000 from libc.so.6.
  db().SetName(0x2000, "puts", /*user_name=*/true);
  db().AddImportModule("libc.so.6", {{0x2000, "puts"}});

  ModuleMap modules = InitModuleMap();
  EXPECT_THAT(modules, ElementsAre(Pair(0x2000, "libc.so.6")));

  // Function at 0x1000..0x100b:
  //   0x1000: push rbp (1 byte)
  //   0x1001: mov rbp, rsp (3 bytes)
  //   0x1004: call puts (5 bytes, calls 0x2000)
  //   0x1009: pop rbp (1 byte)
  //   0x100a: retn (1 byte, no flow to next)
  db().AddFunction(0x1000, 0x100b, /*flags=*/0, "Entry function");
  db().SetName(0x1000, "main", /*user_name=*/true);

  insn_t insn_push{};
  insn_push.ea = 0x1000;
  insn_push.size = 1;
  insn_push.ops[0].type = o_reg;
  insn_push.ops[0].reg = 5;  // rbp
  insn_push.ops[0].dtype = dt_qword;
  insn_push.ops[0].flags = OF_SHOW;
  db().AddInstruction(insn_push, "push", "push rbp", {0x55});

  insn_t insn_mov{};
  insn_mov.ea = 0x1001;
  insn_mov.size = 3;
  insn_mov.ops[0].type = o_reg;
  insn_mov.ops[0].reg = 5;  // rbp
  insn_mov.ops[0].dtype = dt_qword;
  insn_mov.ops[0].flags = OF_SHOW;
  insn_mov.ops[1].type = o_reg;
  insn_mov.ops[1].reg = 4;  // rsp
  insn_mov.ops[1].dtype = dt_qword;
  insn_mov.ops[1].flags = OF_SHOW;
  db().AddInstruction(insn_mov, "mov", "mov rbp, rsp", {0x48, 0x89, 0xe5});

  insn_t insn_call{};
  insn_call.ea = 0x1004;
  insn_call.size = 5;
  insn_call.ops[0].type = o_near;
  insn_call.ops[0].addr = 0x2000;
  insn_call.ops[0].dtype = dt_code;
  insn_call.ops[0].flags = OF_SHOW;
  db().AddInstruction(insn_call, "call", "call puts",
                      {0xe8, 0xf7, 0x0f, 0x00, 0x00}, /*flow_to_next=*/true,
                      /*is_call=*/true);
  db().AddXref(0x1004, 0x2000, fl_CN, /*iscode=*/true);

  insn_t insn_pop{};
  insn_pop.ea = 0x1009;
  insn_pop.size = 1;
  insn_pop.ops[0].type = o_reg;
  insn_pop.ops[0].reg = 5;  // rbp
  insn_pop.ops[0].dtype = dt_qword;
  insn_pop.ops[0].flags = OF_SHOW;
  db().AddInstruction(insn_pop, "pop", "pop rbp", {0x5d});

  insn_t insn_ret{};
  insn_ret.ea = 0x100a;
  insn_ret.size = 1;
  db().AddInstruction(insn_ret, "retn", "retn", {0xc3},
                      /*flow_to_next=*/false);

  // Test AnalyzeFlowIda directly with DumpWriter.
  {
    EntryPoints entry_points;
    {
      EntryPointManager adder(&entry_points, "test");
      adder.Add(0x1000, EntryPoint::Source::FUNCTION_PROLOGUE);
      adder.Add(0x2000, EntryPoint::Source::CALL_TARGET);
    }
    std::ostringstream dump_stream;
    DumpWriter dump_writer(dump_stream);
    Instructions instructions;
    FlowGraph flow_graph;
    CallGraph call_graph;
    ASSERT_THAT(AnalyzeFlowIda(&entry_points, modules, &dump_writer,
                               &instructions, &flow_graph, &call_graph,
                               FlowGraph::NoReturnHeuristic::kNone),
                IsOk());
    EXPECT_THAT(instructions, SizeIs(5));
    EXPECT_THAT(flow_graph.GetFunctions(), SizeIs(2));
    EXPECT_THAT(dump_stream.str(), HasSubstr("main"));
    EXPECT_THAT(dump_stream.str(), HasSubstr("puts"));
  }

  // Test Plugin registration, IDC functions, and BinExport2 protobuf export.
  ASSERT_THAT(GetOrCreateTempDirectory("BinExportIdaTest"), IsOk());
  std::string temp_dir = *GetOrCreateTempDirectory("BinExportIdaTest");
  std::string out_binexport = JoinPath(temp_dir, "test_module.BinExport");
  std::string out_txt = JoinPath(temp_dir, "test_module.txt");
  std::string out_stats = JoinPath(temp_dir, "test_module.statistics");

  EXPECT_EQ(PLUGIN.version, IDP_INTERFACE_VERSION);
  std::unique_ptr<plugmod_t> plugmod(PLUGIN.init());
  ASSERT_NE(plugmod, nullptr);

  EXPECT_EQ(db().InvokeIdcFunction("BinExportBinary", out_binexport), eOk);
  EXPECT_EQ(db().InvokeIdcFunction("BinExportText", out_txt), eOk);
  EXPECT_EQ(db().InvokeIdcFunction("BinExportStatistics", out_stats), eOk);

  // Verify the written BinExport2 proto file.
  BinExport2 proto;
  {
    std::ifstream in(out_binexport, std::ios::binary);
    ASSERT_TRUE(in.is_open());
    ASSERT_TRUE(proto.ParseFromIstream(&in));
  }
  EXPECT_THAT(proto.meta_information().executable_name(),
              Eq("test_module.elf"));
  EXPECT_THAT(proto.meta_information().architecture_name(), Eq("x86-64"));
  EXPECT_EQ(proto.instruction_size(), 5);
  EXPECT_EQ(proto.call_graph().vertex_size(), 2);

  // Also test plugmod->run(...) with argument.
  db().SetPluginOption("BinExportModule", out_binexport);
  EXPECT_TRUE(plugmod->run(/*argument=*/2));
}

}  // namespace
}  // namespace security::binexport

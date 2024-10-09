// Copyright 2011-2024 Google LLC
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

#include "third_party/zynamics/binexport/ida/names.h"

#include <algorithm>
#include <cinttypes>
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <string>
#include <tuple>
#include <vector>

// clang-format off
#include "third_party/zynamics/binexport/ida/begin_idasdk.inc"  // NOLINT
#include <idp.hpp>                                              // NOLINT
#include <allins.hpp>                                           // NOLINT
#include <frame.hpp>                                            // NOLINT
#include <ida.hpp>                                              // NOLINT
#include <lines.hpp>                                            // NOLINT
#include <name.hpp>                                             // NOLINT
#include <nalt.hpp>                                             // NOLINT
#include <netnode.hpp>                                          // NOLINT
#include <segment.hpp>                                          // NOLINT
#include <typeinf.hpp>                                          // NOLINT
#include <ua.hpp>                                               // NOLINT
#if IDP_INTERFACE_VERSION >= 900
#define ph PH
#else
#include <enum.hpp>                                             // NOLINT
#include <struct.hpp>                                           // NOLINT
#endif
#include "third_party/zynamics/binexport/ida/end_idasdk.inc"    // NOLINT
// clang-format on

#include "third_party/absl/container/btree_map.h"
#include "third_party/absl/log/log.h"
#include "third_party/absl/strings/ascii.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/time/time.h"
#include "third_party/zynamics/binexport/address_references.h"
#include "third_party/zynamics/binexport/base_types.h"
#include "third_party/zynamics/binexport/call_graph.h"
#include "third_party/zynamics/binexport/flow_graph.h"
#include "third_party/zynamics/binexport/ida/util.h"
#include "third_party/zynamics/binexport/util/filesystem.h"
#include "third_party/zynamics/binexport/util/format.h"
#include "third_party/zynamics/binexport/virtual_memory.h"

namespace security::binexport {

Address GetImageBase() {
  // @bug: IDA's get_imagebase is buggy for ELF and returns 0 all the time.
  return get_imagebase();
}

Architecture GetArchitecture() {
  qstring procname = inf_get_procname();
  auto architecture = ToStringView(procname);
  if (architecture == "metapc") {
    return kX86;
  }
  if (architecture == "ARM") {
    return kArm;
  }
  if (architecture == "PPC") {
    return kPpc;
  }
  if (architecture == "mipsb" || architecture == "mipsl" ||
      architecture == "mipsr" || architecture == "mipsrl" ||
      architecture == "r5900b" || architecture == "r5900l") {
    return kMips;
  }
  if (architecture == "dalvik") {
    return kDalvik;
  }
  return kGeneric;
}

int GetArchitectureBitness() { return inf_get_app_bitness(); }

absl::optional<std::string> GetArchitectureName() {
  std::string architecture;
  switch (GetArchitecture()) {
    case kX86:
      architecture = "x86";
      break;
    case kArm:
      architecture = "ARM";
      break;
    case kPpc:
      architecture = "PowerPC";
      break;
    case kMips:
      architecture = "MIPS";
      break;
    case kDalvik:
      architecture = "Dalvik";
      break;
    case kGeneric:
      architecture = "GENERIC";
      break;
    default:
      return {};
  }

  switch (size_t address_size = GetArchitectureBitness(); address_size) {
    case 64:
      absl::StrAppend(&architecture, "-64");
      break;
    case 32:
      absl::StrAppend(&architecture, "-32");
      break;
    case 16:
      absl::StrAppend(&architecture, "-16");
      break;
    default:
      LOG_FIRST_N(WARNING, 1) << "Unexpected address size " << address_size
                              << " for architecture \"" << architecture
                              << "\", export may be incorrect";
      LOG_IF_FIRST_N(WARNING, architecture != "GENERIC", 1)
          << "If you're not using a custom processor module, you may want to "
             "file a bug";
      break;
  }
  return architecture;
}

std::string GetModuleName() {
  std::string path(QMAXPATH, '\0');
  if (get_input_file_path(&path[0], QMAXPATH) == 0) {
#if IDP_INTERFACE_VERSION >= 900
    netnode_valstr(0, &path[0], QMAXPATH);
#else
    // b/186782665: IDA 7.5 and lower use the root_node instead.
    root_node.valstr(&path[0], QMAXPATH);
#endif
  }
  path.resize(std::strlen(path.data()));
  return Basename(path);
}

int GetOriginalIdaLine(const Address address, std::string* line) {
  qstring ida_line;
  generate_disasm_line(&ida_line, address, 0);
  int result = tag_remove(&ida_line);
  *line = ToString(ida_line);
  return result;
}

std::string GetMnemonic(const Address address) {
  qstring ida_mnemonic;
  print_insn_mnem(&ida_mnemonic, address);
  return ToString(ida_mnemonic);
}

// Renders hex values as shown in IDA.
std::string IdaHexify(int value) {
  if (value < 10) {
    return absl::StrCat(value);
  }
  return absl::StrCat(absl::AsciiStrToUpper(absl::StrCat(absl::Hex(value))),
                      "h");
}

std::string GetSizePrefix(size_t size_in_bytes) {
  if (size_in_bytes != 0) {
    return absl::StrCat("b", size_in_bytes);
  }
  return "";
}

size_t GetOperandByteSize(const insn_t& instruction, const op_t& operand) {
  switch (operand.dtype) {
    case dt_byte:
      return 1;  // 8 bit
    case dt_code:
    case dt_word:
    case dt_half:  // ARM-only (b/70541404)
      return 2;    // 16 bit
    case dt_dword:
    case dt_float:
      return 4;  // 32 bit
    case dt_fword:
      return 6;  // 48 bit
    case dt_double:
    case dt_qword:
      return 8;        // 64 bit
    case dt_packreal:  // 96 bit
      return 12;
    case dt_byte16:
      return 16;  // 128 bit
    case dt_byte32:
      return 32;  // 256 bit
    case dt_byte64:
      return 64;   // 512 bit
    case dt_ldbl:  // Variable size double
      return ph.sizeof_ldbl();
    case dt_tbyte:  // Variable size
      return ph.tbyte_size;
    case dt_void:     // Operand invalid/undefined
    case dt_bitfild:  // Unsupported
    case dt_string:   // Unsupported
    case dt_unicode:  // Unsupported
    default:
      return 0;  // Indicate to not create byte size prefix
  }
}

size_t GetSegmentSize(const Address address) {
  const segment_t* segment = getseg(address);
  // IDA constants: 0 = 16, 1 = 32, 2 = 64
  return (16 << segment->bitness) >> 3;
}

bool IsCodeSegment(const Address address) {
  if (const segment_t* segment = getseg(address)) {
    return segment->type != SEG_XTRN && segment->type != SEG_DATA;
  }
  return false;
}

std::string GetStringReference(ea_t address) {
  xrefblk_t xrefs;
  if (xrefs.first_from(address, XREF_DATA) == 0) {
    return "";
  }

  while (!xrefs.iscode) {
    if ((xrefs.type == dr_O) && (is_strlit(get_flags(xrefs.to)))) {
      size_t length = get_max_strlit_length(xrefs.to, STRTYPE_C);
      if (length == 2) {
        length = get_max_strlit_length(xrefs.to, STRTYPE_C_16);
      }

      std::string value(length, ' ');
      for (size_t i = 0; i < length; ++i) {
        value[i] = get_byte(xrefs.to + i);
      }
      return value;
    }

    if (xrefs.next_from() == 0) {
      break;
    }
  }
  return "";
}

std::string GetRegisterName(size_t index, size_t bit_width) {
  qstring ida_reg_name;
  if (get_reg_name(&ida_reg_name, index, bit_width) != -1) {
    return ToString(ida_reg_name);
  }
  return absl::StrCat("<reg", index, "-", bit_width);
}

bool IsStackVariable(Address address, uint8_t operand_num) {
  flags_t flags = get_flags(static_cast<ea_t>(address));
  return is_stkvar(flags, operand_num);
}

bool IsStructVariable(Address address, uint8_t operand_num) {
  flags_t flags = get_flags(static_cast<ea_t>(address));
  return (operand_num == 0 && is_stroff0(flags)) ||
         (operand_num == 1 && is_stroff1(flags));
}

std::string GetVariableName(const insn_t& instruction, uint8_t operand_num) {
  if (!IsStackVariable(instruction.ea, operand_num)) {
    return "";
  }

#if IDP_INTERFACE_VERSION >= 900
  func_t* function = get_func(instruction.ea);
  if (!function) {
    return "";
  }

  tinfo_t frame;
  if (!get_func_frame(&frame, function)) {
    return "";
  }

  ea_t offset = calc_stkvar_struc_offset(function, instruction, operand_num);

  udt_type_data_t udt_data;
  if (!frame.get_udt_details(&udt_data)) {
    return "";
  }
  // Find the base member (variable or structure)
  const udm_t* base_member = nullptr;
  for (const auto& member : udt_data) {
    if (member.offset / 8 <= offset &&
        (member.offset / 8 + member.size / 8) > offset) {
      base_member = &member;
      break;
    }
  }

  if (base_member) {
    std::string result = ToString(base_member->name);

    if (ea_t member_offset = offset - (base_member->offset / 8);
        member_offset > 0) {
      // Handle nested structures
      if (base_member->type.is_struct()) {
        udt_type_data_t nested_udt_data;
        if (base_member->type.get_udt_details(&nested_udt_data)) {
          for (const auto& nested_member : nested_udt_data) {
            if (nested_member.offset / 8 == member_offset) {
              return absl::StrCat(result, ".", ToString(nested_member.name));
            }
          }
        }
      }

      // If it's not a nested structure or we couldn't find the exact member,
      // append the offset
      absl::StrAppend(&result, "+", IdaHexify(member_offset));
    }

    return result;
  }

  // If we couldn't find a matching member, return a generic name with the
  // offset
  return absl::StrCat("var_", IdaHexify(offset));
#else
  const member_t* stack_variable =
      get_stkvar(0, instruction, instruction.ops[operand_num],
                 instruction.ops[operand_num].addr);
  if (!stack_variable) {
    return "";
  }

  std::string name = ToString(get_struc_name(stack_variable->id));

  // The parsing is in here because IDA puts in some strange segment prefix or
  // something like that.
  name = name.substr(name.find('.', 4) + 1);
  if (name[0] != ' ') {
    func_t* function = get_func(instruction.ea);
    if (!function) {
      return name;
    }

    const ea_t offset =
        calc_stkvar_struc_offset(function, instruction, operand_num);
    if (offset == BADADDR) {
      return name;
    }

    std::string result;

    // The following comment is from the Python exporter:
    // 4 is the value of the stack pointer register SP/ESP in x86. This should
    // not break other archs but needs to be here or otherwise would need to
    // override the whole method in metapc...
    tid_t id = 0;
    adiff_t disp = 0;
    adiff_t delta = 0;
    if (get_struct_operand(&disp, &delta, &id, instruction.ea, operand_num) &&
        instruction.ops[operand_num].reg == 4) {
      int delta = get_spd(function, instruction.ea);
      delta = -delta - function->frregs;
      if (delta) {
        absl::StrAppend(&result, IdaHexify(delta), "+");
      }

      // TODO(soerenme): This must be recursive for nested structs.
      if (const struc_t* structure = get_struc(id)) {
        if (const member_t* member = get_member(structure, disp)) {
          std::string member_name = ToString(get_member_name(member->id));
          absl::StrAppend(&result, name, ".", member_name, disp);
          if (delta) {
            absl::StrAppend(&result, delta > 0 ? "+" : "", delta);
          }
          return result;
        }
      }
    } else {
      return name;
    }

    absl::StrAppend(&result, name);
    const int var_delta = offset - stack_variable->soff;
    if (var_delta) {
      absl::StrAppend(&result, "+0x", absl::Hex(var_delta));
    }
    return result;
  }
  return "";
#endif
}

std::string GetGlobalStructureName(Address address, Address instance_address,
                                   uint8_t operand_num) {
  std::string instance_name;

  tid_t id[MAXSTRUCPATH];
  memset(id, 0, sizeof(id));
  adiff_t disp = 0;
  adiff_t delta = 0;

  int num_structs = get_struct_operand(&disp, &delta, id, address, operand_num);
#if IDP_INTERFACE_VERSION >= 900
  if (num_structs > 0) {
    tinfo_t tif;
    if (get_tinfo(&tif, id[0])) {
      qstring ida_name;
      if (get_name(&ida_name, instance_address - disp) ||
          tif.get_type_name(&ida_name)) {
        instance_name = ToString(ida_name);
      }

      udt_type_data_t udt_data;
      if (tif.get_udt_details(&udt_data)) {
        for (const udm_t& udm : udt_data) {
          if (udm.offset < disp) {
            continue;
          }
          absl::StrAppend(&instance_name, ".", ToString(udm.name));
          disp -= udm.size;

          if (!udm.type.is_struct()) {
            break;
          }
          tif = udm.type;
          if (!tif.get_udt_details(&udt_data)) {
            break;
          }
        }
      }
    }
  }
#else
  if (num_structs > 0) {
    // Special case for the first index - this may be an instance name instead
    // of a type name.
    const struc_t* structure = get_struc(id[0]);
    if (structure) {
      // First try to get a global variable instance name.
      // Second, fall back to just the structure type name.
      if (qstring ida_name; get_name(&ida_name, instance_address - disp) ||
                            get_struc_name(&ida_name, id[0])) {
        instance_name = ToString(ida_name);
      }
    }

    // TODO(cblichmann): Array members won't be resolved properly. disp will
    //                   point into the array, making get_member calls fail.
    for (const member_t* member = get_member(structure, disp);
         member != nullptr;
         member = get_member(structure, disp -= member->soff)) {
      absl::StrAppend(&instance_name, ".",
                      ToString(get_member_name(member->id)));
      structure = get_sptr(member);
    }
  }
#endif
  return instance_name;
}

std::string GetName(Address address, bool user_names_only) {
  if (!user_names_only ||
      has_user_name(get_flags(static_cast<ea_t>(address)))) {
    return ToString(get_name(static_cast<ea_t>(address)));
  }
  return "";
}

std::string GetDemangledName(Address address) {
  if (has_user_name(get_flags(static_cast<ea_t>(address)))) {
    return ToString(get_short_name(static_cast<ea_t>(address)));
  }
  return "";
}

Name GetName(Address /* address */, Address immediate,
             uint8_t /* operand_num */, bool user_names_only) {
  Expression::Type type = Expression::TYPE_INVALID;
  const std::string name = GetName(immediate, user_names_only);
  if (!name.empty()) {
    xrefblk_t xref;
    for (bool ok = xref.first_to(immediate, XREF_ALL);
         ok && type == Expression::TYPE_INVALID; ok = xref.next_to()) {
      if (!xref.iscode) {
        type = Expression::TYPE_GLOBALVARIABLE;
      }
      switch (xref.type) {
        case fl_JN:
        case fl_JF:
          type = Expression::TYPE_JUMPLABEL;
          break;
        case fl_CN:
        case fl_CF:
          type = Expression::TYPE_FUNCTION;
          break;
      }
    }
  }
  return Name(name, type);
}

std::string GetBytes(const Instruction& instruction) {
  std::string bytes(instruction.GetSize(), '\0');
  get_bytes(&(bytes[0]), instruction.GetSize(),
            static_cast<ea_t>(instruction.GetAddress()));
  return bytes;
}

// Returns raw bytes that are contained within a segment. This will copy bytes
// from the start of the segment up until the first undefined location or the
// end of the segment, if all locations are valid.
std::vector<Byte> GetSectionBytes(ea_t segment_start_address) {
  std::vector<Byte> bytes;
  const segment_t* ida_segment = getseg(segment_start_address);
  if (ida_segment && is_loaded(ida_segment->start_ea)) {
    const ea_t undefined_bytes = next_that(
        ida_segment->start_ea, ida_segment->end_ea,
        [](auto flags, void* /* ud */) { return !has_value(flags); },
        nullptr /* user data */);
    bytes.resize(
        (undefined_bytes == BADADDR ? ida_segment->end_ea : undefined_bytes) -
        ida_segment->start_ea);
    get_bytes(&bytes[0], bytes.size(), ida_segment->start_ea);
  }
  return bytes;
}

int GetPermissions(const segment_t* ida_segment) {
  int flags = 0;
  flags |= ida_segment->perm & SEGPERM_READ ? AddressSpace::kRead : 0;
  flags |= ida_segment->perm & SEGPERM_WRITE ? AddressSpace::kWrite : 0;
  flags |= ida_segment->perm & SEGPERM_EXEC ? AddressSpace::kExecute : 0;
  return flags;
}

void GetRegularComments(Address address, Comments* comments) {
  qstring ida_comment;
  if (get_cmt(&ida_comment, address, /*rptble=*/false) > 0) {
    // TODO(cblichmann): Benchmark against caching an absl::string_view.
    comments->emplace_back(address, UA_MAXOP + 1,
                           CallGraph::CacheString(std::string(
                               ida_comment.c_str(), ida_comment.length())),
                           Comment::REGULAR, false);
  }
  if (get_cmt(&ida_comment, address, /*rptble=*/true) > 0) {
    comments->emplace_back(address, UA_MAXOP + 2,
                           CallGraph::CacheString(std::string(
                               ida_comment.c_str(), ida_comment.length())),
                           Comment::REGULAR, true);
  }
}

void GetEnumComments(Address address,
                     Comments* comments) {  // @bug: there is an get_enum_cmt
                                            // function in IDA as well!
#if IDP_INTERFACE_VERSION >= 900
  if (is_enum0(get_flags(address)) || is_enum1(get_flags(address))) {
    tinfo_t tif;
    if (get_tinfo(&tif, address) && tif.is_enum()) {
      qstring enum_name;
      if (tif.get_type_name(&enum_name)) {
        comments->emplace_back(address, is_enum0(get_flags(address)) ? 0 : 1,
                               CallGraph::CacheString(ToString(enum_name)),
                               Comment::ENUM, /*repeatable=*/false);
      }
    }
  }
#else
  uint8_t serial;
  if (is_enum0(get_flags(address))) {
    int id = get_enum_id(&serial, address, 0);
    if (id != BADNODE) {
      comments->emplace_back(
          address, 0, CallGraph::CacheString(ToString(get_enum_name(id))),
          Comment::ENUM, /*repeatable=*/false);
    }
  }
  if (is_enum1(get_flags(address))) {
    int id = get_enum_id(&serial, address, 1);
    if (id != BADNODE) {
      comments->emplace_back(
          address, 1, CallGraph::CacheString(ToString(get_enum_name(id))),
          Comment::ENUM, /*repeatable=*/false);
    }
  }
#endif
}

bool GetLineComment(Address address, int n, std::string* output) {
  qstring ida_comment;
  ssize_t result = get_extra_cmt(&ida_comment, address, n);
  *output = ToString(ida_comment);
  return result >= 0;
}

void GetLineComments(Address address, Comments* comments) {
  std::string buffer;

  // Anterior comments
  std::string comment;
  for (int i = 0; GetLineComment(address, E_PREV + i, &buffer); ++i) {
    absl::StrAppend(&comment, buffer, "\n");
  }
  if (!comment.empty()) {
    comment = comment.substr(0, comment.size() - 1);
    comments->emplace_back(address, UA_MAXOP + 3,
                           CallGraph::CacheString(comment), Comment::ANTERIOR,
                           /*repeatable=*/false);
  }
  // Posterior comments
  comment.clear();
  for (int i = 0; GetLineComment(address, E_NEXT + i, &buffer); ++i) {
    absl::StrAppend(&comment, buffer, "\n");
  }
  if (!comment.empty()) {
    comment = comment.substr(0, comment.size() - 1);
    comments->emplace_back(address, UA_MAXOP + 4,
                           CallGraph::CacheString(comment), Comment::POSTERIOR,
                           /*repeatable=*/false);
  }
}

void GetFunctionComments(Address address, Comments* comments) {
  func_t* function = get_func(address);
  if (!function) {
    return;
  }
  if (function->start_ea == address) {
    qstring ida_comment;
    if (get_func_cmt(&ida_comment, function, /*repeatable=*/false) > 0) {
      comments->emplace_back(address, UA_MAXOP + 5,
                             CallGraph::CacheString(ToString(ida_comment)),
                             Comment::FUNCTION, /*repeatable=*/false);
    }
    if (get_func_cmt(&ida_comment, function, /*repeatable=*/true) > 0) {
      comments->emplace_back(address, UA_MAXOP + 6,
                             CallGraph::CacheString(ToString(ida_comment)),
                             Comment::FUNCTION, /*repeatable=*/true);
    }
  }
}

void GetLocationNames(Address address, Comments* comments) {
  func_t* function = get_func(address);
  if (function && function->start_ea == address &&
      has_user_name(get_flags(address))) {
    // TODO(cblichmann): get_short_name -> use demangled names for display,
    //                   but port mangled names.
    comments->emplace_back(address, UA_MAXOP + 7,
                           CallGraph::CacheString(ToString(get_name(address))),
                           Comment::LOCATION, /*repeatable=*/false);
  }
}

void GetGlobalReferences(Address address, Comments* comments) {
  size_t count = 0;
  xrefblk_t xb;
  for (bool ok = xb.first_from(address, XREF_DATA); ok; ok = xb.next_from(),
            ++count) {  // xb.to - contains the referenced address
    qstring ida_name(get_name(xb.to));
    if (ida_name.empty() || has_dummy_name(get_flags(address))) {
      continue;
    }

    // This stores the instance pointer
    comments->emplace_back(address, UA_MAXOP + 1024 + count,
                           CallGraph::CacheString(ToString(ida_name)),
                           Comment::GLOBAL_REFERENCE, false);
  }
}

struct FunctionCache {
  explicit FunctionCache(func_t* function) : function(function) {
    if (!function) {
      return;
    }
#if IDP_INTERFACE_VERSION >= 900
    tinfo_t frame_tif;
    if (!get_func_frame(&frame_tif, function)) {
      return;
    }

    udt_type_data_t udt_data;
    if (!frame_tif.get_udt_details(&udt_data)) {
      return;
    }

    // IDA sometimes returns excessively large offsets (billions) we must
    // prevent looping forever in those cases
    size_t last_success = 0;
    const size_t max_offset =
        std::min(frame_tif.get_size(),
                 size_t(64 * 1024 /* Max stack size for analysis */));
    for (const udm_t& member : udt_data) {
      if (member.offset >= max_offset || last_success - member.offset >= 1024) {
        break;
      }
      if (member.is_special_member()) {
        continue;
      }

      if (!member.name.empty()) {
        local_vars[member.offset] = ToString(member.name);
        last_success = member.offset + member.size;
      }
    }
#else
    struc_t* frame = get_frame(function);
    if (!frame) {
      return;
    }

    // IDA sometimes returns excessively large offsets (billions) we must
    // prevent looping forever in those cases
    size_t last_success = 0;
    const size_t max_offset = std::min(
        static_cast<size_t>(get_max_offset(frame)),
        static_cast<size_t>(64 * 1024 /* Max stack size for analysis */));
    for (size_t i = 0; i < max_offset && last_success - i < 1024;) {
      const member_t* member = get_member(frame, i);
      if (!member || is_special_member(member->id)) {
        ++i;
        continue;
      }

      const ea_t offset = member->soff;
      qstring ida_name(get_member_name(member->id));
      if (!ida_name.empty()) {
        i += std::max(static_cast<asize_t>(1), get_member_size(member));
        last_success = i;
        continue;
      }

      local_vars[offset] = ToString(ida_name);
      i += std::max(static_cast<asize_t>(1), get_member_size(member));
      last_success = i;
    }
#endif
  }

  func_t* function;
  absl::btree_map<ea_t, std::string> local_vars;
};

void GetLocalReferences(const insn_t& instruction, Comments* comments) {
  static FunctionCache cache(nullptr);

  func_t* function = get_func(instruction.ea);
  if (!function) {
    return;
  }

  if (cache.function != function) {
    cache = FunctionCache(function);
  }

  for (size_t operand_num = 0; operand_num < UA_MAXOP; ++operand_num) {
    const ea_t offset =
        calc_stkvar_struc_offset(function, instruction, operand_num);
    if (offset == BADADDR) {
      continue;
    }

    // one of the operands references a local variable
    if (cache.local_vars.find(offset) != cache.local_vars.end()) {
      comments->emplace_back(instruction.ea, UA_MAXOP + 2048 + operand_num,
                             CallGraph::CacheString(cache.local_vars[offset]),
                             Comment::LOCAL_REFERENCE, false);
    }
  }
}

void GetComments(const insn_t& instruction, Comments* comments) {
  GetRegularComments(instruction.ea, comments);
  GetEnumComments(instruction.ea, comments);
  GetLineComments(instruction.ea, comments);
  GetFunctionComments(instruction.ea, comments);
  GetLocationNames(instruction.ea, comments);
  GetGlobalReferences(instruction.ea, comments);
  GetLocalReferences(instruction, comments);
}

}  // namespace security::binexport

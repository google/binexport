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

#include "third_party/zynamics/binexport/ida/ida_test_util.h"

#include <algorithm>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

// clang-format off
#include "third_party/zynamics/binexport/ida/begin_idasdk.inc"  // NOLINT
#define IDA_KERNEL_PRIVATE_BYTES_ACCESS
#include <bytes.hpp>                                            // NOLINT
#include <expr.hpp>                                             // NOLINT
#include <frame.hpp>                                            // NOLINT
#include <funcs.hpp>                                            // NOLINT
#include <ida.hpp>                                              // NOLINT
#include <idp.hpp>                                              // NOLINT
#include <kernwin.hpp>                                          // NOLINT
#include <lines.hpp>                                            // NOLINT
#include <loader.hpp>                                           // NOLINT
#include <nalt.hpp>                                             // NOLINT
#include <name.hpp>                                             // NOLINT
#include <netnode.hpp>                                          // NOLINT
#include <pro.h>                                                // NOLINT
#include <segment.hpp>                                          // NOLINT
#include <typeinf.hpp>                                          // NOLINT
#include <ua.hpp>                                               // NOLINT
#include <xref.hpp>                                             // NOLINT
#include "third_party/zynamics/binexport/ida/end_idasdk.inc"    // NOLINT
// clang-format on

#include "third_party/absl/base/no_destructor.h"
#include "third_party/absl/container/flat_hash_map.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/absl/types/span.h"
#include "third_party/zynamics/binexport/util/logging.h"

namespace security::binexport {

IdaTestDatabase::IdaTestDatabase() { Reset(); }

IdaTestDatabase::~IdaTestDatabase() = default;

IdaTestDatabase* IdaTestDatabase::instance() {
  static absl::NoDestructor<IdaTestDatabase> db;
  return db.get();
}

void IdaTestDatabase::Reset() {
  DisableLogInitForTesting();
  procname_ = "metapc";
  bitness_ = 64;
  imagebase_ = 0x1000;
  input_file_path_ = "/tmp/test_binary";
  idb_path_ = "/tmp/test_binary.i64";
  sha256_bytes_.assign(32, '\x11');
  md5_bytes_.assign(16, '\x22');

  std::memset(&ph_, 0, sizeof(ph_));
  ph_.version = IDP_INTERFACE_VERSION;
  ph_.id = PLFM_386;
  ph_.cnbits = 8;
  ph_.dnbits = 8;
  ph_.tbyte_size = 10;

  std::memset(&ash_, 0, sizeof(ash_));
  ash_.name = "Generic Assembler";

  segments_.clear();
  memory_.clear();
  flags_.clear();
  instructions_.clear();
  names_.clear();
  xrefs_from_.clear();
  xrefs_to_.clear();
  functions_.clear();
  func_comments_.clear();
  func_repeatable_comments_.clear();
  comments_.clear();
  repeatable_comments_.clear();
  extra_comments_.clear();
  reg_names_.clear();
  regvar_strings_.clear();
  regvars_.clear();
  import_modules_.clear();
  netnode_valstrs_.clear();
  netnode_supvals_.clear();
  plugin_options_.clear();
  idc_funcs_.clear();
  hooks_.clear();

  database_flags_ = 0;
  user_cancelled_ = false;
  wait_box_visible_ = false;
  wait_box_messages_.clear();
  messages_.clear();
  ask_file_result_.clear();

  // Default register names for common tests.
  SetRegisterName(0, 1, "al");
  SetRegisterName(0, 2, "ax");
  SetRegisterName(0, 4, "eax");
  SetRegisterName(0, 8, "rax");
  SetRegisterName(1, 1, "cl");
  SetRegisterName(1, 2, "cx");
  SetRegisterName(1, 4, "ecx");
  SetRegisterName(1, 8, "rcx");
  SetRegisterName(2, 1, "dl");
  SetRegisterName(2, 2, "dx");
  SetRegisterName(2, 4, "edx");
  SetRegisterName(2, 8, "rdx");
  SetRegisterName(3, 1, "bl");
  SetRegisterName(3, 2, "bx");
  SetRegisterName(3, 4, "ebx");
  SetRegisterName(3, 8, "rbx");
  SetRegisterName(4, 4, "esp");
  SetRegisterName(4, 8, "rsp");
  SetRegisterName(5, 4, "ebp");
  SetRegisterName(5, 8, "rbp");
  SetRegisterName(6, 4, "esi");
  SetRegisterName(6, 8, "rsi");
  SetRegisterName(7, 4, "edi");
  SetRegisterName(7, 8, "rdi");
  SetRegisterName(29, 2, "ds");
  SetRegisterName(30, 2, "es");
  SetRegisterName(31, 2, "fs");
  SetRegisterName(32, 2, "gs");
}

void IdaTestDatabase::SetProcessor(absl::string_view procname, int32_t id,
                                   int bitness) {
  procname_ = std::string(procname);
  ph_.id = id;
  bitness_ = bitness;
}

void IdaTestDatabase::SetInputFileSha256(absl::string_view raw_32_bytes) {
  sha256_bytes_ = std::string(raw_32_bytes);
}

void IdaTestDatabase::SetInputFileMd5(absl::string_view raw_16_bytes) {
  md5_bytes_ = std::string(raw_16_bytes);
}

void IdaTestDatabase::SetNetnodeValstr(nodeidx_t num, absl::string_view value) {
  netnode_valstrs_[num] = std::string(value);
}

void IdaTestDatabase::SetNetnodeSupval(nodeidx_t num, nodeidx_t alt, int tag,
                                       absl::string_view value) {
  netnode_supvals_[std::make_tuple(num, alt, tag)] = std::string(value);
}

segment_t* IdaTestDatabase::AddSegment(ea_t start_ea, ea_t end_ea, uchar type,
                                       uchar perm, uchar bitness,
                                       absl::Span<const uint8_t> bytes) {
  segment_t seg{};
  seg.start_ea = start_ea;
  seg.end_ea = end_ea;
  seg.type = type;
  seg.perm = perm;
  seg.bitness = bitness;
  segments_.push_back(seg);
  if (!bytes.empty()) {
    SetBytes(start_ea, bytes,
             (type == SEG_CODE ? FF_CODE : FF_DATA) | FF_BYTE | FF_IVL);
  }
  return &segments_.back();
}

void IdaTestDatabase::SetBytes(ea_t ea, absl::Span<const uint8_t> bytes,
                               flags64_t flags) {
  for (size_t i = 0; i < bytes.size(); ++i) {
    memory_[ea + i] = bytes[i];
    if (flags_.find(ea + i) == flags_.end()) {
      flags_[ea + i] = flags;
    }
  }
}

flags64_t IdaTestDatabase::GetFlags(ea_t ea) const {
  auto it = flags_.find(ea);
  if (it != flags_.end()) {
    return it->second;
  }
  if (memory_.find(ea) != memory_.end()) {
    return FF_DATA | FF_BYTE | FF_IVL;
  }
  return 0;
}

void IdaTestDatabase::AddInstruction(const insn_t& insn,
                                     absl::string_view mnemonic,
                                     absl::string_view disasm_line,
                                     absl::Span<const uint8_t> bytes,
                                     bool flow_to_next, bool is_call,
                                     bool is_indirect_jump) {
  instructions_[insn.ea] = InstructionEntry{
      .insn = insn,
      .mnemonic = std::string(mnemonic),
      .disasm_line = disasm_line.empty() ? std::string(mnemonic)
                                         : std::string(disasm_line),
      .is_call = is_call,
      .is_indirect_jump = is_indirect_jump,
  };

  std::vector<uint8_t> raw_bytes(bytes.begin(), bytes.end());
  if (raw_bytes.empty() && insn.size > 0) {
    raw_bytes.assign(insn.size, 0x90);
  }
  for (size_t i = 0; i < raw_bytes.size(); ++i) {
    memory_[insn.ea + i] = raw_bytes[i];
  }
  flags_[insn.ea] |= FF_CODE | FF_IVL;
  for (uint16_t i = 1; i < insn.size; ++i) {
    flags_[insn.ea + i] |= FF_TAIL | FF_IVL;
  }
  if (flow_to_next && insn.size > 0) {
    flags_[insn.ea + insn.size] |= FF_FLOW;
    AddXref(insn.ea, insn.ea + insn.size, fl_F, /*iscode=*/true);
  }
}

void IdaTestDatabase::SetName(ea_t ea, absl::string_view name, bool user_name) {
  if (name.empty()) {
    names_.erase(ea);
    flags_[ea] &= ~FF_NAME;
    return;
  }
  names_[ea] = std::string(name);
  if (user_name) {
    flags_[ea] |= FF_NAME;
    flags_[ea] &= ~FF_LABL;
  } else {
    flags_[ea] |= FF_LABL;
  }
}

void IdaTestDatabase::AddXref(ea_t from, ea_t to, uchar type, bool iscode) {
  const XrefEntry entry{
      .from = from,
      .to = to,
      .iscode = static_cast<uchar>(iscode ? 1 : 0),
      .type = type,
      .user = 0,
  };

  auto insert_sorted = [&](std::vector<XrefEntry>& vec) {
    // Keep code xrefs before data xrefs as documented in xref.hpp.
    if (iscode) {
      auto it = std::find_if(vec.begin(), vec.end(),
                             [](const XrefEntry& e) { return e.iscode == 0; });
      vec.insert(it, entry);
    } else {
      vec.push_back(entry);
    }
  };
  insert_sorted(xrefs_from_[from]);
  insert_sorted(xrefs_to_[to]);
}

func_t* IdaTestDatabase::AddFunction(ea_t start_ea, ea_t end_ea, uint32_t flags,
                                     absl::string_view comment,
                                     absl::string_view repeatable_comment) {
  func_t fn(start_ea, end_ea, flags);
  functions_.push_back(fn);
  if (!comment.empty()) {
    func_comments_[start_ea] = std::string(comment);
  }
  if (!repeatable_comment.empty()) {
    func_repeatable_comments_[start_ea] = std::string(repeatable_comment);
  }
  return &functions_.back();
}

void IdaTestDatabase::SetComment(ea_t ea, absl::string_view comment,
                                 bool repeatable) {
  if (repeatable) {
    repeatable_comments_[ea] = std::string(comment);
  } else {
    comments_[ea] = std::string(comment);
  }
}

void IdaTestDatabase::AddExtraComment(ea_t ea, int what,
                                      absl::string_view comment) {
  extra_comments_[{ea, what}] = std::string(comment);
}

void IdaTestDatabase::SetRegisterName(int reg, size_t width,
                                      absl::string_view name) {
  reg_names_[{reg, width}] = std::string(name);
}

void IdaTestDatabase::AddRegvar(ea_t func_ea, absl::string_view canon,
                                absl::string_view user) {
  std::string canon_str(canon);
  std::string user_str(user);
  regvar_t rv{};
  rv.start_ea = func_ea;
  rv.end_ea = func_ea + 0x1000;
  rv.canon = ::qstrdup(canon_str.c_str());
  rv.user = ::qstrdup(user_str.c_str());
  regvars_.push_back(rv);
}

void IdaTestDatabase::AddImportModule(
    absl::string_view module_name,
    absl::Span<const std::pair<ea_t, std::string>> imports) {
  import_modules_.push_back(ImportModule{
      .name = std::string(module_name),
      .imports = {imports.begin(), imports.end()},
  });
}

void IdaTestDatabase::SetPluginOption(absl::string_view option,
                                      absl::string_view value) {
  plugin_options_[std::string(option)] = std::string(value);
}

void IdaTestDatabase::OnWaitBox(mbox_kind_t kind, absl::string_view text) {
  if (kind == mbox_wait) {
    wait_box_visible_ = true;
    wait_box_messages_.emplace_back(text);
  } else if (kind == mbox_replace) {
    wait_box_messages_.emplace_back(text);
  } else if (kind == mbox_hide) {
    wait_box_visible_ = false;
  } else if (kind == mbox_warning || kind == mbox_info) {
    messages_.append(text);
  }
}

void IdaTestDatabase::RegisterIdcFunc(const ext_idcfunc_t& func) {
  if (func.name != nullptr) {
    idc_funcs_[func.name] = func;
  }
}

error_t IdaTestDatabase::InvokeIdcFunction(absl::string_view name,
                                           absl::string_view arg) {
  auto it = idc_funcs_.find(std::string(name));
  if (it == idc_funcs_.end() || it->second.fptr == nullptr) {
    return -1;
  }
  idc_value_t idc_arg(qstring(arg.data(), arg.size()));
  idc_value_t idc_res;
  return it->second.fptr(&idc_arg, &idc_res);
}

void IdaTestDatabase::AddHook(hook_type_t type, hook_cb_t* cb, void* ud) {
  hooks_.emplace_back(type, cb, ud);
}

int IdaTestDatabase::RemoveHook(hook_type_t type, hook_cb_t* cb, void* ud) {
  auto old_size = hooks_.size();
  hooks_.erase(
      std::remove(hooks_.begin(), hooks_.end(), std::make_tuple(type, cb, ud)),
      hooks_.end());
  return static_cast<int>(old_size - hooks_.size());
}

}  // namespace security::binexport

namespace {

using ::security::binexport::IdaTestDatabase;

struct XrefCursor {
  ea_t ea = BADADDR;
  size_t index = 0;
  int flags = 0;
};

absl::flat_hash_map<const xrefblk_t*, XrefCursor>& XrefFromCursors() {
  static absl::NoDestructor<absl::flat_hash_map<const xrefblk_t*, XrefCursor>>
      cursors;
  return *cursors;
}

absl::flat_hash_map<const xrefblk_t*, XrefCursor>& XrefToCursors() {
  static absl::NoDestructor<absl::flat_hash_map<const xrefblk_t*, XrefCursor>>
      cursors;
  return *cursors;
}

bool MatchesXrefFlags(const IdaTestDatabase::XrefEntry& entry, int flags) {
  if ((flags & XREF_DATA) != 0 && entry.iscode != 0) {
    return false;
  }
  if ((flags & XREF_CODE) != 0 && entry.iscode == 0) {
    return false;
  }
  if ((flags & XREF_NOFLOW) != 0 && entry.iscode != 0 && entry.type == fl_F) {
    return false;
  }
  return true;
}

bool AdvanceXrefFrom(xrefblk_t* xb, XrefCursor* cursor) {
  const auto& map = IdaTestDatabase::instance()->xrefs_from();
  auto it = map.find(cursor->ea);
  if (it == map.end()) {
    return false;
  }
  const auto& vec = it->second;
  while (cursor->index < vec.size()) {
    const auto& entry = vec[cursor->index++];
    if (MatchesXrefFlags(entry, cursor->flags)) {
      xb->from = entry.from;
      xb->to = entry.to;
      xb->iscode = entry.iscode != 0;
      xb->type = entry.type;
      xb->user = entry.user != 0;
      return true;
    }
  }
  return false;
}

bool AdvanceXrefTo(xrefblk_t* xb, XrefCursor* cursor) {
  const auto& map = IdaTestDatabase::instance()->xrefs_to();
  auto it = map.find(cursor->ea);
  if (it == map.end()) {
    return false;
  }
  const auto& vec = it->second;
  while (cursor->index < vec.size()) {
    const auto& entry = vec[cursor->index++];
    if (MatchesXrefFlags(entry, cursor->flags)) {
      xb->from = entry.from;
      xb->to = entry.to;
      xb->iscode = entry.iscode != 0;
      xb->type = entry.type;
      xb->user = entry.user != 0;
      return true;
    }
  }
  return false;
}

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvarargs"
#endif

callui_t idaapi TestCallUi(ui_notification_t what, ...) {
  callui_t result{};
  auto* db = IdaTestDatabase::instance();

  va_list va;
  va_start(va, what);
  switch (what) {
    case ui_msg: {
      const char* format = va_arg(va, const char*);
      auto inner_va = va_arg(va, std::decay_t<va_list>);
      qstring buf;
      buf.vsprnt(format, inner_va);
      db->AppendMessage(absl::string_view(buf.c_str(), buf.length()));
      result.i = static_cast<int>(buf.length());
      break;
    }
    case ui_mbox: {
      int kind = va_arg(va, int);
      const char* format = va_arg(va, const char*);
      if (format != nullptr) {
        auto inner_va = va_arg(va, std::decay_t<va_list>);
        qstring buf;
        buf.vsprnt(format, inner_va);
        db->OnWaitBox(static_cast<mbox_kind_t>(kind),
                      absl::string_view(buf.c_str(), buf.length()));
      } else {
        db->OnWaitBox(static_cast<mbox_kind_t>(kind), "");
      }
      result.ssize = 0;
      break;
    }
    case ui_test_cancelled:
      result.cnd = db->user_cancelled();
      break;
    case ui_clr_cancelled:
      db->SetUserCancelled(false);
      break;
    case ui_set_cancelled:
      db->SetUserCancelled(true);
      break;
    case ui_execute_sync: {
      exec_request_t* req = va_arg(va, exec_request_t*);
      result.ssize = req != nullptr ? req->execute() : 0;
      break;
    }
    case ui_ask_file: {
      (void)va_arg(va, int);
      (void)va_arg(va, const char*);
      result.cptr = db->ask_file_result().empty()
                        ? nullptr
                        : const_cast<char*>(db->ask_file_result().c_str());
      break;
    }
    case ui_ask_form:
      result.i = 1;
      break;
    case ui_addons:
      result.i = 1;
      break;
    default:
      break;
  }
  va_end(va);
  return result;
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif

}  // namespace

// IDA SDK C-linkage symbol overrides for unit testing.

// In <kernwin.hpp>, IDA UI functions (msg, warning, info, show_wait_box,
// replace_wait_box, hide_wait_box, user_cancelled, ask_file, ask_form,
// register_addon, execute_sync, etc.) are inline wrappers that dispatch through
// the global `callui` function pointer exported by the IDA kernel. Define and
// point it at TestCallUi so those inline wrappers link and route UI
// interactions to IdaTestDatabase. On Windows, <kernwin.hpp> declares `callui`
// with `__declspec(dllimport)` (`ida_export_data`), so callers reference the
// import table slot `__imp_callui`.
#ifdef _WIN32
callui_t(idaapi* g_test_callui)(ui_notification_t what, ...) = &TestCallUi;
extern "C" void* __imp_callui = &g_test_callui;
#else
idaman callui_t ida_export_data(idaapi* callui)(ui_notification_t what,
                                                ...) = &TestCallUi;
#endif

idaman size_t ida_export getinf(inftag_t tag) {
  const auto* db = IdaTestDatabase::instance();
  switch (tag) {
    case INF_BASEADDR:
    case INF_IMAGEBASE:
      return db->imagebase();
    case INF_ABIBITS:
      return db->bitness();
    case INF_LFLAGS:
      if (db->bitness() == 64) {
        return LFLG_64BIT | LFLG_PC_FLAT;
      }
      if (db->bitness() == 32) {
        return LFLG_PC_FLAT;
      }
      return 0;
    default:
      return 0;
  }
}

idaman ssize_t ida_export getinf_buf(inftag_t tag, void* buf, size_t bufsize) {
  if (buf == nullptr || bufsize == 0) {
    return 0;
  }
  const auto* db = IdaTestDatabase::instance();
  switch (tag) {
    case INF_PROCNAME: {
      const std::string& proc = db->procname();
      const size_t n = std::min(proc.size(), bufsize - 1);
      std::memcpy(buf, proc.data(), n);
      static_cast<char*>(buf)[n] = '\0';
      return static_cast<ssize_t>(n);
    }
    case INF_INPUT_FILE_PATH: {
      const std::string& path = db->input_file_path();
      if (path.empty()) {
        return 0;
      }
      const size_t n = std::min(path.size(), bufsize - 1);
      std::memcpy(buf, path.data(), n);
      static_cast<char*>(buf)[n] = '\0';
      return static_cast<ssize_t>(n);
    }
    case INF_SHA256: {
      if (db->sha256_bytes().size() != 32 || bufsize < 32) {
        return 0;
      }
      std::memcpy(buf, db->sha256_bytes().data(), 32);
      return 32;
    }
    case INF_MD5: {
      if (db->md5_bytes().size() != 16 || bufsize < 16) {
        return 0;
      }
      std::memcpy(buf, db->md5_bytes().data(), 16);
      return 16;
    }
    default:
      return 0;
  }
}

idaman ssize_t ida_export getinf_str(qstring* buf, inftag_t tag) {
  if (buf == nullptr) {
    return 0;
  }
  const auto* db = IdaTestDatabase::instance();
  if (tag == INF_PROCNAME) {
    *buf = db->procname().c_str();
    return static_cast<ssize_t>(buf->length());
  }
  if (tag == INF_INPUT_FILE_PATH) {
    *buf = db->input_file_path().c_str();
    return static_cast<ssize_t>(buf->length());
  }
  buf->clear();
  return 0;
}

idaman bool ida_export getinf_flag(inftag_t tag, uint32_t flag) {
  return (getinf(tag) & flag) != 0;
}

idaman bool ida_export setinf(inftag_t tag, ssize_t value) {
  auto* db = IdaTestDatabase::instance();
  if (tag == INF_BASEADDR || tag == INF_IMAGEBASE) {
    db->SetImageBase(static_cast<ea_t>(value));
    return true;
  }
  return false;
}

idaman bool ida_export setinf_buf(inftag_t tag, const void* buf,
                                  size_t /*bufsize*/) {
  auto* db = IdaTestDatabase::instance();
  if (tag == INF_PROCNAME && buf != nullptr) {
    db->SetProcessor(static_cast<const char*>(buf), db->ph()->id,
                     db->bitness());
    return true;
  }
  return false;
}

idaman bool ida_export setinf_flag(inftag_t tag, uint32_t flag, bool value) {
  auto* db = IdaTestDatabase::instance();
  if (tag == INF_LFLAGS && flag == LFLG_64BIT) {
    db->SetProcessor(db->procname(), db->ph()->id, value ? 64 : 32);
    return true;
  }
  return false;
}

idaman processor_t* ida_export get_ph() {
  return IdaTestDatabase::instance()->ph();
}

idaman asm_t* ida_export get_ash() {
  return IdaTestDatabase::instance()->ash();
}

idaman int ida_export get_segm_qty() {
  return static_cast<int>(IdaTestDatabase::instance()->segments().size());
}

idaman segment_t* ida_export getnseg(int n) {
  auto& segs = IdaTestDatabase::instance()->mutable_segments();
  if (n < 0 || static_cast<size_t>(n) >= segs.size()) {
    return nullptr;
  }
  return &segs[n];
}

idaman segment_t* ida_export getseg(ea_t ea) {
  auto& segs = IdaTestDatabase::instance()->mutable_segments();
  for (auto& seg : segs) {
    if (ea >= seg.start_ea && ea < seg.end_ea) {
      return &seg;
    }
  }
  return nullptr;
}

idaman uchar ida_export segtype(ea_t ea) {
  if (const segment_t* seg = getseg(ea)) {
    return seg->type;
  }
  return SEG_UNDF;
}

idaman ea_t ida_export next_that(ea_t ea, ea_t maxea, testf_t* testf,
                                 void* ud) {
  if (testf == nullptr) {
    return BADADDR;
  }
  const auto* db = IdaTestDatabase::instance();
  for (ea_t cur = ea + 1; cur < maxea; ++cur) {
    if (testf(db->GetFlags(cur), ud)) {
      return cur;
    }
  }
  return BADADDR;
}

idaman bool ida_export is_mapped(ea_t ea) {
  if (getseg(ea) != nullptr) {
    return true;
  }
  const auto& mem = IdaTestDatabase::instance()->memory();
  return mem.find(ea) != mem.end();
}

idaman bool ida_export is_loaded(ea_t ea) {
  const auto* db = IdaTestDatabase::instance();
  return (db->GetFlags(ea) & FF_IVL) != 0 ||
         db->memory().find(ea) != db->memory().end();
}

idaman flags64_t ida_export get_flags_ex(ea_t ea, int /*how*/) {
  return IdaTestDatabase::instance()->GetFlags(ea);
}

idaman uchar ida_export get_byte(ea_t ea) {
  const auto& mem = IdaTestDatabase::instance()->memory();
  auto it = mem.find(ea);
  return it != mem.end() ? it->second : 0;
}

idaman uint32_t ida_export get_dword(ea_t ea) {
  uint32_t val = 0;
  for (int i = 0; i < 4; ++i) {
    val |= static_cast<uint32_t>(get_byte(ea + i)) << (i * 8);
  }
  return val;
}

idaman ssize_t ida_export get_bytes(void* buf, ssize_t size, ea_t ea,
                                    int /*gmb_flags*/, void* /*mask*/) {
  if (buf == nullptr || size <= 0) {
    return 0;
  }
  auto* out = static_cast<uint8_t*>(buf);
  for (ssize_t i = 0; i < size; ++i) {
    out[i] = get_byte(ea + i);
  }
  return size;
}

idaman bool ida_export is_stkvar(flags64_t F, int n) {
  if (n == 0) {
    return is_stkvar0(F);
  }
  if (n == 1) {
    return is_stkvar1(F);
  }
  return false;
}

idaman size_t ida_export get_max_strlit_length(ea_t ea, int32_t /*strtype*/,
                                               int /*options*/) {
  const auto& mem = IdaTestDatabase::instance()->memory();
  size_t len = 0;
  for (ea_t cur = ea;; ++cur, ++len) {
    auto it = mem.find(cur);
    if (it == mem.end() || it->second == 0) {
      break;
    }
  }
  return len;
}

idaman ssize_t ida_export get_cmt(qstring* buf, ea_t ea, bool rptble) {
  const auto* db = IdaTestDatabase::instance();
  const auto& map = rptble ? db->repeatable_comments() : db->comments();
  auto it = map.find(ea);
  if (it == map.end()) {
    if (buf != nullptr) {
      buf->clear();
    }
    return -1;
  }
  if (buf != nullptr) {
    *buf = it->second.c_str();
  }
  return static_cast<ssize_t>(it->second.size());
}

idaman ssize_t ida_export get_extra_cmt(qstring* buf, ea_t ea, int what) {
  const auto& map = IdaTestDatabase::instance()->extra_comments();
  auto it = map.find({ea, what});
  if (it == map.end()) {
    if (buf != nullptr) {
      buf->clear();
    }
    return -1;
  }
  if (buf != nullptr) {
    *buf = it->second.c_str();
  }
  return static_cast<ssize_t>(it->second.size());
}

idaman ssize_t ida_export get_ea_name(qstring* out, ea_t ea, int /*gtn_flags*/,
                                      getname_info_t* /*gtni*/) {
  const auto& names = IdaTestDatabase::instance()->names();
  auto it = names.find(ea);
  if (it == names.end()) {
    if (out != nullptr) {
      out->clear();
    }
    return 0;
  }
  if (out != nullptr) {
    *out = it->second.c_str();
  }
  return static_cast<ssize_t>(it->second.size());
}

idaman int ida_export get_struct_operand(adiff_t* /*disp*/, adiff_t* /*delta*/,
                                         tid_t* /*path*/, ea_t /*ea*/,
                                         int /*n*/) {
  return 0;
}

idaman ssize_t ida_export tag_remove(qstring* buf, const char* str,
                                     int /*init_level*/) {
  if (buf == nullptr) {
    return 0;
  }
  if (str != nullptr && str != buf->c_str()) {
    *buf = str;
  }
  return static_cast<ssize_t>(buf->length());
}

idaman bool ida_export generate_disasm_line(qstring* buf, ea_t ea,
                                            int /*flags*/) {
  if (buf == nullptr) {
    return false;
  }
  const auto& insns = IdaTestDatabase::instance()->instructions();
  auto it = insns.find(ea);
  if (it == insns.end() || it->second.disasm_line.empty()) {
    buf->clear();
    return false;
  }
  *buf = it->second.disasm_line.c_str();
  return true;
}

idaman bool ida_export print_insn_mnem(qstring* out, ea_t ea) {
  if (out == nullptr) {
    return false;
  }
  const auto& insns = IdaTestDatabase::instance()->instructions();
  auto it = insns.find(ea);
  if (it == insns.end() || it->second.mnemonic.empty()) {
    out->clear();
    return false;
  }
  *out = it->second.mnemonic.c_str();
  return true;
}

idaman int ida_export decode_insn(insn_t* out, ea_t ea) {
  const auto& insns = IdaTestDatabase::instance()->instructions();
  auto it = insns.find(ea);
  if (it == insns.end()) {
    return 0;
  }
  if (out != nullptr) {
    *out = it->second.insn;
  }
  return it->second.insn.size;
}

idaman bool ida_export is_call_insn(const insn_t& insn) {
  const auto& insns = IdaTestDatabase::instance()->instructions();
  auto it = insns.find(insn.ea);
  return it != insns.end() && it->second.is_call;
}

idaman bool ida_export is_indirect_jump_insn(const insn_t& insn) {
  const auto& insns = IdaTestDatabase::instance()->instructions();
  auto it = insns.find(insn.ea);
  return it != insns.end() && it->second.is_indirect_jump;
}

idaman ssize_t ida_export get_reg_name(qstring* buf, int reg, size_t width,
                                       int /*reghi*/) {
  const auto* db = IdaTestDatabase::instance();
  const auto& map = db->reg_names();
  auto it = map.find({reg, width});
  if (it == map.end()) {
    it = map.find({reg, 0});
  }
  if (it != map.end()) {
    if (buf != nullptr) {
      *buf = it->second.c_str();
    }
    return static_cast<ssize_t>(it->second.size());
  }
  if (reg < 0) {
    return -1;
  }
  std::string fallback = absl::StrCat("r", reg);
  if (buf != nullptr) {
    *buf = fallback.c_str();
  }
  return static_cast<ssize_t>(fallback.size());
}

idaman bool ida_export xrefblk_t_first_from(xrefblk_t* xb, ea_t from,
                                            int flags) {
  if (xb == nullptr) {
    return false;
  }
  XrefCursor& cursor = XrefFromCursors()[xb];
  cursor.ea = from;
  cursor.index = 0;
  cursor.flags = flags;
  return AdvanceXrefFrom(xb, &cursor);
}

idaman bool ida_export xrefblk_t_next_from(xrefblk_t* xb) {
  if (xb == nullptr) {
    return false;
  }
  auto& cursors = XrefFromCursors();
  auto it = cursors.find(xb);
  if (it == cursors.end()) {
    return false;
  }
  return AdvanceXrefFrom(xb, &it->second);
}

idaman bool ida_export xrefblk_t_first_to(xrefblk_t* xb, ea_t to, int flags) {
  if (xb == nullptr) {
    return false;
  }
  XrefCursor& cursor = XrefToCursors()[xb];
  cursor.ea = to;
  cursor.index = 0;
  cursor.flags = flags;
  return AdvanceXrefTo(xb, &cursor);
}

idaman bool ida_export xrefblk_t_next_to(xrefblk_t* xb) {
  if (xb == nullptr) {
    return false;
  }
  auto& cursors = XrefToCursors();
  auto it = cursors.find(xb);
  if (it == cursors.end()) {
    return false;
  }
  return AdvanceXrefTo(xb, &it->second);
}

idaman func_t* ida_export get_func(ea_t ea) {
  auto& funcs = IdaTestDatabase::instance()->mutable_functions();
  for (auto& fn : funcs) {
    if (ea >= fn.start_ea && ea < fn.end_ea) {
      return &fn;
    }
  }
  return nullptr;
}

idaman func_t* ida_export getn_fchunk(int n) {
  auto& funcs = IdaTestDatabase::instance()->mutable_functions();
  if (n < 0 || static_cast<size_t>(n) >= funcs.size()) {
    return nullptr;
  }
  return &funcs[n];
}

idaman size_t ida_export get_fchunk_qty(void) {
  return IdaTestDatabase::instance()->mutable_functions().size();
}

idaman ssize_t ida_export get_func_cmt(qstring* buf, const func_t* pfn,
                                       bool repeatable) {
  if (pfn == nullptr) {
    return -1;
  }
  const auto* db = IdaTestDatabase::instance();
  const auto& map =
      repeatable ? db->func_repeatable_comments() : db->func_comments();
  auto it = map.find(pfn->start_ea);
  if (it == map.end()) {
    if (buf != nullptr) {
      buf->clear();
    }
    return -1;
  }
  if (buf != nullptr) {
    *buf = it->second.c_str();
  }
  return static_cast<ssize_t>(it->second.size());
}

idaman bool ida_export get_func_frame(tinfo_t* /*out*/, const func_t* /*pfn*/) {
  return false;
}

idaman ea_t ida_export calc_stkvar_struc_offset(func_t* /*pfn*/,
                                                const insn_t& /*insn*/,
                                                int /*n*/) {
  return BADADDR;
}

idaman regvar_t* ida_export find_regvar(func_t* pfn, ea_t ea1, ea_t /*ea2*/,
                                        const char* canon,
                                        const char* /*user*/) {
  if (pfn == nullptr || canon == nullptr) {
    return nullptr;
  }
  for (auto& rv : IdaTestDatabase::instance()->mutable_regvars()) {
    if (ea1 >= rv.start_ea && ea1 < rv.end_ea &&
        std::strcmp(rv.canon, canon) == 0) {
      return &rv;
    }
  }
  return nullptr;
}

idaman uint ida_export get_import_module_qty() {
  return static_cast<uint>(
      IdaTestDatabase::instance()->import_modules().size());
}

idaman bool ida_export get_import_module_name(qstring* buf, int mod_index) {
  const auto& mods = IdaTestDatabase::instance()->import_modules();
  if (mod_index < 0 || static_cast<size_t>(mod_index) >= mods.size()) {
    return false;
  }
  if (buf != nullptr) {
    *buf = mods[mod_index].name.c_str();
  }
  return true;
}

idaman int ida_export enum_import_names(int mod_index,
                                        import_enum_cb_t* callback,
                                        void* param) {
  const auto& mods = IdaTestDatabase::instance()->import_modules();
  if (mod_index < 0 || static_cast<size_t>(mod_index) >= mods.size() ||
      callback == nullptr) {
    return 0;
  }
  for (size_t i = 0; i < mods[mod_index].imports.size(); ++i) {
    const auto& [ea, name] = mods[mod_index].imports[i];
    int res = callback(ea, name.c_str(), static_cast<uval_t>(i), param);
    if (res == 0) {
      return res;
    }
  }
  return 1;
}

idaman ssize_t ida_export netnode_valstr(nodeidx_t num, char* buf,
                                         size_t bufsize) {
  const auto* db = IdaTestDatabase::instance();
  if (num == 0) {
    auto it = db->netnode_valstrs().find(0);
    const std::string& val =
        it != db->netnode_valstrs().end() ? it->second : db->input_file_path();
    if (val.empty() || buf == nullptr || bufsize == 0) {
      return -1;
    }
    const size_t n = std::min(val.size(), bufsize - 1);
    std::memcpy(buf, val.data(), n);
    buf[n] = '\0';
    return static_cast<ssize_t>(n);
  }
  auto it = db->netnode_valstrs().find(num);
  if (it == db->netnode_valstrs().end() || buf == nullptr || bufsize == 0) {
    return -1;
  }
  const size_t n = std::min(it->second.size(), bufsize - 1);
  std::memcpy(buf, it->second.data(), n);
  buf[n] = '\0';
  return static_cast<ssize_t>(n);
}

idaman ssize_t ida_export netnode_supval(nodeidx_t num, nodeidx_t alt,
                                         void* buf, size_t bufsize, int tag) {
  const auto* db = IdaTestDatabase::instance();
  auto it = db->netnode_supvals().find(std::make_tuple(num, alt, tag));
  if (it != db->netnode_supvals().end()) {
    if (buf != nullptr && bufsize > 0) {
      const size_t n = std::min(it->second.size(), bufsize);
      std::memcpy(buf, it->second.data(), n);
    }
    return static_cast<ssize_t>(it->second.size());
  }
  if (num == 0 && tag == 'S') {
    if (alt == RIDX_FILE_FORMAT_NAME) {
      constexpr absl::string_view kFormat = "ELF64 for x86-64 (Executable)";
      if (buf != nullptr && bufsize > 0) {
        const size_t n = std::min(kFormat.size(), bufsize - 1);
        std::memcpy(buf, kFormat.data(), n);
        static_cast<char*>(buf)[n] = '\0';
        return static_cast<ssize_t>(n + 1);
      }
      return static_cast<ssize_t>(kFormat.size() + 1);
    }
    if (alt == RIDX_SHA256 && !db->sha256_bytes().empty()) {
      const size_t n = std::min(db->sha256_bytes().size(), bufsize);
      if (buf != nullptr && n > 0) {
        std::memcpy(buf, db->sha256_bytes().data(), n);
      }
      return static_cast<ssize_t>(n);
    }
    if (alt == RIDX_MD5 && !db->md5_bytes().empty()) {
      const size_t n = std::min(db->md5_bytes().size(), bufsize);
      if (buf != nullptr && n > 0) {
        std::memcpy(buf, db->md5_bytes().data(), n);
      }
      return static_cast<ssize_t>(n);
    }
  }
  return -1;
}

idaman const char* ida_export get_plugin_options(const char* plugin) {
  if (plugin == nullptr) {
    return nullptr;
  }
  const auto& opts = IdaTestDatabase::instance()->plugin_options();
  auto it = opts.find(plugin);
  return it != opts.end() ? it->second.c_str() : nullptr;
}

idaman void ida_export set_database_flag(uint32_t dbfl, bool cnd) {
  IdaTestDatabase::instance()->set_database_flag_bits(dbfl, cnd);
}

idaman const char* ida_export get_path(path_type_t pt) {
  const auto* db = IdaTestDatabase::instance();
  switch (pt) {
    case PATH_TYPE_IDB:
      return db->idb_path().c_str();
    case PATH_TYPE_CMD:
      return db->input_file_path().c_str();
    default:
      return "";
  }
}

idaman bool ida_export add_idc_func(const ext_idcfunc_t& func) {
  IdaTestDatabase::instance()->RegisterIdcFunc(func);
  return true;
}

idaman bool ida_export auto_wait(void) { return true; }

idaman bool ida_export hook_to_notification_point(hook_type_t hook_type,
                                                  hook_cb_t* cb,
                                                  void* user_data) {
  IdaTestDatabase::instance()->AddHook(hook_type, cb, user_data);
  return true;
}

idaman int ida_export unhook_from_notification_point(hook_type_t hook_type,
                                                     hook_cb_t* cb,
                                                     void* user_data) {
  return IdaTestDatabase::instance()->RemoveHook(hook_type, cb, user_data);
}

idaman void* ida_export find_extlang(const void* /*str*/,
                                     find_extlang_kind_t /*kind*/) {
  return nullptr;
}

idaman void ida_export copy_tinfo_t(tinfo_t* _this, const tinfo_t& r) {
  if (_this != nullptr) {
    _this->typid = r.typid;
  }
}

idaman void ida_export clear_tinfo_t(tinfo_t* _this) {
  if (_this != nullptr) {
    _this->typid = BT_UNK;
  }
}

idaman bool ida_export get_tinfo(tinfo_t* /*tif*/, ea_t /*ea*/) {
  return false;
}

idaman bool ida_export get_tinfo_details(typid_t /*typid*/, type_t /*bt2*/,
                                         void* /*buf*/) {
  return false;
}

idaman size_t ida_export get_tinfo_size(uint32_t* /*p_effalign*/,
                                        typid_t /*typid*/, int /*gts_code*/) {
  return BADSIZE;
}

idaman size_t ida_export get_tinfo_pdata(void* /*outptr*/, typid_t /*typid*/,
                                         int /*what*/) {
  return 0;
}

idaman size_t ida_export get_tinfo_property(typid_t /*typid*/,
                                            int /*gta_prop*/) {
  return 0;
}

idaman ea_helper_t* ida_export get_eah() {
  static ea_helper_t eah;
  eah.setup(IdaTestDatabase::instance()->bitness() == 64);
  return &eah;
}

idaman void ida_export free_regvar(regvar_t* v) {
  if (v != nullptr) {
    qfree(v->canon);
    qfree(v->user);
    qfree(v->cmt);
    v->canon = nullptr;
    v->user = nullptr;
    v->cmt = nullptr;
  }
}

idaman THREAD_SAFE void ida_export free_idcv(idc_value_t* v) {
  if (v != nullptr) {
    if (v->vtype == VT_STR) {
      v->qstr().~qstring();
    }
    v->vtype = VT_LONG;
    v->num = 0;
  }
}

idaman THREAD_SAFE void* ida_export qalloc(size_t size) {
  return std::malloc(size);
}

idaman THREAD_SAFE void* ida_export qrealloc(void* alloc, size_t newsize) {
  return std::realloc(alloc, newsize);
}

idaman THREAD_SAFE void* ida_export qcalloc(size_t nitems, size_t itemsize) {
  return std::calloc(nitems, itemsize);
}

idaman THREAD_SAFE void ida_export qfree(void* alloc) { std::free(alloc); }

idaman THREAD_SAFE void* ida_export qalloc_or_throw(size_t size) {
  void* ptr = std::malloc(size == 0 ? 1 : size);
  if (ptr == nullptr) {
    std::abort();
  }
  return ptr;
}

idaman THREAD_SAFE void* ida_export qrealloc_or_throw(void* ptr, size_t size) {
  void* new_ptr = std::realloc(ptr, size == 0 ? 1 : size);
  if (new_ptr == nullptr) {
    std::abort();
  }
  return new_ptr;
}

idaman THREAD_SAFE char* ida_export qstrdup(const char* string) {
  if (string == nullptr) {
    return nullptr;
  }
  const size_t len = std::strlen(string) + 1;
  auto* copy = static_cast<char*>(qalloc(len));
  if (copy != nullptr) {
    std::memcpy(copy, string, len);
  }
  return copy;
}

idaman THREAD_SAFE char* ida_export qstrncpy(char* dst, const char* src,
                                             size_t dstsize) {
  if (dst == nullptr || dstsize == 0) {
    return dst;
  }
  if (src == nullptr) {
    dst[0] = '\0';
    return dst;
  }
  const size_t len = std::min(std::strlen(src), dstsize - 1);
  std::memcpy(dst, src, len);
  dst[len] = '\0';
  return dst;
}

idaman THREAD_SAFE void* ida_export qvector_reserve(void* vec, void* old,
                                                    size_t cnt, size_t elsize) {
  auto* v = static_cast<qvector<char>*>(vec);
  const size_t new_alloc = std::max(cnt, v->alloc * 2);
  v->alloc = new_alloc;
  return qrealloc_or_throw(old, new_alloc * elsize);
}

idaman AS_PRINTF(3, 0) THREAD_SAFE int ida_export
    qvsnprintf(char* buffer, size_t n, const char* format, va_list va) {
  if (format == nullptr) {
    if (buffer != nullptr && n > 0) {
      buffer[0] = '\0';
    }
    return 0;
  }
  if (buffer == nullptr || n == 0) {
    const int res = std::vsnprintf(nullptr, 0, format, va);
    return res > 0 ? res : 0;
  }
  const int res = std::vsnprintf(buffer, n, format, va);
  if (res < 0) {
    buffer[0] = '\0';
    return 0;
  }
  buffer[n - 1] = '\0';
  return static_cast<int>(std::min(static_cast<size_t>(res), n - 1));
}

idaman AS_PRINTF(3, 4) THREAD_SAFE int ida_export
    qsnprintf(char* buffer, size_t n, const char* format, ...) {
  va_list va;
  va_start(va, format);
  const int res = qvsnprintf(buffer, n, format, va);
  va_end(va);
  return res;
}

idaman THREAD_SAFE NORETURN void ida_export qexit(int code) { std::exit(code); }

idaman THREAD_SAFE bool ida_export qsem_free(qsemaphore_t /*sem*/) {
  return true;
}

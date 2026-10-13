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

#ifndef IDA_IDA_TEST_UTIL_H_
#define IDA_IDA_TEST_UTIL_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
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
#include <name.hpp>                                             // NOLINT
#include <netnode.hpp>                                          // NOLINT
#include <segment.hpp>                                          // NOLINT
#include <typeinf.hpp>                                          // NOLINT
#include <ua.hpp>                                               // NOLINT
#include <xref.hpp>                                             // NOLINT
#include "third_party/zynamics/binexport/ida/end_idasdk.inc"    // NOLINT
// clang-format on

#include "gtest/gtest.h"
#include "third_party/absl/container/btree_map.h"
#include "third_party/absl/container/flat_hash_map.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/absl/types/span.h"

namespace security::binexport {

// In-memory fake IDA database and UI harness backing IDA SDK calls in unit
// tests.
//
// How IDA SDK symbol overriding works:
// - In production, the BinExport IDA plugin is built as a shared library
//   (.so/.dylib/.dll) that leaves IDA SDK C-linkage functions (`idaman ...
//   ida_export`, such as `getinf`, `getseg`, `decode_insn`, `qalloc`) and the
//   global `callui` UI dispatcher pointer unresolved at link time (or resolved
//   against `ida.lib` import thunks on Windows), relying on the host IDA Pro
//   kernel (`libida`) to provide those symbols when the plugin is loaded.
// - In unit tests (`ida_test`), the plugin's translation units
//   (`binexport_ida` and `binexport_plugin_shared`) are linked directly into a
//   standalone test executable without `libida`.
// - `ida_test_util.cc` defines strong `extern "C"` (`idaman`) implementations
//   for the IDA SDK functions, `<pro.h>` memory/string/container primitives,
//   and the `callui` function pointer (plus `__imp_callui` on Windows, where
//   `<kernwin.hpp>` declares `callui` with `__declspec(dllimport)`).
// - Because IDA SDK headers declare all kernel entry points as `extern "C"`
//   functions (and inline wrappers in `<kernwin.hpp>`, `<bytes.hpp>`, etc.
//   simply forward to those `extern "C"` functions or `callui`), the linker
//   resolves every IDA SDK call from the plugin code to the definitions in
//   `ida_test_util.cc`, which read and mutate the singleton `IdaTestDatabase`
//   instance below.
class IdaTestDatabase {
 public:
  struct XrefEntry {
    ea_t from = BADADDR;
    ea_t to = BADADDR;
    uchar iscode = 0;
    uchar type = 0;
    uchar user = 0;
  };

  struct InstructionEntry {
    insn_t insn;
    std::string mnemonic;
    std::string disasm_line;
    bool is_call = false;
    bool is_indirect_jump = false;
  };

  struct ImportModule {
    std::string name;
    std::vector<std::pair<ea_t, std::string>> imports;
  };

  IdaTestDatabase();
  ~IdaTestDatabase();

  static IdaTestDatabase* instance();
  void Reset();

  // Processor and database metadata configuration.
  void SetProcessor(absl::string_view procname, int32_t id = PLFM_386,
                    int bitness = 64);
  void SetImageBase(ea_t imagebase) { imagebase_ = imagebase; }
  void SetInputFilePath(absl::string_view path) {
    input_file_path_ = std::string(path);
  }
  void SetIdbPath(absl::string_view path) { idb_path_ = std::string(path); }
  void SetInputFileSha256(absl::string_view raw_32_bytes);
  void SetInputFileMd5(absl::string_view raw_16_bytes);
  void SetNetnodeValstr(nodeidx_t num, absl::string_view value);
  void SetNetnodeSupval(nodeidx_t num, nodeidx_t alt, int tag,
                        absl::string_view value);

  // Segments, bytes, and flags.
  segment_t* AddSegment(ea_t start_ea, ea_t end_ea, uchar type = SEG_CODE,
                        uchar perm = SEGPERM_READ | SEGPERM_EXEC,
                        uchar bitness = 2,
                        absl::Span<const uint8_t> bytes = {});
  void SetBytes(ea_t ea, absl::Span<const uint8_t> bytes,
                flags64_t flags = FF_DATA | FF_BYTE | FF_IVL);
  void SetFlags(ea_t ea, flags64_t flags) { flags_[ea] = flags; }
  flags64_t GetFlags(ea_t ea) const;

  // Instructions, names, xrefs, functions, and comments.
  void AddInstruction(const insn_t& insn, absl::string_view mnemonic,
                      absl::string_view disasm_line = "",
                      absl::Span<const uint8_t> bytes = {},
                      bool flow_to_next = true, bool is_call = false,
                      bool is_indirect_jump = false);
  void SetName(ea_t ea, absl::string_view name, bool user_name = true);
  void AddXref(ea_t from, ea_t to, uchar type, bool iscode = true);
  func_t* AddFunction(ea_t start_ea, ea_t end_ea, uint32_t flags = 0,
                      absl::string_view comment = "",
                      absl::string_view repeatable_comment = "");
  void SetComment(ea_t ea, absl::string_view comment, bool repeatable = false);
  void AddExtraComment(ea_t ea, int what, absl::string_view comment);
  void SetRegisterName(int reg, size_t width, absl::string_view name);
  void AddRegvar(ea_t func_ea, absl::string_view canon, absl::string_view user);
  void AddImportModule(absl::string_view module_name,
                       absl::Span<const std::pair<ea_t, std::string>> imports);

  // Plugin options and UI state.
  void SetPluginOption(absl::string_view option, absl::string_view value);
  void SetAskFileResult(absl::string_view filename) {
    ask_file_result_ = std::string(filename);
  }
  void ClearAskFileResult() { ask_file_result_.clear(); }
  void SetUserCancelled(bool cancelled) { user_cancelled_ = cancelled; }

  const std::string& messages() const { return messages_; }
  void ClearMessages() { messages_.clear(); }
  const std::vector<std::string>& wait_box_messages() const {
    return wait_box_messages_;
  }
  bool wait_box_visible() const { return wait_box_visible_; }
  uint32_t database_flags() const { return database_flags_; }

  error_t InvokeIdcFunction(absl::string_view name, absl::string_view arg);

  // Accessors used by the IDA SDK symbol overrides.
  const std::string& procname() const { return procname_; }
  int bitness() const { return bitness_; }
  ea_t imagebase() const { return imagebase_; }
  const std::string& input_file_path() const { return input_file_path_; }
  const std::string& idb_path() const { return idb_path_; }
  const std::string& sha256_bytes() const { return sha256_bytes_; }
  const std::string& md5_bytes() const { return md5_bytes_; }
  processor_t* ph() { return &ph_; }
  asm_t* ash() { return &ash_; }

  const std::vector<segment_t>& segments() const { return segments_; }
  std::vector<segment_t>& mutable_segments() { return segments_; }
  const absl::btree_map<ea_t, uint8_t>& memory() const { return memory_; }
  const absl::btree_map<ea_t, InstructionEntry>& instructions() const {
    return instructions_;
  }
  const absl::flat_hash_map<ea_t, std::string>& names() const { return names_; }
  const absl::flat_hash_map<ea_t, std::vector<XrefEntry>>& xrefs_from() const {
    return xrefs_from_;
  }
  const absl::flat_hash_map<ea_t, std::vector<XrefEntry>>& xrefs_to() const {
    return xrefs_to_;
  }
  std::vector<func_t>& mutable_functions() { return functions_; }
  const absl::flat_hash_map<ea_t, std::string>& func_comments() const {
    return func_comments_;
  }
  const absl::flat_hash_map<ea_t, std::string>& func_repeatable_comments()
      const {
    return func_repeatable_comments_;
  }
  const absl::flat_hash_map<ea_t, std::string>& comments() const {
    return comments_;
  }
  const absl::flat_hash_map<ea_t, std::string>& repeatable_comments() const {
    return repeatable_comments_;
  }
  const absl::flat_hash_map<std::pair<ea_t, int>, std::string>& extra_comments()
      const {
    return extra_comments_;
  }
  const absl::flat_hash_map<std::pair<int, size_t>, std::string>& reg_names()
      const {
    return reg_names_;
  }
  std::vector<regvar_t>& mutable_regvars() { return regvars_; }
  const std::vector<ImportModule>& import_modules() const {
    return import_modules_;
  }
  const absl::flat_hash_map<nodeidx_t, std::string>& netnode_valstrs() const {
    return netnode_valstrs_;
  }
  const absl::flat_hash_map<std::tuple<nodeidx_t, nodeidx_t, int>, std::string>&
  netnode_supvals() const {
    return netnode_supvals_;
  }
  const absl::flat_hash_map<std::string, std::string>& plugin_options() const {
    return plugin_options_;
  }
  void set_database_flag_bits(uint32_t mask, bool set) {
    if (set) {
      database_flags_ |= mask;
    } else {
      database_flags_ &= ~mask;
    }
  }
  void AppendMessage(absl::string_view msg) { messages_.append(msg); }
  void OnWaitBox(mbox_kind_t kind, absl::string_view text);
  bool user_cancelled() const { return user_cancelled_; }
  const std::string& ask_file_result() const { return ask_file_result_; }
  void RegisterIdcFunc(const ext_idcfunc_t& func);
  void AddHook(hook_type_t type, hook_cb_t* cb, void* ud);
  int RemoveHook(hook_type_t type, hook_cb_t* cb, void* ud);

 private:
  std::string procname_;
  int bitness_ = 64;
  ea_t imagebase_ = 0x1000;
  std::string input_file_path_;
  std::string idb_path_;
  std::string sha256_bytes_;
  std::string md5_bytes_;
  processor_t ph_{};
  asm_t ash_{};

  std::vector<segment_t> segments_;
  absl::btree_map<ea_t, uint8_t> memory_;
  absl::btree_map<ea_t, flags64_t> flags_;
  absl::btree_map<ea_t, InstructionEntry> instructions_;
  absl::flat_hash_map<ea_t, std::string> names_;
  absl::flat_hash_map<ea_t, std::vector<XrefEntry>> xrefs_from_;
  absl::flat_hash_map<ea_t, std::vector<XrefEntry>> xrefs_to_;
  std::vector<func_t> functions_;
  absl::flat_hash_map<ea_t, std::string> func_comments_;
  absl::flat_hash_map<ea_t, std::string> func_repeatable_comments_;
  absl::flat_hash_map<ea_t, std::string> comments_;
  absl::flat_hash_map<ea_t, std::string> repeatable_comments_;
  absl::flat_hash_map<std::pair<ea_t, int>, std::string> extra_comments_;
  absl::flat_hash_map<std::pair<int, size_t>, std::string> reg_names_;
  std::vector<std::pair<std::string, std::string>> regvar_strings_;
  std::vector<regvar_t> regvars_;
  std::vector<ImportModule> import_modules_;
  absl::flat_hash_map<nodeidx_t, std::string> netnode_valstrs_;
  absl::flat_hash_map<std::tuple<nodeidx_t, nodeidx_t, int>, std::string>
      netnode_supvals_;
  absl::flat_hash_map<std::string, std::string> plugin_options_;
  absl::flat_hash_map<std::string, ext_idcfunc_t> idc_funcs_;
  std::vector<std::tuple<hook_type_t, hook_cb_t*, void*>> hooks_;

  uint32_t database_flags_ = 0;
  bool user_cancelled_ = false;
  bool wait_box_visible_ = false;
  std::vector<std::string> wait_box_messages_;
  std::string messages_;
  std::string ask_file_result_;
};

// Base GoogleTest fixture that resets the in-memory test database for each
// test.
class IdaTest : public ::testing::Test {
 protected:
  void SetUp() override { db().Reset(); }

  IdaTestDatabase& db() { return *IdaTestDatabase::instance(); }
};

}  // namespace security::binexport

#endif  // IDA_IDA_TEST_UTIL_H_

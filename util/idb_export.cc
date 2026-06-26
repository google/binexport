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

#include "third_party/zynamics/binexport/util/idb_export.h"

#include <fstream>
#include <memory>
#include <thread>  // NOLINT

#include "third_party/absl/base/attributes.h"
#include "third_party/absl/container/flat_hash_map.h"
#include "third_party/absl/container/flat_hash_set.h"
#include "third_party/absl/memory/memory.h"
#include "third_party/absl/status/status.h"
#include "third_party/absl/status/statusor.h"
#include "third_party/absl/strings/ascii.h"
#include "third_party/absl/strings/match.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/str_format.h"
#include "third_party/absl/strings/str_join.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/absl/synchronization/mutex.h"
#include "third_party/absl/time/time.h"
#include "third_party/zynamics/binexport/util/filesystem.h"
#include "third_party/zynamics/binexport/util/process.h"
#include "third_party/zynamics/binexport/util/status_macros.h"
#include "third_party/zynamics/binexport/util/timer.h"

namespace security::binexport {
namespace {

constexpr const char* OptionBool(bool value) {
  return value ? "TRUE" : "FALSE";
}

absl::flat_hash_map<std::string, std::string> ida_exe_path_cache;
absl::Mutex ida_exe_path_cache_mutex;
std::string GetIdaExePath(const std::string& ida_dir, bool is_64bit) {
  absl::MutexLock lock(&ida_exe_path_cache_mutex);

  const std::string key =
      absl::StrCat(ida_dir, is_64bit ? ":64" : ":32");
  auto it = ida_exe_path_cache.find(key);
  if (it != ida_exe_path_cache.end()) {
    return it->second;
  }

#ifdef _WIN32
  const auto ida64_exe_path = JoinPath(ida_dir, "ida64.exe");
  const auto ida_exe_path = JoinPath(ida_dir, "ida.exe");
#else
  const auto ida64_exe_path = JoinPath(ida_dir, "ida64");
  const auto ida_exe_path = JoinPath(ida_dir, "ida");
#endif

  const std::string main_ida_exe_path =
      is_64bit ? ida64_exe_path : ida_exe_path;
  if (FileExists(ida_exe_path)) {
    ida_exe_path_cache[key] = main_ida_exe_path;
    return main_ida_exe_path;
  }

  if (FileExists(ida_exe_path)) {
    ida_exe_path_cache[key] = ida_exe_path;
    return ida_exe_path;
  }

  // Cache the negative result as well.
  ida_exe_path_cache[key] = "";
  return "";
}

}  // namespace

void IdbExporter::AddDatabase(std::string path) {
  absl::MutexLock lock{&queue_mutex_};
  idb_paths_.push_back(std::move(path));
}

absl::Status ExportDatabase(const std::string& idb_path,
                            const IdbExporter::Options& options) {
  // Check existence first to avoid running IDA needlessly.
  if (!FileExists(idb_path)) {
    return absl::NotFoundError(absl::StrCat("File not found: " + idb_path));
  }

  const auto ida_exe_path =
      GetIdaExePath(options.ida_dir, absl::EqualsIgnoreCase(
                                         GetFileExtension(idb_path),
                                         kIdbExtension64));
  if (ida_exe_path.empty()) {
    return absl::NotFoundError(absl::StrCat(
        "Cannot find IDA executable in: ", options.ida_dir));
  }

  std::vector<std::string> args;
  args.push_back(ida_exe_path);
  args.push_back("-A");
  args.push_back("-OBinExportAutoAction:BinExportBinary");
  args.push_back(absl::StrCat(
      "-OBinExportModule:",
      // Make the output name deterministic. When only specifying a directory,
      // BinExport will use the IDB's original executable name as the base name.
      JoinPath(options.export_dir,
               ReplaceFileExtension(Basename(idb_path), kBinExportExtension))));
  args.push_back(absl::StrCat("-OBinExportAlsoLogToStdErr:",
                              OptionBool(options.alsologtostderr)));
  if (!options.log_filename.empty()) {
    args.push_back(absl::StrCat("-OBinExportLogFile:", options.log_filename));
  }
  args.push_back(absl::StrCat("-OBinExportX86NoReturnHeuristic:",
                              OptionBool(options.x86_noreturn_heuristic)));
  args.push_back(idb_path);

  SetEnvironmentVariable("TVHEADLESS", "1");
  absl::StatusOr<int> exit = SpawnProcessAndWait(args);

  // Reset environment variable.
  SetEnvironmentVariable("TVHEADLESS", /*value=*/"");
  return exit.status();
}

absl::Status IdbExporter::Export(
    std::function<bool(const absl::Status&, const std::string&, double)>
        progress) {
  std::vector<std::thread> threads;
  threads.reserve(options_.num_threads);
  std::vector<absl::Status> statuses(options_.num_threads);
  for (int i = 0; i < options_.num_threads; ++i) {
    auto& status = statuses[i];
    threads.emplace_back([this, &status, &progress]() {
      while (true) {
        std::string idb_path;
        {
          absl::MutexLock lock(&queue_mutex_);
          if (idb_paths_.empty()) {
            break;
          }
          idb_path = std::move(idb_paths_.back());
          idb_paths_.pop_back();
        }
        Timer<> timer;
        status = ExportDatabase(idb_path, options_);
        if (progress && !progress(status, idb_path, timer.elapsed())) {
          break;
        }
      }
    });
  }
  for (auto& thread : threads) {
    thread.join();
  }

  // Return first error
  for (const auto& status : statuses) {
    NA_RETURN_IF_ERROR(status);
  }
  return absl::OkStatus();
}

absl::StatusOr<std::vector<std::string>> CollectIdbsToExport(
    absl::string_view path, std::vector<std::string>* existing_binexports) {
  std::vector<std::string> entries;
  NA_RETURN_IF_ERROR(GetDirectoryEntries(path, &entries));

  absl::flat_hash_map<std::string, std::string> split_entries;
  absl::flat_hash_map<std::string, std::string> split_binexports;
  for (const auto& entry : entries) {
    if (IsDirectory(JoinPath(path, entry))) {
      continue;
    }
    std::string filename = ReplaceFileExtension(entry, "");
    std::string ext = GetFileExtension(entry);

    const bool is_binexport = absl::EqualsIgnoreCase(ext, kBinExportExtension);
    if (is_binexport) {
      if (split_binexports.emplace(filename, ext).second) {
        split_entries.erase(filename);
        if (existing_binexports) {
          existing_binexports->push_back(absl::StrCat(filename, ext));
        }
      }
    } else if (split_binexports.count(filename) == 0) {
      const bool is_i64 = absl::EqualsIgnoreCase(ext, kIdbExtension64);
      const bool is_idb = absl::EqualsIgnoreCase(ext, kIdbExtension);
      if (is_i64 || is_idb) {
        auto& split_ext = split_entries[std::move(filename)];
        if (split_ext.empty() || absl::EqualsIgnoreCase(split_ext, ext) ||
            (is_i64 && absl::EqualsIgnoreCase(split_ext, kIdbExtension))) {
          split_ext = std::move(ext);
        }
      }
    }
  }
  entries.clear();
  for (const auto& [filename, ext] : split_entries) {
    entries.push_back(absl::StrCat(filename, ext));
  }
  entries.shrink_to_fit();
  return entries;
}

}  // namespace security::binexport

// Copyright 2011-2025 Google LLC
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

#include "third_party/zynamics/binexport/util/filesystem.h"

#ifdef _WIN32
#define _WIN32_WINNT 0x0600
#define VC_EXTRALEAN
// clang-format off
#include <windows.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <stdlib.h>
// clang-format on

#undef CopyFile             // winbase.h
#undef GetCurrentDirectory  // processenv.h
#undef GetFullPathName      // fileapi.h
#undef StrCat               // shlwapi.h
#else
#include <dirent.h>
#include <libgen.h>  // POSIX basename()
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include <algorithm>  // IWYU pragma: keep
#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <cstring>     // IWYU pragma: keep
#include <filesystem>  // NOLINT(build/c++17)
#include <fstream>
#include <initializer_list>
#include <ios>
#include <memory>
#include <string>
#include <system_error>  // NOLINT(build/c++11)
#include <vector>

#include "third_party/absl/status/status.h"
#include "third_party/absl/strings/ascii.h"
#include "third_party/absl/strings/match.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/str_replace.h"  // IWYU pragma: keep
#include "third_party/absl/strings/string_view.h"
#include "third_party/absl/strings/strip.h"  // IWYU pragma: keep
#include "third_party/zynamics/binexport/util/process.h"
#include "third_party/zynamics/binexport/util/status_macros.h"

using security::binexport::GetLastOsError;

namespace internal {

std::string JoinPathImpl(std::initializer_list<absl::string_view> paths) {
  std::string result;
  for (auto& path : paths) {
    if (path.empty()) {
      continue;
    }
    if (result.empty() || result[result.size() - 1] == kPathSeparator[0]) {
      absl::StrAppend(&result, path);
    } else {
      absl::StrAppend(&result, kPathSeparator, path);
    }
  }
  return result;
}

}  // namespace internal

std::string GetCurrentDirectory() {
  enum { kMaxPath = 260 };
  char buffer[kMaxPath] = {0};
#ifdef _WIN32
  if (GetCurrentDirectoryA(kMaxPath, buffer) == 0) {
    return "";
  }
#else
  if (!getcwd(buffer, kMaxPath)) {
    return "";
  }
#endif
  return std::string(buffer);
}

std::string GetFullPathName(absl::string_view path) {
#ifdef _WIN32
  if (!PathIsRelativeA(std::string(path).c_str())) {
    return std::string(path);
  }
#else
  if (absl::StartsWith(path, kPathSeparator)) {
    return std::string(path);
  }
#endif
  return JoinPath(GetCurrentDirectory(), path);
}

absl::Status CreateDirectories(absl::string_view path) {
  if (path.empty()) {
    return absl::OkStatus();
  }
#ifdef _WIN32
  std::string real_path = absl::StrReplaceAll(path, {{"/", "\\"}});
  const int result = SHCreateDirectoryEx(
      /*hwnd=*/nullptr, real_path.c_str(), /*psa=*/nullptr);
  if (result != ERROR_SUCCESS && result != ERROR_ALREADY_EXISTS &&
      result != ERROR_FILE_EXISTS) {
    return absl::UnknownError(absl::StrCat("cannot create directory \"", path,
                                           "\": ", GetLastOsError()));
  }
#else
  auto slash = path.rfind('/');
  if (slash != absl::string_view::npos) {
    // Create parent directory recursively.
    NA_RETURN_IF_ERROR(CreateDirectories(path.substr(0, slash)));
  }
  std::string path_copy(path);
  if (mkdir(path_copy.c_str(), 0775) == -1) {
    // Ignore existing directories.
    if (errno != EEXIST) {
      return absl::UnknownError(absl::StrCat("cannot create directory \"", path,
                                             "\": ", GetLastOsError()));
    }
  }
#endif
  return absl::OkStatus();
}

namespace {

absl::StatusOr<std::string> DoGetOrCreateTempDirectory(
    absl::string_view product_name, bool create) {
  std::string path;
#ifdef _WIN32
  char buffer[MAX_PATH] = {0};
  if (GetTempPath(MAX_PATH, buffer) == 0) {
    return absl::UnknownError(
        absl::StrCat("error getting temp directory", GetLastOsError()));
  }
  path = JoinPath(buffer, product_name);
#else
  path = JoinPath("/tmp", absl::AsciiStrToLower(product_name));
#endif
  if (create) {
    NA_RETURN_IF_ERROR(CreateDirectories(path));
  }
  return path;
}

}  // namespace

absl::StatusOr<std::string> GetTempDirectory(absl::string_view product_name) {
  return DoGetOrCreateTempDirectory(product_name, /*create=*/false);
}

absl::StatusOr<std::string> GetOrCreateTempDirectory(
    absl::string_view product_name) {
  return DoGetOrCreateTempDirectory(product_name, /*create=*/true);
}

std::string Basename(absl::string_view path) {
  const auto last_slash = path.find_last_of(kSupportedPathSeparators);
  return std::string(last_slash == absl::string_view::npos
                         ? path
                         : absl::ClippedSubstr(path, last_slash + 1));
}

std::string Dirname(absl::string_view path) {
  std::string path_copy(path);
#ifdef _WIN32
  char drive[_MAX_DRIVE] = {0};
  char dirname[_MAX_DIR] = {0};
  if (_splitpath_s(path_copy.c_str(), drive, _MAX_DRIVE,
                   dirname /* Directory */, _MAX_FNAME, nullptr /* Filename */,
                   0 /* Filename length */, nullptr /* Extension */,
                   0 /* Extension length */) != 0) {
    return ".";  // Safe default in case this ever happens.
  }
  return absl::StrCat(drive, absl::StripSuffix(dirname, kPathSeparator));
#else
  return std::string(dirname(&path_copy[0]));
#endif
}

std::string GetFileExtension(absl::string_view path) {
  std::string extension = Basename(path);
  auto pos = extension.rfind('.');
  return pos != absl::string_view::npos ? extension.substr(pos) : "";
}

std::string ReplaceFileExtension(absl::string_view path,
                                 absl::string_view new_extension) {
  auto last_slash = path.find_last_of(kSupportedPathSeparators);
  if (last_slash == absl::string_view::npos) {
    last_slash = 0;
  }
  auto pos = path.substr(last_slash).find_last_of('.');
  if (pos != absl::string_view::npos) {
    pos += last_slash;
  }
  return absl::StrCat(path.substr(0, pos), new_extension);
}

#ifndef _WIN32
namespace {

absl::StatusOr<mode_t> GetFileMode(const std::string& path) {
  struct stat file_info;
  if (stat(path.c_str(), &file_info) == -1) {
    switch (errno) {
      case EACCES:
      case ENOENT:
      case ENOTDIR:
        return 0;
      default:
        return absl::ErrnoToStatus(
            errno, absl::StrCat("stat() failed for \"", path, "\""));
    }
  }
  return file_info.st_mode;
}

}  // namespace
#endif

absl::StatusOr<int64_t> GetFileSize(absl::string_view path) {
  std::ifstream stream(std::string(path), std::ios::ate);
  auto size = static_cast<int64_t>(stream.tellg());
  if (stream) {
    return size;
  }
  return absl::UnknownError(absl::StrCat("cannot get file size for: ", path));
}

bool FileExists(absl::string_view path) {
  std::string path_copy(path);
#ifdef _WIN32
  DWORD attr = GetFileAttributes(path_copy.c_str());
  return (attr != INVALID_FILE_ATTRIBUTES) &&
         !(attr & FILE_ATTRIBUTE_DIRECTORY);
#else
  auto mode = GetFileMode(path_copy);
  return mode.ok() ? S_ISREG(*mode) : false;
#endif
}

bool IsDirectory(absl::string_view path) {
  std::string path_copy(path);
#ifdef _WIN32
  DWORD attr = GetFileAttributes(path_copy.c_str());
  return (attr != INVALID_FILE_ATTRIBUTES) && (attr & FILE_ATTRIBUTE_DIRECTORY);
#else
  auto mode = GetFileMode(path_copy);
  return mode.ok() ? S_ISDIR(*mode) : false;
#endif
}

absl::Status GetDirectoryEntries(absl::string_view path,
                                 std::vector<std::string>* result) {
#ifdef _WIN32
  std::string path_copy(JoinPath(path, "*"));  // Assume path is a directory
  WIN32_FIND_DATA entry;
  HANDLE directory = FindFirstFile(path_copy.c_str(), &entry);
  bool error = directory == INVALID_HANDLE_VALUE;
  if (!error) {
    do {
      result->push_back(entry.cFileName);
    } while (FindNextFile(directory, &entry) != 0);
    error = GetLastError() != ERROR_NO_MORE_FILES;
    FindClose(directory);
  }
  if (error) {
    return absl::UnknownError(
        absl::StrCat("FindFirstFile() failed for: ", path));
  }
#else
  std::string path_copy(path);
  errno = 0;
  DIR* directory = opendir(path_copy.c_str());
  if (!directory) {
    return absl::ErrnoToStatus(
        errno, absl::StrCat("opendir() failed for \"", path, "\""));
  }
  struct dirent* entry;
  while ((entry = readdir(directory))) {
    const std::string name(entry->d_name);
    if (name != "." && name != "..") {
      result->push_back(name);
    }
  }
  if (errno != 0) {
    return absl::ErrnoToStatus(errno, "readdir() failed");
  }
  closedir(directory);
#endif
  return absl::OkStatus();
}

absl::Status RemoveAll(absl::string_view path) {
  std::string path_copy(path);
#ifdef _WIN32
  // Linking against filesystem is difficult on Linux and macOS' XCode does not
  // have it. Visual Studio's standard library has it integrated.
  // TODO(cblichmann): Use filesystem once libstdc++ is >= 8.3 everywhere.
  namespace fs = std::filesystem;
  if (std::error_code ec;
      fs::remove_all(path_copy, ec) == static_cast<std::uintmax_t>(-1)) {
    return absl::UnknownError(
        absl::StrCat("remove_all() failed for \"", path, "\": ", ec.message()));
  }
#else
  errno = 0;
  if (!IsDirectory(path)) {
    return absl::UnknownError(absl::StrCat("Not a directory: ", path));
  }
  DIR* directory = opendir(path_copy.c_str());
  if (!directory) {
    return absl::ErrnoToStatus(
        errno, absl::StrCat("opendir() failed for \"", path, "\""));
  }
  struct dirent* entry;
  while ((entry = readdir(directory))) {
    const std::string name(entry->d_name);
    if (name == "." || name == "..") {
      continue;
    }
    const std::string full_path(JoinPath(path, name));
    if (IsDirectory(full_path)) {
      NA_RETURN_IF_ERROR(RemoveAll(full_path));
    } else {
      std::remove(full_path.c_str());
    }
  }
  if (errno != 0) {
    return absl::ErrnoToStatus(errno, "readdir() failed");
  }
  closedir(directory);
  if (rmdir(path_copy.c_str()) == -1) {
    return absl::ErrnoToStatus(errno, "rmdir() failed ");
  }
#endif
  return absl::OkStatus();
}

absl::Status CopyFile(absl::string_view from, absl::string_view to) {
  std::ifstream input(std::string(from), std::ios::in | std::ios::binary);
  std::ofstream output(std::string(to),
                       std::ios::out | std::ios::trunc | std::ios::binary);
  output << input.rdbuf();
  if (!input) {
    return absl::UnknownError(absl::StrCat("Stream read failed for \"", from,
                                           "\": ", GetLastOsError()));
  }
  if (!output) {
    return absl::UnknownError(absl::StrCat("Stream write failed for \"", to,
                                           "\": ", GetLastOsError()));
  }
  return absl::OkStatus();
}

absl::Status CreateOrUpdateLinkWithFallback(const std::string& target,
                                            const std::string& link_path) {
#ifndef _WIN32
  std::unique_ptr<char, void (*)(char*)> canonical_path(
      nullptr, [](char* p) { free(p); });
  if (canonical_path.reset(realpath(target.c_str(), nullptr));
      !canonical_path) {
    return absl::ErrnoToStatus(errno,
                               absl::StrCat("Cannot read '", target, "'"));
  }

  // symlink() will not overwrite, so remove first. Since remove can fail for
  // many reasons, the error is ignored here and symlink() will fail below.
  remove(link_path.c_str());

  if (symlink(canonical_path.get(), link_path.c_str()) == -1) {
    return absl::ErrnoToStatus(
        errno, absl::StrCat("Symlink creation of '", link_path, "': "));
  }
  return absl::OkStatus();
#else
  std::string canonical_target(MAX_PATH, '\0');
  if (!PathCanonicalize(&canonical_target[0], target.c_str()) ||
      !PathFileExists(canonical_target.c_str())) {
    return absl::FailedPreconditionError(
        absl::StrCat("Cannot read '", target, "': ", GetLastOsError()));
  }
  canonical_target.resize(strlen(canonical_target.c_str()));  // Right-trim NULs

  std::string canonical_path(MAX_PATH, '\0');
  if (!PathCanonicalize(&canonical_path[0], link_path.c_str())) {
    return absl::FailedPreconditionError(
        absl::StrCat("Path '", link_path, "' invalid: ", GetLastOsError()));
  }
  canonical_path.resize(strlen(canonical_path.c_str()));

  // Remove existing file first
  if (DeleteFile(canonical_path.c_str()) == 0 &&
      GetLastError() != ERROR_FILE_NOT_FOUND) {
    return absl::FailedPreconditionError(absl::StrCat(
        "Cannot remove existing '", canonical_path, "': ", GetLastOsError()));
  }
  if (CreateSymbolicLink(canonical_path.c_str(), canonical_target.c_str(),
                         SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE)) {
    return absl::OkStatus();
  }
  // Symlink creation failed. Either "Developer Mode" is not enabled, or the
  // user does not have elevated privileges.
  // Try to create a hard link instead.
  if (CreateHardLink(canonical_path.c_str(), canonical_target.c_str(),
                     /*lpSecurityAttributes=*/nullptr)) {
    return absl::OkStatus();
  }
  // Not on NTFS, or on a network share without support for hard links, copy
  // the file instead.
  if (CopyFileA(canonical_target.c_str(), canonical_path.c_str(),
                /*bFailIfExists=*/true)) {
    return absl::OkStatus();
  }
  return absl::UnknownError(absl::StrCat("Copying '", canonical_target,
                                         "' to '", canonical_path,
                                         "' failed: ", GetLastOsError()));
#endif
}

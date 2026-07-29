// Copyright 2011-2026 Google LLC
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

#include "third_party/zynamics/binexport/testing.h"

#include <cstdlib>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>

#include "third_party/absl/log/log.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/zynamics/binexport/util/filesystem.h"

namespace security::binexport {

std::string GetTestTempPath(absl::string_view name) {
  // When using Bazel, the environment variable TEST_TMPDIR is guaranteed to be
  // set. The CMake build should set this up correctly, too.
  // See https://bazel.build/reference/test-encyclopedia for details.
  const char* test_tmpdir = getenv("TEST_TMPDIR");
  return JoinPath(test_tmpdir ? test_tmpdir : "", name);
}

std::string GetTestSourcePath(absl::string_view name) {
  const char* test_srcdir = getenv("TEST_SRCDIR");
  return JoinPath(test_srcdir ? test_srcdir : "", name);
}

std::string GetTestFileContents(absl::string_view path) {
  std::ifstream in_stream(std::string(path), std::ios_base::binary);
  std::ostringstream out_stream;
  out_stream << in_stream.rdbuf();
  if (!in_stream || !out_stream) {
    LOG(FATAL) << absl::StrCat("Error during read: ", path);
  }
  return out_stream.str();
}

void SetTestFileContents(absl::string_view path, absl::string_view content) {
  std::ofstream out_stream(std::string(path),
                           std::ios_base::trunc | std::ios_base::binary);
  if (!out_stream) {
    LOG(FATAL) << absl::StrCat("Failed to open file: ", path);
  }
  out_stream.write(content.data(), content.size());
  if (!out_stream) {
    LOG(FATAL) << absl::StrCat("Error during write: ", path);
  }
}

BinExport2 GetBinExportForTesting(absl::string_view name) {
  const std::string testfile = GetTestSourcePath(name);
  std::ifstream stream(testfile.c_str(), std::ios::in | std::ios::binary);
  BinExport2 proto;
  if (!proto.ParseFromIstream(&stream)) {
    LOG(FATAL) << absl::StrCat("Could not parse test file: ", testfile);
  }
  return proto;
}

}  // namespace security::binexport

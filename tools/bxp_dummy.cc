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

// Dummy command that does (mostly) nothing. It will print its positional
// arguments.

#include <vector>

#include "third_party/absl/status/status.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/str_format.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/zynamics/binexport/tools/command_util.h"
#include "third_party/zynamics/binexport/util/filesystem.h"

namespace security::binexport {
namespace {

absl::Status DummyMain(int argc, char* argv[]) {
  InstallFlagsUsageConfig(absl::StrCat("Do (mostly) nothing.\n",
                                       "Usage: ", Basename(argv[0]), " ..."));
  std::vector<char*> positional = ParseSubCommandLine("dummy", argc, argv);

  for (const auto& arg : positional) {
    absl::PrintF("arg: %s\n", arg);
  }
  return absl::OkStatus();
}

}  // namespace
}  // namespace security::binexport

int main(int argc, char* argv[]) {
  return security::binexport::InvokeMainAndReportErrors(
      security::binexport::DummyMain, argc, argv);
}

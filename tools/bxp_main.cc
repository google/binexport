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

// `bxp`, the entry point for BinExport command-line utilities.
// This is the main launcher binary that looks up a requested sub-command
// relative to its module path (i.e. where its executable is) and runs it.
//
// This works similar to how Git sub-commands work: executables whose name
// tart with "bxp-" will be considered as sub-commands.
//
// Usage: The following assumes the `binexport2dump` utility has been
// symlinked/renamed to `bxp-dump` and is located in the same directory as
// `bxp` itself.
// Dump a .BinExport file to stdout:
//   bxp dump <PATH/TO/BINEXPORT/FILE.BinExport>
//
// Generally, command-line processing of this launcher will handle built-in
// flags like `--help` up until the first non-flag argument. This argument
// is then treated as the name of the sub-command and will be invoked with
// the rest of the command-line. Each sub-command is expected to do its own
// flag parsing.

#include <string>
#include <vector>

#include "third_party/absl/flags/parse.h"
#include "third_party/absl/status/status.h"
#include "third_party/absl/status/statusor.h"
#include "third_party/absl/strings/match.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/zynamics/binexport/tools/command_util.h"
#include "third_party/zynamics/binexport/util/filesystem.h"
#include "third_party/zynamics/binexport/util/process.h"
#include "third_party/zynamics/binexport/util/status_macros.h"

namespace security::binexport {
namespace {

// Finds the first non-flag argument. This needs to be called before Abseil's
// command-line processing because Abseil automatically handles default flags
// and may exit the program for unknown arguments.
// Returns the index of the first non-flag argument, or argc if there is no such
// argument.
int FindSubCommand(int argc, char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    absl::string_view arg = argv[i];
    if (!absl::StartsWith(arg, "-")) {
      return i;
    }
  }
  return argc;
}

const std::string& GetLookupDir() {
  static const auto* lookup_dir =
      new std::string(Dirname(GetModuleFilename().value_or("")));
  return *lookup_dir;
}

constexpr absl::string_view kToolPrefix = "bxp-";

absl::StatusOr<std::string> ValidateCommand(absl::string_view command) {
  if (std::string command_exe =
          JoinPath(GetLookupDir(), absl::StrCat(kToolPrefix, command));
      FileExists(command_exe)) {
    return command_exe;
  }
  return absl::NotFoundError(absl::StrCat(
      "'", command, "' is not a binexport command. See 'bxp --help'."));
}

absl::Status BxpMain(int argc, char* argv[]) {
  InstallFlagsUsageConfig("Work with exported disassembly files.");

  int command_index = FindSubCommand(argc, argv);
  absl::ParseCommandLine(command_index, argv);
  if (command_index == argc) {
    return absl::InvalidArgumentError("No command given. Try '--help'.");
  }

  NA_ASSIGN_OR_RETURN(const std::string command_exe,
                      ValidateCommand(argv[command_index]));

  std::vector<std::string> command_args({command_exe});
  command_args.reserve(argc - command_index - 1);
  for (int i = command_index + 1; i < argc; ++i) {
    command_args.push_back(argv[i]);
  }

  // Communicate to the sub-command how it was invoked.
  std::string_view launch_command = command_exe;
  if (absl::StartsWith(launch_command, kToolPrefix)) {
    launch_command.remove_prefix(kToolPrefix.size());
  }
  SetEnvironmentVariable("_BXP_LAUNCH_CMD",
                         absl::StrCat(Basename(argv[0]), " ", launch_command));

  NA_RETURN_IF_ERROR(SpawnProcessAndWait(command_args).status());

  return absl::OkStatus();
}

}  // namespace
}  // namespace security::binexport

int main(int argc, char* argv[]) {
  return security::binexport::InvokeMainAndReportErrors(
      security::binexport::BxpMain, argc, argv);
}

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

#ifndef TOOLS_COMMAND_UTIL_H_
#define TOOLS_COMMAND_UTIL_H_

#include <functional>
#include <vector>

#include "third_party/absl/status/status.h"
#include "third_party/absl/strings/string_view.h"

namespace security::binexport {

// Installs Abseil Flags' library usage callbacks and sets a usage message.
// This needs to be done before any operation that may call one of the
// callbacks such as `absl::ParseCommandLine()` or `ParseSubCommandline()`
// below.
void InstallFlagsUsageConfig(absl::string_view usage_message);

// Returns the full command that was used to launch this sub-command. If not
// set by the launcher, returns "UNKNOWN".
// This is similar to Abseil's `absl::flags_internal::ProgramInvocationName()`.
std::string ProgramLaunchCommand();

// Parses command line arguments the same way as `absl::ParseCommandLine()`,
// setting the program name to indicate which command has been called.
// This function returns all the remaining positional arguments collected by
// `absl::ParseCommandLine()`.
// Note: The intended use is to pass argc and argv from a main function, so
//       the elements in returned vector are not owned. Hence, argc and argv
//       must out-live the use of the vector.
std::vector<char*> ParseSubCommandLine(absl::string_view command, int argc,
                                       char* argv[]);

// Calls a "main" function that returns a status and reports success or failure.
// This allows for unified error handling using `absl::Status`.
int InvokeMainAndReportErrors(
    const std::function<absl::Status(int argc, char* argv[])>& main, int argc,
    char* argv[]);

}  // namespace security::binexport

#endif  // TOOLS_COMMAND_UTIL_H_

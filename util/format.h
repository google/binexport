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

#ifndef UTIL_FORMAT_H_
#define UTIL_FORMAT_H_

#include <string>

#include "third_party/absl/time/time.h"
#include "third_party/zynamics/binexport/util/types.h"

namespace security::binexport {

// Returns a hexadecimal string representation of an address, suitable for log
// lines and display in UIs. The returned string will always be either 8 or 16
// uppercase hexadecimal characters, depending on whether the address is larger
// than 0xFFFFFFFF. In any case, the string is left padded with zeroes.
//
// Some examples:
//   FormatAddress(0x08)               => "00000008"
//   FormatAddress(0x59DE50)           => "0059DE50"
//   FormatAddress(0x00000001004940B0) => "00000001004940B0"
//   FormatAddress(0x7FF00000004926F4) => "7FF00000004926F4"
std::string FormatAddress(Address address);

// Returns an artificial name for the function at address, suitable for display
// in UIs. The returned string will start with "sub_" and uppercase hexadecmial
// characters. The address is _not_ formatted with leading zeroes, following
// what IDA Pro and Binary Ninja do.
std::string FormatFunctionName(Address address);

// Formats a duration given in seconds or as an absl::Duration into a human
// readable time based on hours. Maximum precision is 1/100th of a second.
//
// Example:
//   HumanReadableDuration(9045.123) => "2h 45m 0.12s"
std::string HumanReadableDuration(double seconds);
std::string HumanReadableDuration(absl::Duration duration);

}  // namespace security::binexport

#endif  // UTIL_FORMAT_H_

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

#include "third_party/zynamics/binexport/util/format.h"

#include <cstdint>
#include <string>

#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/str_format.h"
#include "third_party/absl/time/time.h"
#include "third_party/zynamics/binexport/util/types.h"

namespace security::binexport {

std::string FormatAddress(Address address) {
  if (address <= 0xFFFFFFFF) {
    return absl::StrFormat("%08X", address);
  }
  return absl::StrFormat("%016X", address);
}

std::string FormatFunctionName(Address address) {
  return absl::StrFormat("sub_%X", address);
}

std::string HumanReadableDuration(double seconds) {
  std::string result;

  absl::Duration remainder;
  int64_t full_hours =
      absl::IDivDuration(absl::Seconds(seconds), absl::Hours(1), &remainder);
  int64_t full_minutes =
      absl::IDivDuration(remainder, absl::Minutes(1), &remainder);
  int64_t full_seconds =
      absl::IDivDuration(remainder, absl::Seconds(1), &remainder);
  absl::Duration full = remainder;

  bool need_space = false;
  if (full_hours > 0) {
    absl::StrAppend(&result, full_hours, "h");
    need_space = true;
  }
  if (full_minutes > 0) {
    absl::StrAppend(&result, (need_space ? " " : ""), full_minutes, "m");
    need_space = true;
  }
  if (full_seconds > 0 || full > absl::ZeroDuration()) {
    absl::StrAppend(&result, (need_space ? " " : ""), full_seconds);
    if (full > absl::ZeroDuration()) {
      absl::StrAppend(&result, ".", absl::ToInt64Milliseconds(full) / 10);
    }
    absl::StrAppend(&result, "s");
  }
  if (result.empty()) {
    absl::StrAppend(&result, "0s");
  }
  return result;
}

std::string HumanReadableDuration(absl::Duration duration) {
  return HumanReadableDuration(absl::ToDoubleSeconds(duration));
}

}  // namespace security::binexport

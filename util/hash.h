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

#ifndef UTIL_HASH_H_
#define UTIL_HASH_H_

#include <string>

#include "third_party/zynamics/binexport/util/types.h"

// Calculates a general-purpose, non-cryptographic hash over the contents of a
// string.
// TODO(cblichmann): accept an absl::string_view instead.
uint32_t GetSdbmHash(const std::string& data);

#endif  // UTIL_HASH_H_

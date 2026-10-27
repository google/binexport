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

#ifndef UTIL_UNICODE_H_
#define UTIL_UNICODE_H_

#include <string>

#include "third_party/absl/strings/string_view.h"

namespace security::binexport {

// Converts raw bytes holding UTF-16LE code units to UTF-8. The input usually
// comes straight from the binary being analyzed, so it can be arbitrary bytes.
// This function never fails and always returns valid UTF-8:
// - Unpaired surrogates are replaced with U+FFFD.
// - A trailing odd byte is replaced with U+FFFD.
// - U+0000 is kept as a NUL byte.
std::string Utf16LeToUtf8(absl::string_view utf16le);

// Returns a copy of data where every byte that is not printable ASCII
// (0x20-0x7E) or one of '\t', '\n', '\f', '\r' is replaced with a space. The
// result has the same size as the input.
std::string ReplaceNonPrintableAscii(absl::string_view data);

}  // namespace security::binexport

#endif  // UTIL_UNICODE_H_

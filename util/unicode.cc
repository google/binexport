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

#include "third_party/zynamics/binexport/util/unicode.h"

#include <cstddef>
#include <cstdint>
#include <string>

#include "third_party/absl/strings/ascii.h"
#include "third_party/absl/strings/string_view.h"

namespace security::binexport {
namespace {

constexpr char32_t kReplacementCharacter = 0xFFFD;

bool IsHighSurrogate(char16_t unit) { return unit >= 0xD800 && unit <= 0xDBFF; }
bool IsLowSurrogate(char16_t unit) { return unit >= 0xDC00 && unit <= 0xDFFF; }

void AppendUtf8(char32_t code_point, std::string* out) {
  if (code_point < 0x80) {
    out->push_back(static_cast<char>(code_point));
  } else if (code_point < 0x800) {
    out->push_back(static_cast<char>(0xC0 | (code_point >> 6)));
    out->push_back(static_cast<char>(0x80 | (code_point & 0x3F)));
  } else if (code_point < 0x10000) {
    out->push_back(static_cast<char>(0xE0 | (code_point >> 12)));
    out->push_back(static_cast<char>(0x80 | ((code_point >> 6) & 0x3F)));
    out->push_back(static_cast<char>(0x80 | (code_point & 0x3F)));
  } else {
    out->push_back(static_cast<char>(0xF0 | (code_point >> 18)));
    out->push_back(static_cast<char>(0x80 | ((code_point >> 12) & 0x3F)));
    out->push_back(static_cast<char>(0x80 | ((code_point >> 6) & 0x3F)));
    out->push_back(static_cast<char>(0x80 | (code_point & 0x3F)));
  }
}

}  // namespace

std::string Utf16LeToUtf8(absl::string_view utf16le) {
  // Assemble code units byte by byte, so this works regardless of host byte
  // order and alignment of the input.
  const size_t num_units = utf16le.size() / 2;
  auto unit_at = [utf16le](size_t i) -> char16_t {
    return static_cast<char16_t>(
        static_cast<uint8_t>(utf16le[2 * i]) |
        (static_cast<uint8_t>(utf16le[2 * i + 1]) << 8));
  };

  std::string result;
  result.reserve(num_units);
  for (size_t i = 0; i < num_units; ++i) {
    const char16_t unit = unit_at(i);
    char32_t code_point = unit;
    if (IsHighSurrogate(unit)) {
      const char16_t next = i + 1 < num_units ? unit_at(i + 1) : 0;
      if (IsLowSurrogate(next)) {
        code_point = 0x10000 + ((unit - 0xD800) << 10) + (next - 0xDC00);
        ++i;
      } else {
        code_point = kReplacementCharacter;
      }
    } else if (IsLowSurrogate(unit)) {
      code_point = kReplacementCharacter;
    }
    AppendUtf8(code_point, &result);
  }
  // A trailing odd byte is a truncated code unit.
  if (utf16le.size() % 2 != 0) {
    AppendUtf8(kReplacementCharacter, &result);
  }
  return result;
}

std::string ReplaceNonPrintableAscii(absl::string_view data) {
  std::string result(data);
  for (char& c : result) {
    const auto byte = static_cast<uint8_t>(c);
    const bool keep = absl::ascii_isprint(byte) || byte == '\t' ||
                      byte == '\n' || byte == '\f' || byte == '\r';
    if (!keep) {
      c = ' ';
    }
  }
  return result;
}

}  // namespace security::binexport

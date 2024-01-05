# Copyright 2011-2024 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Utility library for implementing sub-commands
add_library(bxp_command_util
 command_util.h
 command_util.cc
 ../version.h
 ${CMAKE_CURRENT_BINARY_DIR}/../version.cc
)
add_library(bxp::command_util ALIAS bxp_command_util)
target_link_libraries(bxp_command_util PRIVATE
 absl::flags_parse
 absl::status
 absl::str_format
 binexport_base
 binexport_shared
)

# Entry point for BinExport command-line utilities.
add_executable(bxp bxp_main.cc)
target_link_libraries(bxp PRIVATE
  absl::flags_parse
  absl::status
  absl::str_format
  binexport_base
  binexport_shared
  bxp::command_util
)
install(TARGETS bxp RUNTIME DESTINATION binexport-prefix)

# Dummy command that does (mostly) nothing. Used for tests.
add_executable(bxp-dummy bxp_dummy.cc)
target_link_libraries(bxp-dummy PRIVATE
  absl::flags_parse
  absl::status
  absl::str_format
  binexport_base
  binexport_shared
  bxp::command_util
)

# Dumps the disassembly from BinExport files.
add_executable(binexport2dump binexport2dump.cc)
target_link_libraries(binexport2dump
  absl::flat_hash_map
  absl::hash
  absl::log_initialize
  absl::str_format
  absl::time
  bxp::command_util
  binexport_base
  binexport_shared
)
install(TARGETS binexport2dump RUNTIME DESTINATION binexport-prefix)

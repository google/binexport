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

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(BINEXPORT_TOP_LEVEL TRUE)
endif()

# If unset, force a default value for this standard option
if(NOT BUILD_TESTING)
  set(BUILD_TESTING OFF)
endif()

option(BINEXPORT_BUILD_TESTING
  "If ON, this will build all of BinExport's own tests" ${BINEXPORT_TOP_LEVEL})
option(BINEXPORT_BUILD_BENCHMARK
       "If this and BINEXPORT_BUILD_TESTING is ON, build benchmark tests" OFF)

option(BINEXPORT_ENABLE_IDAPRO "Build the IDA Pro plugins" ON)
option(BINEXPORT_ENABLE_BINARYNINJA "Build the Binary Ninja plugin" ON)

set(BINEXPORT_BINARYNINJA_CHANNEL "stable" CACHE
    STRING "Binary Ninja channel, either 'stable' or 'dev'")

option(BINEXPORT_BINARYNINJA_LATEST "Use the latest Binary Ninja API from GitHub" OFF)

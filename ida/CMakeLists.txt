# Copyright 2011-2026 Google LLC
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

# Code shared with the BinDiff plugin
add_library(binexport_plugin_shared STATIC
  begin_idasdk.inc
  digest.cc
  digest.h
  end_idasdk.inc
  log_sink.cc
  log_sink.h
  names.cc
  names.h
  plugin.h
  ui.cc
  ui.h
  util.cc
  util.h
)
target_include_directories(binexport_plugin_shared
  PUBLIC $<TARGET_PROPERTY:idasdk::plugin,INTERFACE_INCLUDE_DIRECTORIES>
)
target_compile_definitions(binexport_plugin_shared
  PUBLIC $<TARGET_PROPERTY:idasdk::plugin,INTERFACE_COMPILE_DEFINITIONS>
         USE_DANGEROUS_FUNCTIONS
         USE_STANDARD_FILE_FUNCTIONS
)
target_link_libraries(binexport_plugin_shared
  PUBLIC absl::btree
         absl::log
         absl::log_entry
         absl::log_sink
         absl::optional
         absl::span
         absl::status
         absl::status_macros
         absl::statusor
         absl::strings
         absl::time
         binexport_base
         binexport_core
         ida_addon_base
)

add_library(binexport_ida OBJECT
  arm.cc
  arm.h
  dalvik.cc
  dalvik.h
  flow_analysis.cc
  flow_analysis.h
  generic.cc
  generic.h
  main_plugin.cc
  main_plugin.h
  metapc.cc
  metapc.h
  mips.cc
  mips.h
  ppc.cc
  ppc.h
)
target_link_libraries(binexport_ida
  PUBLIC absl::btree
         absl::core_headers
         absl::flat_hash_map
         absl::flat_hash_set
         absl::hash
         absl::log
         absl::log_initialize
         absl::log_sink
         absl::memory
         absl::node_hash_map
         absl::node_hash_set
         absl::optional
         absl::status
         absl::status_macros
         absl::strings
         absl::time
         binexport_core
         binexport_plugin_shared
)

ida_add_plugin(${binexport_ida_plugin_name})
target_link_libraries(${binexport_ida_plugin_name}
  PUBLIC binexport_ida
         binexport_plugin_shared
)
if(WIN32)
  target_link_libraries(${binexport_ida_plugin_name}
    PUBLIC crypt32.lib
           delayimp.lib  # Helper for /DELAYLOAD
           secur32.lib
           shlwapi.lib
           ws2_32.lib
           wldap32.lib
  )
  # See b/206656063 for context
  set_target_properties(${binexport_ida_plugin_name} PROPERTIES
    LINK_FLAGS /DELAYLOAD:dbghelp.dll
  )
endif()
set_target_properties(${binexport_ida_plugin_name} PROPERTIES
  POSITION_INDEPENDENT_CODE ON
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/ida"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/ida"
)

if(BUILD_TESTING AND BINEXPORT_BUILD_TESTING)
  add_library(binexport_ida_test_util STATIC
    ida_test_util.cc
    ida_test_util.h
  )
  target_link_libraries(binexport_ida_test_util
    PUBLIC absl::btree
           absl::flat_hash_map
           absl::no_destructor
           absl::span
           absl::strings
           binexport_test_base
           binexport_plugin_shared
           binexport_shared
  )

  add_executable(ida_test
    ida_test.cc
  )
  target_link_libraries(ida_test
    PUBLIC absl::log
           absl::status
           absl::status_matchers
           absl::strings
           binexport_test_base
           binexport_core
           binexport_ida
           binexport_plugin_shared
           binexport_shared
           binexport_ida_test_util
  )
  gtest_discover_tests(ida_test)
endif()

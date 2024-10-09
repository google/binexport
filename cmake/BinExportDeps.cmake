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

function(binexport_check_target target)
  if(NOT TARGET ${target})
    message(FATAL_ERROR
      "Compiling ${PROJECT_NAME} requires a ${target} CMake "
      "target in your project")
  endif()
endfunction()

include(FetchContent)

if(BUILD_TESTING AND BINEXPORT_BUILD_TESTING)
  # Googletest (needs to come after Abseil due to C++ standard propagation)
  FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/5bcb2d78a16edd7110e72ef694d229815aa29542.zip  # 2024-07-24
    URL_HASH SHA256=55d80e3e4b3ae63c4b377895babc2ecd17834aedfc0e6cb8aedb5c7adb97defd
  )
  FetchContent_MakeAvailable(googletest)
  binexport_check_target(gtest)
  binexport_check_target(gtest_main)
  binexport_check_target(gmock)

  if(BINEXPORT_BUILD_BENCHMARK)
    # Benchmark
    FetchContent_Declare(benchmark
      URL https://github.com/google/benchmark/archive/ea71a14891474943fc1f34d359f9e0e82476ffe1.zip  # 2024-01-09
      URL_HASH SHA256=d5b0b5471c42e8e431f08ccc52db4acff609d927286bde04e2ac93aff3699ca1
    )
    set(BENCHMARK_CXX_STANDARD ${CMAKE_CXX_STANDARD} CACHE STRING "" FORCE)
    set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
    set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
    set(BENCHMARK_USE_BUNDLED_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(benchmark)
    binexport_check_target(benchmark::benchmark)
  endif()
endif()

# Abseil
FetchContent_Declare(absl
  URL https://github.com/abseil/abseil-cpp/archive/7e5c339b1aa790ae03cc614a8d7626d5b4831891.zip  # 2024-07-25 (RC2)
  URL_HASH SHA256=2ad33d08a720fa3a67ec12bd8cf9846da7ed53045163d69047856cc671a0cbe5
)
set(ABSL_CXX_STANDARD ${CMAKE_CXX_STANDARD} CACHE STRING "" FORCE)
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE)
set(ABSL_USE_EXTERNAL_GOOGLETEST ON CACHE BOOL "" FORCE)
set(ABSL_FIND_GOOGLETEST OFF CACHE BOOL "" FORCE)
if(BUILD_TESTING AND BINEXPORT_BUILD_TESTING)
  # Need this for absl::status_matchers to be available
  set(ABSL_BUILD_TESTING ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(absl)
binexport_check_target(absl::core_headers)
if(BUILD_TESTING AND BINEXPORT_BUILD_TESTING)
  # Fix a bug in Abseil's CMake build files
  target_link_libraries(absl_no_destructor_test PUBLIC gmock)
endif()

# Protocol Buffers
FetchContent_Declare(protobuf
  GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  GIT_TAG        v27.2 # 2024-05-25 (must be a branch for GIT_SHALLOW to work)
  GIT_SUBMODULES third_party/jsoncpp
  GIT_SHALLOW    TRUE
)
set(protobuf_ABSL_PROVIDER "package" CACHE STRING "" FORCE)
set(protobuf_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(protobuf_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(protobuf_INSTALL OFF CACHE BOOL "" FORCE)
set(protobuf_WITH_ZLIB OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(protobuf)
binexport_check_target(protobuf::libprotobuf)
binexport_check_target(protobuf::protoc)
target_include_directories(utf8_validity PUBLIC
  "${BINEXPORT_BINARY_DIR}/src_include"
  "${protobuf_SOURCE_DIR}"
)
set(Protobuf_INCLUDE_DIR "${protobuf_SOURCE_DIR}/src" CACHE INTERNAL "")
set(Protobuf_LIBRARIES protobuf::libprotobuf CACHE INTERNAL "")
find_package(Protobuf 3.14 REQUIRED) # Make protobuf_generate_cpp available

# Binary Ninja API
if(BINEXPORT_ENABLE_BINARYNINJA)
  if(BINEXPORT_BINARYNINJA_LATEST)
    set(_binexport_binaryninjacore_suffix "_latest")
    set(_binexport_binaryninja_git_tag "dev")
  else()
    if(BINEXPORT_BINARYNINJA_CHANNEL STREQUAL "stable")
      set(_binexport_binaryninjacore_suffix "_stable")
      set(_binexport_binaryninja_git_tag
          "967ffc9bd705f6820c4dbfe97f301d52facb1417") # 2024-08-14 v4.1.5902
    else()
      set(_binexport_binaryninjacore_suffix "")
      set(_binexport_binaryninja_git_tag
          "de23abd02ab27b6623656ed04e9b62d4dc1361b7") # 2024-08-24
    endif()
  endif()
  FetchContent_Declare(binaryninjaapi
    GIT_REPOSITORY https://github.com/Vector35/binaryninja-api.git
    GIT_TAG        ${_binexport_binaryninja_git_tag}
  )
  FetchContent_GetProperties(binaryninjaapi)
  if(NOT binaryninjaapi_POPULATED)
    FetchContent_Populate(binaryninjaapi)  # For binaryninjaapi_SOURCE_DIR
  endif()
  if(BINEXPORT_BINARYNINJA_LATEST)
    if(WIN32)
      find_program(POWERSHELL_PATH NAMES powershell pwsh)
      set(_stub_command "${POWERSHELL_PATH} ${BINEXPORT_SOURCE_DIR}/binaryninja/stubs/regenerate-api-stubs.ps1")
    else()
      set(_stub_command "${BINEXPORT_SOURCE_DIR}/binaryninja/stubs/regenerate-api-stubs.sh")
    endif()
    add_custom_command(
      OUTPUT ${BINEXPORT_SOURCE_DIR}/binaryninja/stubs/binaryninjacore${_binexport_binaryninjacore_suffix}.cc
      COMMAND ${_stub_command} ${binaryninjaapi_SOURCE_DIR} latest
      DEPENDS ${binaryninjaapi_SOURCE_DIR}/binaryninjacore.h
      COMMENT "Updating stubs"
    )
  endif()
  add_library(binaryninjacore SHARED
    ${BINEXPORT_SOURCE_DIR}/binaryninja/stubs/binaryninjacore${_binexport_binaryninjacore_suffix}.cc
  )
  set_target_properties(binaryninjacore PROPERTIES
    SOVERSION 1
  )
  target_include_directories(binaryninjacore PRIVATE
    "${binaryninjaapi_SOURCE_DIR}"
  )
  set(CORE_LIBRARY binaryninjacore)
  set(BN_CORE_LIBRARY "${CORE_LIBRARY}")
  set(HEADLESS TRUE)
  if(binaryninjaapi_POPULATED)
    add_subdirectory("${binaryninjaapi_SOURCE_DIR}" "${binaryninjaapi_BINARY_DIR}")
    if(MSVC)
      target_compile_options(binaryninjaapi PRIVATE
        /wd4005  # macro redefinition (NOMINMAX, _CRT_SECURE_NO_WARNINGS)
      )
    endif()
  endif()
  binexport_check_target(binaryninjaapi)
  add_library(BinaryNinja::API ALIAS binaryninjaapi)
endif()

# Boost
set(Boost_NO_SYSTEM_PATHS TRUE)
if(NOT BOOST_ROOT)
  set(BOOST_ROOT "${BINEXPORT_SOURCE_DIR}/boost_parts")
endif()
find_package(Boost 1.83 REQUIRED)

find_package(Git)
if(BINEXPORT_ENABLE_IDAPRO)
  find_package(IdaSdk REQUIRED)
endif()

#set(BUILD_TESTING ${BINEXPORT_SAVE_BUILD_TESTING})


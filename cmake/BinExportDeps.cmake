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
  URL https://github.com/abseil/abseil-cpp/archive/e4c43850ad008b362b53622cb3c88fd915d8f714.zip # 2025-05-23
  URL_HASH SHA256=00d20e61e2d5dfe86dee88d70897fcdbe593696dfc8ac162873b5fce718557ae
)
set(ABSL_CXX_STANDARD ${CMAKE_CXX_STANDARD} CACHE STRING "" FORCE)
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE)
set(ABSL_USE_EXTERNAL_GOOGLETEST ON CACHE BOOL "" FORCE)
set(ABSL_FIND_GOOGLETEST OFF CACHE BOOL "" FORCE)
if(MSVC)
  # Link MSVCRT statically for abseil
  set(ABSL_MSVC_STATIC_RUNTIME ON CACHE BOOL "" FORCE)
endif()
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
  URL https://github.com/protocolbuffers/protobuf/archive/refs/tags/v31.0.tar.gz # 2025-05-14
  URL_HASH SHA256=2b695cb1eaef8e173f884235ee6d55f57186e95d89ebb31361ee55cb5fd1b996
)
set(protobuf_ABSL_PROVIDER "package" CACHE STRING "" FORCE)
set(protobuf_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(protobuf_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(protobuf_INSTALL OFF CACHE BOOL "" FORCE)
set(protobuf_WITH_ZLIB OFF CACHE BOOL "" FORCE)
if(MSVC)
  # Link MSVCRT statically for protoc
  set(protobuf_MSVC_STATIC_RUNTIME ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(protobuf)
binexport_check_target(protobuf::libprotobuf)
binexport_check_target(protobuf::protoc)
target_include_directories(utf8_validity PUBLIC
  "${BINEXPORT_BINARY_DIR}/src_include"
  "${protobuf_SOURCE_DIR}"
)
target_include_directories(libprotobuf PUBLIC
  "${protobuf_SOURCE_DIR}/third_party/utf8_range"
)
set(Protobuf_INCLUDE_DIR "${protobuf_SOURCE_DIR}/src" CACHE INTERNAL "")
set(Protobuf_LIBRARIES protobuf::libprotobuf CACHE INTERNAL "")
find_package(Protobuf 3.14 REQUIRED) # Make protobuf_generate_cpp available

# Binary Ninja API
if(BINEXPORT_ENABLE_BINARYNINJA)
  if(BINEXPORT_BINARYNINJA_CHANNEL STREQUAL "stable")
    set(_binexport_binaryninjacore_suffix "_stable")
    set(_binexport_binaryninja_git_tag
        "13a6e9ab06a3384b8c6ea6c2a0654d97482b369f") # 2025-05-21 v5.0.7486-stable
  else()
    set(_binexport_binaryninjacore_suffix "")
    set(_binexport_binaryninja_git_tag
        "8ba8388e12ab32ad937c4514f7a907d2530f1ef8") # 2025-05-31
  endif()
  FetchContent_Declare(binaryninjaapi
    GIT_REPOSITORY https://github.com/Vector35/binaryninja-api.git
    GIT_TAG        ${_binexport_binaryninja_git_tag}
  )
  set(CORE_LIBRARY binaryninjacore)
  set(BN_CORE_LIBRARY "${CORE_LIBRARY}")
  set(HEADLESS TRUE)
  FetchContent_MakeAvailable(binaryninjaapi)
  add_library(binaryninjacore SHARED
    binaryninja/stubs/binaryninjacore${_binexport_binaryninjacore_suffix}.cc
  )
  set_target_properties(binaryninjacore PROPERTIES
    SOVERSION 1
  )
  target_include_directories(binaryninjacore PRIVATE
    "${binaryninjaapi_SOURCE_DIR}"
  )
  if(MSVC)
    target_compile_options(binaryninjaapi PRIVATE
      /wd4005  # macro redefinition (NOMINMAX, _CRT_SECURE_NO_WARNINGS)
    )
  endif()
  binexport_check_target(binaryninjaapi)
  add_library(BinaryNinja::API ALIAS binaryninjaapi)
endif()

# Boost
# Set include path, as the FindBoost module is deprecated as of CMake 4.0.
set(Boost_INCLUDE_DIR "${BINEXPORT_SOURCE_DIR}/boost_parts")

find_package(Git)
if(BINEXPORT_ENABLE_IDAPRO)
  find_package(IdaSdk REQUIRED)
endif()

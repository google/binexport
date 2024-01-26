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

# Abseil
FetchContent_Declare(absl
  URL https://github.com/abseil/abseil-cpp/archive/ae87791869cacbc125aa708108c4721e51ff703d.zip  # 2023-06-08
  URL_HASH SHA256=fbe050daabadda2297cea9ace55ccde48e3994887bc0b1e6c7330f1a97ee071b
)
set(ABSL_CXX_STANDARD ${CMAKE_CXX_STANDARD} CACHE STRING "" FORCE)
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE)
set(ABSL_USE_EXTERNAL_GOOGLETEST ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(absl)
# Protobuf's utf8_range fork insists on this being set
set(ABSL_ROOT_DIR "${absl_SOURCE_DIR}" CACHE STRING "" FORCE)
binexport_check_target(absl::core_headers)

if(BUILD_TESTING AND BINEXPORT_BUILD_TESTING)
  # Googletest (needs to come after Abseil due to C++ standard propagation)
  FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/334704df263b480a3e9e7441ed3292a5e30a37ec.zip  # 2023-06-06
    URL_HASH SHA256=a217118c2c36a3632b594af7ff98111a65bb2b980b726a7fa62305e02a998440
  )
  FetchContent_MakeAvailable(googletest)
  binexport_check_target(gtest)
  binexport_check_target(gtest_main)
  binexport_check_target(gmock)

  if(BINEXPORT_BUILD_BENCHMARK)
    # Benchmark
    FetchContent_Declare(benchmark
      URL https://github.com/google/benchmark/archive/604f6fd3f4b34a84ec4eb4db81d842fa4db829cd.zip  # 2023-05-30
      URL_HASH SHA256=342705876335bf894147e052d0dac141fe15962034b41bef5aa59c4b279ca89c
    )
    set(BENCHMARK_CXX_STANDARD ${CMAKE_CXX_STANDARD} CACHE STRING "" FORCE)
    set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
    set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
    set(BENCHMARK_USE_BUNDLED_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(benchmark)
    binexport_check_target(benchmark::benchmark)
  endif()
endif()

# Protocol Buffers
FetchContent_Declare(protobuf
  GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  GIT_TAG        v23.4 # 2023-07-05 (must be a branch for GIT_SHALLOW to work)
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
  if(BINEXPORT_BINARYNINJA_CHANNEL STREQUAL "stable")
    set(_binexport_binaryninjacore_suffix "_stable")
    set(_binexport_binaryninja_git_tag
        "0d57172be4fda0b7015db697b5353a12d03932af") # 2023-09-19 v3.5.4526
  else()
    set(_binexport_binaryninjacore_suffix "")
    set(_binexport_binaryninja_git_tag
        "6e2b374dece03f6fb48a1615fa2bfee809ec2157") # 2023-09-24
  endif()
  FetchContent_Declare(binaryninjaapi
    GIT_REPOSITORY https://github.com/Vector35/binaryninja-api.git
    GIT_TAG        ${_binexport_binaryninja_git_tag}
  )
  FetchContent_GetProperties(binaryninjaapi)
  if(NOT binaryninjaapi_POPULATED)
    FetchContent_Populate(binaryninjaapi)  # For binaryninjaapi_SOURCE_DIR
  endif()
  add_library(binaryninjacore SHARED
    binaryninja/stubs/binaryninjacore${_binexport_binaryninjacore_suffix}.cc
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

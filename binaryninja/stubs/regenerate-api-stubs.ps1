<#
    Copyright 2011-2024 Google LLC

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        https://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
#>

# Updates the Binary Ninja API stub file

# Exit on error
$ErrorActionPreference = "Stop"

# Function to get the canonical path
function Get-CanonicalPath {
    param (
        [string]$file
    )
    $file = Resolve-Path $file -ErrorAction Stop
    $limit = 0
    while ((Test-Path -PathType Leaf $file) -and ($limit -lt 1000)) {
        $file = (Get-Item $file).Target
        $limit++
    }
    return (Get-Item $file).FullName
}

$THIS = Split-Path $PSCommandPath -leaf

if (-not $args[0]) {
    Write-Host "usage: $THIS PATH_TO_BINARYNINJA_API [stable]"
    Write-Host "set 'stable' to update the stable stubs"
    exit 1
}

$SUFFIX = switch ($args[1]) {
    "stable" { "_stable" }
    "latest" { "_latest" }
    default { "" }
}

$BINARYNINJA_API_SRC = Get-CanonicalPath $args[0]

Set-Location $PSScriptRoot

$header = @"
// Copyright 2011-2024 Google LLC
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

// This file is auto-generated. To regenerate, run the "$THIS" script.

#include <cstdint>
#include <cstddef>

// clang-format off
#include "exceptions.h"  // NOLINT
#define BINARYNINJACORE_LIBRARY
#include "binaryninjacore.h"  // NOLINT
// clang-format on

extern "C" {
"@

$footer = @"
}  // extern "C"
"@

# The following extracts all C API functions from the Binary Ninja API
# and creates empty stub functions for them. This is later compiled
# into an API compatible library that is used to link against. This
# avoids having to use install a copy of Binary Ninja on the machine
# that builds BinExport.
# Note that the script line below can be replaced with a small Clang
# tool to make it more robust.
$functions = Get-Content "${BINARYNINJA_API_SRC}/binaryninjacore.h" |
    foreach {$_ -replace "\s+// .*", "" } |
    clang-format --style='{BasedOnStyle: Google, Language: Cpp, ColumnLimit: 100000}' |
    Select-String '^BINARYNINJACOREAPI' |
    ForEach-Object {
        $_ -replace '(BINARYNINJACOREAPI void .*)\;$', '$1 {}' -replace '(BINARYNINJACOREAPI .*)\;$', '$1 { return {}; }'
    }

$functions = ,$header + $functions + ,$footer
$functions | Out-String | % Trim | Set-Content -Path "binaryninjacore${SUFFIX}.cc"

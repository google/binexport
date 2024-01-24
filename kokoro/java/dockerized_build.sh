#!/bin/bash

# Fail on error, display commands being run
set -ex

src_dir=/build/src/git
out_dir=/build/out
deps_dir=/build/deps

trap "chmod -R ugo+rX \"${out_dir}\"" EXIT

cd "${src_dir}/binexport/java"
export GHIDRA_INSTALL_DIR="${deps_dir}/ghidra"
gradle \
  --warning-mode all

mv dist/*.zip "${out_dir}/ghidra_BinExport.zip"

#!/bin/bash
#
# Decrypts the checked-in IDA SDK. In order to not leak the passphrase in the
# workflow log, it is set as an environment variable before being passed to
# GPG.

set -e

gpg --quiet --batch --yes --decrypt \
  "--passphrase=${IDASDK_SECRET}" \
  --output "${GITHUB_WORKSPACE}/build/idasdk_teams82.zip" \
  "${GITHUB_WORKSPACE}/ida/idasdk/idasdk_teams82.zip.gpg"

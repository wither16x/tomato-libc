#!/bin/bash

set -e

# the prefix must contains:
# usr/
# usr/include/
# usr/lib/
PREFIX="$1"

cp -v sysroot/usr/include/*.h "$PREFIX"/usr/include/
cp -v sysroot/usr/lib/* "$PREFIX"/usr/lib/
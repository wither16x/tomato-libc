#!/bin/bash

set -e

mkdir -p sysroot
mkdir -p sysroot/usr

mkdir -p sysroot/usr/include
for file in include/*.h; do
        if [ -f "$file" ]; then
                cp -v "$file" "sysroot/usr/$file"
        fi
done

mkdir -p sysroot/usr/lib
cp -v build/crt0.o sysroot/usr/lib/crt0.o
cp -v build/libc.a sysroot/usr/lib/libc.a
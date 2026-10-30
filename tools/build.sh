#!/bin/sh
# SPDX-License-Identifier: BSD-2-Clause
# Copyright (c) 2026 FVOS contributors
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
mkdir -p "$root/out"
cd "$root/src"                          # include paths resolve from src/
fasm os.asm "$root/out/os.img"

#!/bin/sh
# SPDX-License-Identifier: BSD-2-Clause
# Copyright (c) 2026 FVOS contributors
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
shot="$root/out/shot.ppm"
rm -f "$shot"
( sleep 3; echo "screendump $shot"; sleep 1; echo quit ) | \
  qemu-system-x86_64 -drive format=raw,file="$root/out/os.img" \
    -vga std -m 256M -no-reboot -display none -monitor stdio >/dev/null
# PPM P6 header for 1024x768 is 16 bytes; first pixel follows as R,G,B
px=$(dd if="$shot" bs=1 skip=16 count=3 2>/dev/null | od -An -tx1 | tr -d ' \n')
[ "$px" = "203050" ] && echo "smoke: PASS" || { echo "smoke: FAIL (got $px)"; exit 1; }

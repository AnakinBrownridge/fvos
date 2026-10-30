#!/bin/sh
# SPDX-License-Identifier: BSD-2-Clause
# Copyright (c) 2026 FVOS contributors
root=$(cd "$(dirname "$0")/.." && pwd)
exec qemu-system-x86_64 -drive format=raw,file="$root/out/os.img" \
  -vga std -m 256M -no-reboot -no-shutdown -d cpu_reset -D "$root/out/qemu.log"

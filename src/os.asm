; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; os.asm - the ONLY file fasm is invoked on. Everything is textual include.
format binary
include 'config.inc'
include 'boot/stage1.inc'       ; org BASE, exactly 512 bytes
include 'boot/stage2.inc'       ; lands at STAGE2 (0x7E00)
include 'boot/vbe.inc'
include 'kernel/gfx.inc'
include 'kernel/main.inc'
IMAGE_END:                      ; used by stage1 to compute the sector count
align 512                       ; pad to whole sectors for INT 13h

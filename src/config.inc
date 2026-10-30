; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; config.inc - memory map, requested video mode, BootInfo ABI.
; Keep in sync with docs/memory-map.md and docs/boot-abi.md.

BASE      = 0x7C00
STAGE2    = 0x7E00              ; stage1 loads image[512..] here, contiguous
BOOTINFO  = 0x0500              ; kernel-visible handoff struct
PML4      = 0x1000
PDPT      = 0x2000
PD        = 0x3000              ; 4 pages: identity-maps 4 GiB with 2 MiB pages
KSTACK    = 0x90000

VBE_SEG   = 0x7000              ; scratch segment for VBE blocks (phys 0x70000)
VBE_INFO  = 0x0000              ; 512B VbeInfoBlock
VBE_MODE  = 0x0200              ; 256B ModeInfoBlock

WANT_W    = 1024
WANT_H    = 768
WANT_BPP  = 32

; BootInfo layout (all dwords)
BI_FB     = 0                   ; LFB physical address
BI_PITCH  = 4
BI_W      = 8
BI_H      = 12
BI_BPP    = 16
BI_MODE   = 20

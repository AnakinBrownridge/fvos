; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; stage1.inc - 512-byte MBR. Loads the rest of the image via INT 13h LBA.
use16
org BASE
stage1:
    cli
    xor  ax,ax
    mov  ds,ax
    mov  es,ax
    mov  ss,ax
    mov  sp,BASE
    sti
    mov  si,dap                 ; DL = BIOS boot drive, untouched
    mov  ah,0x42                ; extended LBA read
    int  0x13
    jc   .hang
    jmp  0:STAGE2
.hang:
    hlt
    jmp  .hang

dap:                            ; sector count is computed at assemble time
    db 16,0
    dw (IMAGE_END - STAGE2 + 511) / 512
    dw STAGE2,0                 ; offset:segment
    dq 1                        ; start LBA

    db 510-($-BASE) dup 0
    db 0x55,0xAA
if $ <> STAGE2
    err 'stage1 must be exactly 512 bytes'
end if
; Keep the image under ~127 sectors (safe per-call INT 13h limit).
; Past that, loop the DAP.

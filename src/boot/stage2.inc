; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; stage2.inc - A20, VBE mode set, real -> PM32 -> long mode, jump to kmain.
use16
stage2:
    in   al,0x92                ; fast A20 via System Control Port A
    or   al,2
    and  al,0xFE                ; bit0 = fast reset: never set it
    out  0x92,al

    call vbe_setup              ; must run in real mode (INT 10h)
    jc   .novbe

    cli
    lgdt [gdt_desc]
    mov  eax,cr0
    or   al,1                   ; PE
    mov  cr0,eax
    jmp  0x08:pm32

.novbe:
    mov  ax,0x0E00+'V'          ; teletype 'V' = VBE failed
    xor  bx,bx
    int  0x10
.hang:
    hlt
    jmp  .hang

use32
pm32:
    mov  ax,0x10
    mov  ds,ax
    mov  es,ax
    mov  ss,ax
    mov  fs,ax
    mov  gs,ax
    mov  esp,BASE

    ; zero PML4 + PDPT + 4xPD (0x1000..0x6FFF)
    mov  edi,PML4
    xor  eax,eax
    mov  ecx,0x6000/4
    rep  stosd

    mov  dword [PML4],PDPT or 3                 ; P|RW
    mov  dword [PDPT+0 ],(PD+0x0000) or 3
    mov  dword [PDPT+8 ],(PD+0x1000) or 3
    mov  dword [PDPT+16],(PD+0x2000) or 3
    mov  dword [PDPT+24],(PD+0x3000) or 3

    mov  edi,PD                 ; 2048 x 2MiB pages, P|RW|PS; covers the LFB
    mov  eax,0x83
    mov  ecx,2048
.pd:
    mov  [edi],eax
    add  eax,0x200000
    add  edi,8
    loop .pd

    mov  eax,cr4
    or   eax,0x20               ; PAE
    mov  cr4,eax
    mov  eax,PML4
    mov  cr3,eax
    mov  ecx,0xC0000080         ; EFER
    rdmsr
    or   eax,0x100              ; LME
    wrmsr
    mov  eax,cr0
    or   eax,0x80000000         ; PG -> long mode active (compat submode)
    mov  cr0,eax
    jmp  0x18:lm64

use64
lm64:
    xor  eax,eax
    mov  ds,ax
    mov  es,ax
    mov  ss,ax
    mov  rsp,KSTACK
    jmp  kmain

align 8
gdt:
    dq 0
    dq 0x00CF9A000000FFFF       ; 0x08 code32
    dq 0x00CF92000000FFFF       ; 0x10 data
    dq 0x00AF9A000000FFFF       ; 0x18 code64
gdt_end:
gdt_desc:
    dw gdt_end-gdt-1
    dd gdt

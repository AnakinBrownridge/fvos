; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; main.inc - kernel entry. Entered in long mode, identity-mapped, DF undefined.
use64
kmain:
    cld
    mov  eax,[BOOTINFO+BI_FB]
    mov  [gfx_fb],rax
    mov  eax,[BOOTINFO+BI_PITCH]
    mov  [gfx_pitch],eax
    mov  r12d,[BOOTINFO+BI_W]
    mov  r13d,[BOOTINFO+BI_H]

    xor  edi,edi                ; desktop
    xor  esi,esi
    mov  edx,r12d
    mov  ecx,r13d
    mov  r8d,0x00203050
    call fill_rect

    mov  edi,100                ; window body
    mov  esi,100
    mov  edx,400
    mov  ecx,300
    mov  r8d,0x00C0C0C0
    call fill_rect

    mov  edi,100                ; title bar
    mov  esi,100
    mov  edx,400
    mov  ecx,24
    mov  r8d,0x000040A0
    call fill_rect
.halt:
    hlt
    jmp  .halt

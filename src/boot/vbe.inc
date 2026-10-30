; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; vbe.inc - VBE mode enumeration + set. Real mode only (uses INT 10h).
use16
; Out: CF=0 mode set, BootInfo filled. CF=1 failure.
vbe_setup:
    mov  ax,VBE_SEG
    mov  es,ax
    xor  di,di
    mov  dword [es:di],'VBE2'   ; request VBE2+ info block
    mov  ax,0x4F00
    int  0x10
    cmp  ax,0x004F
    jne  .fail
    cmp  dword [es:di],'VESA'
    jne  .fail
    lfs  si,[es:di+0x0E]        ; FS:SI -> mode list (far ptr)

.next:
    mov  cx,[fs:si]
    add  si,2
    cmp  cx,0xFFFF              ; end of list
    je   .fail
    push cx si
    mov  ax,0x4F01              ; query mode
    mov  di,VBE_MODE
    int  0x10
    pop  si cx
    cmp  ax,0x004F
    jne  .next

    mov  di,VBE_MODE
    mov  al,[es:di]             ; ModeAttributes: bit0 ok, bit4 gfx, bit7 LFB
    and  al,0x91
    cmp  al,0x91
    jne  .next
    cmp  word [es:di+0x12],WANT_W
    jne  .next
    cmp  word [es:di+0x14],WANT_H
    jne  .next
    cmp  byte [es:di+0x19],WANT_BPP
    jne  .next
    cmp  byte [es:di+0x1B],6    ; memory model 6 = direct colour
    jne  .next

    ; found: copy handoff (DS=0, so absolute addressing)
    mov  eax,[es:di+0x28]       ; PhysBasePtr
    mov  [BOOTINFO+BI_FB],eax
    movzx eax,word [es:di+0x10] ; pitch (bytes/scanline)
    mov  [BOOTINFO+BI_PITCH],eax
    movzx eax,word [es:di+0x12]
    mov  [BOOTINFO+BI_W],eax
    movzx eax,word [es:di+0x14]
    mov  [BOOTINFO+BI_H],eax
    movzx eax,byte [es:di+0x19]
    mov  [BOOTINFO+BI_BPP],eax

    movzx ebx,cx
    or   bh,0x40                ; bit 14: linear framebuffer
    mov  [BOOTINFO+BI_MODE],ebx
    mov  ax,0x4F02
    int  0x10
    cmp  ax,0x004F
    jne  .fail
    clc
    ret
.fail:
    stc
    ret

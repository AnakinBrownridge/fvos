; SPDX-License-Identifier: BSD-2-Clause
; Copyright (c) 2026 FVOS contributors
;
; gfx.inc - framebuffer primitives.
use64
gfx_fb:    dq 0
gfx_pitch: dd 0

; fill_rect  edi=x esi=y edx=w ecx=h r8d=0x00RRGGBB
; Load edi/esi with 32-bit movs so the upper halves are zero.
; Clobbers rax rcx rdi rsi r9 r10. Assumes DF=0. No clipping yet.
fill_rect:
    mov  r9,[gfx_fb]
    mov  r10d,[gfx_pitch]
    imul rsi,r10                ; y*pitch
    lea  rdi,[r9+rdi*4]         ; fb + x*4
    add  rdi,rsi
    mov  eax,r8d
.row:
    mov  r9,rdi                 ; remember row start
    push rcx
    mov  ecx,edx
    rep  stosd                  ; one row
    pop  rcx
    lea  rdi,[r9+r10]           ; next row = row start + pitch
    dec  ecx
    jnz  .row
    ret

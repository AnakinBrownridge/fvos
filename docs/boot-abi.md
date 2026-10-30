# Boot ABI

## BootInfo (physical 0x500, little-endian dwords)

| Offset | Name | Meaning |
|---|---|---|
| 0 | BI_FB | LFB physical address |
| 4 | BI_PITCH | bytes per scanline (always use this, never W*4) |
| 8 | BI_W | width in pixels |
| 12 | BI_H | height in pixels |
| 16 | BI_BPP | bits per pixel |
| 20 | BI_MODE | VBE mode number incl. bit 14 |

## State at kmain entry
Long mode, identity-mapped 0-4 GiB (write-back), interrupts disabled,
RSP = KSTACK, DS/ES/SS = 0, DF undefined (kmain executes `cld`).

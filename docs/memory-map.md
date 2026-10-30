# Memory Map (mirrors src/config.inc)

| Address | Size | Use |
|---|---|---|
| 0x00000500 | 24 B | BootInfo (see boot-abi.md) |
| 0x00001000 | 4 KiB | PML4 |
| 0x00002000 | 4 KiB | PDPT |
| 0x00003000 | 16 KiB | PD x4 (identity map 0-4 GiB, 2 MiB pages) |
| 0x00007C00 | 512 B | stage1 (MBR) |
| 0x00007E00 | image | stage2 + kernel (flat, contiguous) |
| 0x00070000 | 512 B + 256 B | VBE info block + mode info block (real-mode scratch) |
| 0x00090000 | grows down | kernel stack (KSTACK) |
| LFB (BIOS-chosen) | pitch*H | framebuffer, reached through the identity map |

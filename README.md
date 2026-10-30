# FVOS
A bare-metal x86_64 OS written entirely in FASM. One `fasm` call, one flat binary,
no linker. License: BSD-2-Clause.

## Build & run
    sudo apt install fasm qemu-system-x86
    tools/build.sh && tools/run.sh

Tested with fasm 1.73.x and QEMU 8.x. See CONTRIBUTING.md and docs/.

AI-assisted code disclosure: see [.ainotice/AINOTICE.md](.ainotice/AINOTICE.md).

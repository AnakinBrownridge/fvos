# ADR 0001: Single translation unit

Status: accepted

The whole OS is assembled by one `fasm` invocation on `src/os.asm`; every other
file is pulled in with `include`. No linker, no object files, no relocations.
This keeps builds in the millisecond range and the toolchain to one binary.
Contributions must not introduce a link step or additional build tools.

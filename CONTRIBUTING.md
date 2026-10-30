# Contributing

## Hard rules
1. One `fasm` invocation on `src/os.asm`. No linker, no objects, no external build deps.
2. Every file carries an SPDX header (`tools/check-spdx.sh` enforces it).
3. Sign off every commit: `git commit -s` (Developer Certificate of Origin).
4. No code, fonts or tables copied from other projects unless the license is
   compatible and the source is recorded in THIRD_PARTY.md.
5. Changes to `config.inc` or BootInfo must update `docs/memory-map.md` / `docs/boot-abi.md`.
6. Disclose AI assistance in the commit message (`Assisted-by: <tool/model>`).
   You remain responsible for the code you sign off.

## Style
Lowercase mnemonics, 4-space indent, a header comment on every routine stating
inputs, outputs and clobbered registers. Comment *why*, not *what*.

## Before opening a PR
    tools/build.sh && tests/smoke.sh
Include `time tools/build.sh` output if you added more than ~200 lines.

# AI Notice

## Disclosure

Portions of this repository were generated with AI assistance.

| Field | Value |
|---|---|
| Tool | Claude (Anthropic) |
| Model | Claude Sonnet 5.5 |
| Interface | Claude web/mobile chat (claude.ai) |
| Date | 2026-10-30 |
| Scope | Initial project scaffold: repository layout, `src/` boot chain (stage1, stage2, VBE setup, long-mode transition, paging), `src/kernel/gfx.inc` and `src/kernel/main.inc`, `tools/` scripts, `tests/smoke.sh`, CI workflow, and the draft `CONTRIBUTING.md` / `README.md` skeletons. |
| Direction | Architecture, constraints and requirements were specified by the project maintainers. |

Later contributions are not covered by this notice unless their commits say so.
Contributors who use AI tools should record that in the commit message
(for example, an `Assisted-by:` trailer).

## Status of the code

- The AI-generated code was **not guaranteed to be correct, secure or
  hardware-compatible**. It has been tested only to the extent described in
  `tests/smoke.sh` and CI (QEMU, `-vga std`). Real-hardware behaviour,
  especially BIOS/VBE quirks, is unverified.
- The project maintainers are responsible for everything merged into this
  repository, regardless of how it was produced.

## Licensing and provenance

- The repository is released under the license in `LICENSE`
  (see the SPDX headers in each file).
- AI-generated output may not be eligible for copyright protection in some
  jurisdictions, and the legal status of AI-generated code is unsettled. This
  is not legal advice.
- The generator was not asked to copy code from other projects, and no
  third-party code is intentionally included. However, the maintainers cannot
  guarantee that the output is free of similarity to existing works. Anything
  with known third-party origin must be recorded in `THIRD_PARTY.md`.
- Sign-offs (`git commit -s`, Developer Certificate of Origin) are made by
  human contributors, who certify their right to submit the code under the
  project license.

## Review policy

AI-assisted changes go through the same review, CI and sign-off requirements
as all other changes. See `CONTRIBUTING.md`.

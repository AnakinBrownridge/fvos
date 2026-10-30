#!/bin/sh
# SPDX-License-Identifier: BSD-2-Clause
# Copyright (c) 2026 FVOS contributors
rc=0
for f in $(git ls-files 'src/*.asm' 'src/*.inc' 'tools/*.sh' 'tests/*.sh'); do
  head -n 3 "$f" | grep -q 'SPDX-License-Identifier:' \
    || { echo "missing SPDX header: $f"; rc=1; }
done
exit $rc

#!/usr/bin/env bash
set -e

if [[ ! -x fuzzy || fuzzy.c -nt fuzzy ]]; then
    gcc -O2 -Wall -Wextra -pedantic fuzzy.c -o fuzzy
fi

exec ./fuzzy
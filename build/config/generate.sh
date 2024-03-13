#!/bin/sh

set -e

cd "$(dirname "$0")/../.."

YELLOW=$([ ! -t 2 ] || printf "\033[0;33m")
CLEAR=$([ ! -t 2 ] || printf "\033[0m")

printf "%sConfiguring...%s\nYou can simply ignore errors during configuring\n" "$YELLOW" "$CLEAR" 1>&2

CC="$(sh build/script/get-cc.sh)"
CFLAGS=""

printf "CC := %s\n" "$CC"

if [ "$CC" = "clang" ] || [ "$CC" = "clang" ]; then
  mkdir -p .cache
  echo "int main(void){}" > .cache/test.c
  CFLAGS="-Werror -pedantic -std=c99"
  for str in all extra pedantic cast-qual conversion double-promotion duplicated-branches duplicated-cond float-equal format=2 format-signedness init-self logical-op missing-declarations missing-prototypes padded shadow strict-prototypes switch-default switch-enum undef unused-macros write-strings; do
    "$CC" -W$str -Werror -o .cache/test .cache/test.c 1>&2 && CFLAGS="$CFLAGS -W$str" || :
  done
fi

if [ -n "$CFLAGS" ]; then
  printf "CFLAGS := %s\n" "$CFLAGS"
fi

printf "%sConfigure - done.%s\n" "$YELLOW" "$CLEAR" 1>&2

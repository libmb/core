#!/bin/sh

set -e

cd "$(dirname "$0")/../.."

trap 'rm -f compile_commands.json.tmp' EXIT;

if command -v cmd > /dev/null; then
  PWD="$(cmd //c cd | sed 's|\\|\\\\\\\\|g' | sed s/\"/\\\"/g)"
else
  PWD="$(pwd | sed 's|\\|\\\\\\\\|g' | sed s/\"/\\\"/g)"
fi

sed "s\\[\\[WORKSPACE\\]\\]$PWDg" build/misc/compile_commands.json.template > compile_commands.json.tmp
mv compile_commands.json.tmp compile_commands.json

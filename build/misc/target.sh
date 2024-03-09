#!/bin/sh

set -e

cd "$(dirname "$0")/../.."

rm -rf .cache/target .cache/target.tmp

trap 'rm -rf .cache/target.tmp' EXIT

mkdir -p .cache/target.tmp

sh build/misc/target_makefile.sh > .cache/target.tmp/Makefile

mv .cache/target.tmp .cache/target

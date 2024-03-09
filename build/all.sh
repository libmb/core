#!/bin/sh

set -e

cd "$(dirname "$0")/.."

[ -d .cache/target ] || sh build/misc/target.sh
(cd .cache/target && make)

#!/bin/sh

set -e

cd "$(dirname "$0")/../../src"

find . -type f -name \*.c | cut -c 3- | grep -v __test__

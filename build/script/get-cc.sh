#!/bin/sh

set -e

(command -v clang > /dev/null && echo "clang") ||
(command -v gcc > /dev/null && echo "gcc") ||
(command -v c99 > /dev/null && echo "c99") ||
echo "cc"

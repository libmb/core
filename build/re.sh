#!/bin/sh

set -e

cd "$(dirname "$0")/.."

sh build/fclean.sh
sh build/all.sh

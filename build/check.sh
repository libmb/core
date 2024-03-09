#!/bin/sh

set -e

cd "$(dirname "$0")/.."

sh spec/check.sh

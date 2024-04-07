#!/bin/sh

set -e

cd "$(dirname "$0")/.."

trap 'rm -rf .cache/tmp' EXIT

per_target() {
  TARGET_TRIPLE="$1"

  mkdir -p ".cache/tmp/$TARGET_TRIPLE"
  sh build/script/get-source.sh | xargs -I {} sh -c "mkdir -p \$(dirname '.cache/tmp/{}') && clang -target '$TARGET_TRIPLE' -I include -c -o .cache/tmp/$TARGET_TRIPLE/{}.o src/{}"
  sh build/script/get-source.sh | sed "s:^:.cache/tmp/$TARGET_TRIPLE/:" | sed s/\$/.o/ | xargs llvm-ar -c -r -s ".cache/tmp/$TARGET_TRIPLE/libmb_core.a"
  (cd ".cache/tmp/$TARGET_TRIPLE" && zip -9 -r "../../../out/$TARGET_TRIPLE.zip" libmb_core.a)
}

rm -rf out
mkdir -p out

while IFS= read -r TARGET_TRIPLE; do
  per_target "$TARGET_TRIPLE"
done < build/data/targets.txt

(cd include && find . -name "*.h" -exec zip -9 -r "../out/include.zip" {} \;)

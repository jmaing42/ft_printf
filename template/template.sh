#!/bin/sh

set -e

printf ".POSIX:\n# this file is generated, do not modify directly\n\n"

printf "OBJS = %s\n" "$(find . -name "*.c" | grep -v /test/ | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"

printf "\n"

cat ../template/template.mk

printf "\n# dependencies\n"

find . -name "*.c" | cut -c 3- | sort | xargs clang -MM -MG

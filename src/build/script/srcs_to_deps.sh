#!/bin/sh

while IFS= read -r line
do
  line=$(printf "%s" "$line" | sed s/\\.c\$//)
  printf "%s: %s\n" "$1" "$(basename "$line.o")"
  printf "%s: %s\n" "$(basename "$line.o")" "../$line.c"
done

#!/bin/bash

OUTPUT="TOP_SECRET.txt"
FLAG_LINE=138   # where the flag will be hidden
CODE=""

> "$OUTPUT"

for i in $(seq 1 250); do
  if [ "$i" -eq "$FLAG_LINE" ]; then
    # 50 letters exactly:
    # FLAGHIDDENINRANDOMTEXT (22 chars) + 28 X's = 50
    echo "QDKHJWKFGHJSECRETIS$CODE" >> "$OUTPUT"
  else
    tr -dc 'A-Z' </dev/urandom | head -c 50 >> "$OUTPUT"
    echo >> "$OUTPUT"
  fi
done

echo "[+] Generated $OUTPUT (250 lines, 50 letters each)"

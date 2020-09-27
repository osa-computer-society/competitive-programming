#!/bin/bash

echo "Are you sure you want to remove all .in, .out, .txt. csv, and .dSYM files?"
read yn
if [[ "$yn" =~ [yY].* ]]
then
  find . -type f \( -name *.in -o -name *.out -o -name *.txt -o -name *.csv -o -perm 755 \) -path .git -exec rm -i {} \;
  find . -type d -name *.dSYM -exec rm -rf {} \;
fi

#!/bin/bash

echo "Are you sure you want to remove all .in, .out, .txt. csv, and executable files?"
read yn
if [[ "$yn" =~ [yY].* ]]
then
  find . -type f \( -name "*.txt" -o -name "*.csv" -o -perm 755 \) -not -path "./.git/*" -exec rm -i {} \;
  find . -type d -name *.dSYM -exec rm -rf {} \;
fi

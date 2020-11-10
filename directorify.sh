#!/bin/bash

for file in `ls -l | grep "^-" | tr -s ' ' | cut -d ' ' -f 9`; do
  mkdir ${file:r}
  mv $file ${file:r}
done

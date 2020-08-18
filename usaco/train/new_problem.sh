#!/bin/bash

if [ $# -eq 0 ]
then
    echo "Please enter the problem task name"
else
    touch "$1.in"
    cp template.cpp "$1.cpp"
    sed -i '' "s/NAME_OF_TASK/$1/g" "$1.cpp"
    code -r "$1.in" "$1.cpp"
fi

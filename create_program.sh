#!/bin/bash

template="/Users/alexandercai/GitHub/competitive-programming/template.cpp"

createFile() {
    cd "$1"
    code -r "$2"
    if [[ -e "$2" ]]; then
        head -n 5 "$2"
        echo "File already exists. Do you want to overwrite it?"
        read yn
        if [[ "$yn" =~ y.*|Y.* ]]; then
            sed "1 s/: /: $2/" "$template" > "$2"
        else
            echo "No changes have been made."
        fi
    else
        sed "1 s/: /: $2/" "$template" > "$2"
    fi
}

if [[ "$1" == "dmoj" ]]; then
    createFile "dmoj" "${2}.cpp"
elif [[ "${1:0:3}" =~ cc[co] ]]; then
    dirPath="ccc/20${1:3:2}"
    if [[ ! -d "$dirPath" ]]; then
        mkdir "$dirPath"
    fi
    createFile "$dirPath" "${1}.cpp"
elif [[ "${1:0:5}" == "usaco" ]]; then
    dirPath="usaco/${1:7:3}_${1:5:2}"
    if [[ ! -d "$dirPath" ]]; then
        mkdir "$dirPath"
    fi
    createFile "$dirPath" "${1}.cpp"
else
    createFile "dmoj" "${1}.cpp"
fi

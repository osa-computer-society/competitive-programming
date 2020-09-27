#!/bin/bash

if [[ "$#" -eq 0 ]]; then
    echo You must pass the contest as the first argument! e.g. "./create_program.sh dmoj <program_name>"
    exit 0
fi

templatePath="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )/template.cpp"

# add the problem name to the first line
writeToTemplate() {
    sed "1 s/: /: $1/" "$templatePath" > "$1"
}

# $1 is the directory to create the problem in
createFile() {
    mkdir -pv "$1" 
    cd "$1"
    # if the file exists, show the top 5 lines and prompt for overwrite
    if [[ -e "$2" ]]
    then
        head -n 5 "$2"
        echo "File already exists. Do you want to overwrite it?"
        read yn
        if [[ "$yn" =~ [yY].* ]]
        then
            writeToTemplate "$2"
        else
            echo "No changes have been made."
        fi
    else
        writeToTemplate "$2"
    fi
}

if [[ "$1" == "dmoj" ]]; then
    createFile "dmoj" "${2}.cpp"
elif [[ "$1" =~ cc[co] ]]; then
    if [[ "$#" -lt 3 ]]; then
        echo "Please specify the year, e.g. createFile ${1:0:3} 2020 s3"
        exit 1
    fi
    createFile "ccc/$2" "$3.cpp"
elif [[ "$1" == "usaco" ]]; then
    if [[ "$#" -lt 4 ]]; then
        echo "Please specify the year, contest, and problem name, e.g. ./createFile usaco 2020 february swap"
        exit 1
    fi
    createFile "usaco/$2/$3" "$4.cpp"
else
    echo "Please specify the contest this problem is from, e.g. ./createFile ccc [year] [problem]"
    exit 1
fi

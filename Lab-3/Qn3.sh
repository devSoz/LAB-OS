#!/bin/sh
echo "Enter file name: "
read filename

filePermission="$(stat -c %A $filename)"

if [[ ${filePermission:3:1} == "x" ]]
then
     echo "$filename has execute permission"
else
     echo "$filename don't have execute permission"
fi
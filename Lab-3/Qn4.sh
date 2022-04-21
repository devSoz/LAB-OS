#!/bin/sh
max=0
filename=''
for FILE in *; 
do 
    #stat used to get file details
    size=$(stat -c %s $FILE)
    if [ $size -ge $max ]
    then #compare and find largest file
        max=$size
        filename=$FILE
    fi
done
echo "$filename is the largest file with size $max bytes"
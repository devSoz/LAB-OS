#!/bin/bash
N=10
i=1
sum=0
avg=0
echo "Enter the numbers:"
while [ $i -le $N ]
do
  read num           
  sum=$((sum + num)) 
  i=$((i + 1))
done

echo "The sum is $sum"

avg=$((sum/N))
echo "The average is $avg"


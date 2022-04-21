echo "Enter the numbers: "
i=0
sum=0
avg=0
n=10
while [ $i -le $n ]
do
    read num
    sum=$((sum+num))
    i=$((i+1))
done
echo "Sum: $sum"
let avg=$((sum/n))
echo "Average: $avg"
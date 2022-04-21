echo -n "Enter number: "
read num
for i in $(seq 1 $num)
do
 [ $(expr $num % $i) == 0 ] && echo $i
done
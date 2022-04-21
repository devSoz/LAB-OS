echo "Enter a number: "
read num
count=0
i=0
for (( i=1; i <= $num; i++ ))
do
    if [ $(($num%$i)) == 0 ] 
    then 
        echo "$i"
    fi
done


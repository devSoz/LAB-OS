echo -n "Enter string: "
read str
len=${#str}
len=$((len-1))
count=0
#echo "$len"
for i in $(seq 0 $len)
do
    ch=${str:$i:1}
    if  $ch in [aeiouAEIOU]
    then 
        count=$((count+1))
    fi
done
echo "The given string is '$str' and have $count vowels"
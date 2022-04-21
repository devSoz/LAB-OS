read -p "Enter string: " str
length=${#str}
length=$((length-1))
i=$length
while [ $i -ge 0 ]
do
    reversedStr=$reversedStr${str:$i:1}
    i=$((i-1))
done
echo "Reverse of string $str: $reversedStr" 
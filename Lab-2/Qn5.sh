echo -n "Enter string: "
read str
len=${#str}
len=$((len-1))
count=0
#echo "$len"
for i in $(seq 0 $len)
do
    ch=${str:$i:1}
    case  $ch in [aeiouAEIOU] )
        count=$((count+1))
        ;;
    esac
done
echo "$str has $count vowels"
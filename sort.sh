#!/bin/bash
read -p "Enter your array:" -a a
len=${#a[@]}
echo Your array length: $len
sort()
{
	if [ $1 -lt $2 ]
	then
		u=$1
		v=$2
		t=${a[$u]}
		while [ $u -ne $v ]
		do
			while [[ $v -gt $u && ${a[$v]} -ge $t ]]
			do
				v=$(($v-1))
			done
			a[$u]=${a[$v]}
			while [[ $u -lt $v && ${a[$u]} -lt $t ]]
			do
				u=$(($u+1))
			done
			a[$v]=${a[$u]}
		done
		a[$u]=$t
		sort $1 $(($u-1))
		sort $(($u+1)) $2
	fi
}
sort 0 $(($len-1))
echo Ordered list: ${a[*]}

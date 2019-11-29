#!/bin/bash
a=$((($RANDOM+1)%100))
while read -p "Enter your number:" num
do
	if [ $num -gt 0 ]&&[ $num -lt 101 ]
	then
		if [ $num -eq $a ]
		then
			echo "BINGO!"
			break
		fi
		if [ $num -gt $a ]
		then
			echo "Larger, try again!"
		else
			echo "Smaller, try again!"
		fi
	else
		echo "Num is over range, please enter 1~100"
	fi
done

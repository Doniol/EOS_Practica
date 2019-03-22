#!/usr/bin/env bash

#Encodes input and saves it to a file.
while :
do
	NEWTEXT=""
	echo "Enter Text (Enter <EOF> if done): "
	read TEXT
	if [ $TEXT == "<EOF>" ]
	then
		break
	fi
	for CHAR in $(seq 1 ${#TEXT})
	do
		printf -v NUM %d "$CHAR"
		(( NUM += 2 ))
		printf -v NEWCHAR \\$(printf '%03o' "$NUM")
		NEWTEXT+=$NEWCHAR
	done
	echo $NEWTEXT >> /home/hu/encoded.txt
done
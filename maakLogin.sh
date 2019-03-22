#!/usr/bin/env bash

echo "Enter Username: "
read USER
if [[ -z "${USER// }" ]]
then
	USERNAME=$(whoami)
else
	USERNAME=$USER
fi
echo "Enter Password (Password must contain 1 uppercase, 1 lowercase letter, 1 number and must be at least 8 characters long): "
read PASS
while :
do
	if [[ $PASS =~ [A-Z] ]] && [[ $PASS =~ [a-z] ]] && [[ $PASS =~ [0-9] ]] && [ ${#PASS} -gt 8 ]
	then
		break
	fi
	echo "Invalid Password!"
	read PASS
done
echo "$USERNAME" >> /home/hu/$1.txt
echo $PASS | md5sum >> /home/hu/$1.txt
echo "Account details saved in: /home/hu/$1.txt"
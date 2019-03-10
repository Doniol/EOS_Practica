#!/usr/bin/env bash

$(truncate -s 0 $1/log.txt)
for f in $(find $1 -type f -name "*")
do
	$2 $f
	RETURNVAL=$?
	if [ $RETURNVAL -ne 0 ]
	then
		echo "Command $2 $f did not succeed." >> $1/log.txt
	fi
done
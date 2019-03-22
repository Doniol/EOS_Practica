#!/usr/bin/env bash

COUNT=0
ITEMS=$1/*

for ITEM in $ITEMS
do
	for ARGUMENT in "$@"
	do
		case $ITEM in
			*.$ARGUMENT)
			COUNT=$((COUNT+1))
			;;
		esac
	done
done

echo $COUNT
#!/usr/bin/env bash

FOLDER="$1/Afbeeldingen"
mkdir -p $FOLDER
for f in $(find . -type f -name "*.png" -o -name "*.jpg")
do
	mv $f $FOLDER
done
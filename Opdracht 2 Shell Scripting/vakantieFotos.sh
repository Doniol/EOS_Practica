#!/usr/bin/env bash

FOLDER="$1/Afbeeldingen/Vakantie"
mkdir -p $FOLDER
for f in $(find $1 -type f -name "*vakantie*.png" -o -name "*vakantie*.jpg")
do
	mv $f $FOLDER
done
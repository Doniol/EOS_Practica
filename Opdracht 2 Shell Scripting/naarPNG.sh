#!/usr/bin/env bash

for f in $(find $1 -type f -name "*.jpg")
do
	NAME=${f::-4}
	$(convert $f $NAME.png)
	rm -f $f
done
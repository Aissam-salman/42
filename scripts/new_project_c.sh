#!/bin/bash

if [ $1 ]; then
	NAME=$1
else
	echo "Need name!"
	exit 1
fi

git clone https://github.com/Aissam-salman/template_c-42.git $NAME

rm -rf $NAME/.git

#!/bin/bash

binName=ouput
g++ -Wall -g -o $binName fullcode.cpp
if [ -f "$binName" ]; then
	./$binName
	rm -f $binName
else
	echo "compile error"
fi

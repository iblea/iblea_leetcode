#!/bin/bash

curpath=$(dirname $(realpath $0))
# gtest_path=$(realpath $curpath/../template/googletest)
gtest_path=$(realpath $curpath/googletest)
echo $gtest_path

binName="output_gtest"

fileName=""
if [ $# -ge 1 ]; then
    fileName="$1"
else
    fileName="fullcode.cpp"
    # fileName="gtest_template.cpp"
fi

if [ ! -f $fileName ]; then
    echo "file not exist"
    exit 1
fi

./build_gtest.sh "$fileName"

if [ -f "$binName" ]; then
	./$binName
	rm -f $binName
    if [ -d "$binName.dSYM/" ]; then
        rm -rf ./$binName.dSYM/
    fi
else
	echo "compile error"
fi

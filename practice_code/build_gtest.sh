#!/bin/bash

curpath=$(dirname $(realpath $0))
project_path=$(pwd)

# gtest_path=$(realpath $curpath/../template/googletest)
gtest_path=$(realpath $curpath/googletest)

binName="output_gtest"
fileName=""

if [ $# -ge 1 ]; then
    fileName="$1"
else
    fileName="fullcode.cpp"
    # fileName="gtest_template.cpp"
fi

# g++ -Wall -g \
#     -I $gtest_path/include \
#     -L $gtest_path/lib \
#     -o $binName $fileName \
#     -std=c++17 -pthread \
#     -lgtest -lgtest_main -lpthread

# g++
# /opt/homebrew/bin/g++-13

clang++ -Wall -g -O0 \
	-I $gtest_path/include \
	-L $gtest_path/lib \
	-std=c++17 \
	$fileName \
	-o $binName \
	-lgtest -lgtest_main -lpthread \
	-fno-omit-frame-pointer \
	-gdwarf-4


# 이 디렉토리 없애면 중단점 등 안됨.
# if [ -d "$binName.dSYM/" ]; then
# 	rm -rf ./$binName.dSYM/
# fi

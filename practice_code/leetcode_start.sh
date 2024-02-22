#!/bin/bash

curpath=$(dirname $(realpath $0))
cd "$curpath"

JAVA_FILE="Solution.java"
CLASS_NAME="${JAVA_FILE:0:${#JAVA_FILE}-5}"
CLASS_FILE="${CLASS_NAME}.class"


if [ -f "CLASS_FILE" ]; then
    rm -f $CLASS_FILE
fi

javac $JAVA_FILE
java $CLASS_NAME

if [ -f "$CLASS_FILE" ]; then
    rm -f $CLASS_FILE
fi
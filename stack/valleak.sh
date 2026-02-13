#!/bin/bash


if [ -z "$1" ]; then
    echo "You have not pass any file to check"
    exit 1
fi
valgrind --tool=memcheck --leak-check=full "$1"

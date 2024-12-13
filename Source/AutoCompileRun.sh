#!/bin/bash

echo "AutoCompileRun:"

g++ -std=c++11 -o main Node.cpp Map.cpp main.cpp

./main


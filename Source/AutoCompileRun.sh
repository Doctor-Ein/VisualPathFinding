#!/bin/bash

echo "AutoCompileRun:"

g++ -std=c++11 -o main ./SharedRepo/Node.cpp ./SharedRepo/Map.cpp main.cpp


./main
set the bounds of the front window to {100, 100, 800, 600}

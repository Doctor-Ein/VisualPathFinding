#!/bin/bash
echo "Auto Compile Run:"

# 检查 main 可执行文件是否存在
if [ ! -f main ]; then
    echo "Compiling source files..."
    g++ -std=c++11 -o main Map.cpp Solution.cpp main.cpp
else
    echo "Executable 'main' exists, skipping compilation."
fi

# 运行程序
./main

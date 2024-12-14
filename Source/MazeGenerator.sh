#!/bin/bash

echo "MazeGenerator CompileRun:"

# 使用 AppleScript 设置终端窗口大小并在新窗口中运行程序
osascript -e 'tell application "Terminal"
    -- 创建第一个新窗口并设置大小
    do script "cd /Users/xlx/VScode/CPP/程序设计/TermWork/Source/ && g++ -std=c++11 -o MazeGenerator Node.cpp Map.cpp MazeGenerator.cpp && ./MazeGenerator"
    set the bounds of the front window to {100, 100, 800, 600}  -- 设置第一个窗口的位置和大小 (60x30 字符，480x480 像素)
end tell'

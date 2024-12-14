#!/bin/bash

# 切换到目标目录
cd /Users/xlx/VScode/CPP/程序设计/TermWork/Source/

# 编译 Sol_DFS
echo "Starting Sol_DFS compilation"
g++ -std=c++11 -o Sol_DFS Node.cpp Map.cpp Sol_DFS.cpp

# 编译 Sol_BFS
echo "Starting Sol_BFS compilation"
g++ -std=c++11 -o Sol_BFS Node.cpp Map.cpp Sol_BFS.cpp

# 编译 Sol_Astar
echo "Starting Sol_Astar compilation"
g++ -std=c++11 -o Sol_Astar Node.cpp Map.cpp Sol_Astar.cpp

osascript -e 'tell application "Terminal"
    -- 创建第一个新窗口并设置大小
    do script "cd /Users/xlx/VScode/CPP/程序设计/TermWork/Source/ && ./Sol_DFS"
    set the bounds of the front window to {100, 100, 580, 600}  -- 设置第一个窗口的位置和大小 (60x30 字符，480x480 像素)

    -- 创建第二个新窗口并设置大小
    do script "cd /Users/xlx/VScode/CPP/程序设计/TermWork/Source/ && ./Sol_BFS"
    set the bounds of the front window to {600, 100, 1080, 600}  -- 设置第二个窗口的位置和大小

    -- 创建第三个新窗口并设置大小
    do script "cd /Users/xlx/VScode/CPP/程序设计/TermWork/Source/ && ./Sol_Astar"
    set the bounds of the front window to {1100, 100, 1580, 600}  -- 设置第三个窗口的位置和大小
end tell'

#!/bin/bash

# 记录当前目录
PathofSource=$(pwd)

# 编译 Sol_DFS
echo "Starting Sol_DFS compilation"
g++ -std=c++11 -o Sol_DFS ./SharedRepo/Node.cpp ./SharedRepo/Map.cpp ./ExtenRepo/Sol_DFS.cpp

# 编译 Sol_BFS
echo "Starting Sol_BFS compilation"
g++ -std=c++11 -o Sol_BFS ./SharedRepo/Node.cpp ./SharedRepo/Map.cpp ./ExtenRepo/Sol_BFS.cpp

# 编译 Sol_Astar
echo "Starting Sol_Astar compilation"
g++ -std=c++11 -o Sol_Astar ./SharedRepo/Node.cpp ./SharedRepo/Map.cpp ./ExtenRepo/Sol_Astar.cpp

# 使用 AppleScript 打开新的终端窗口并运行命令
osascript <<EOF
tell application "Terminal"
    -- 创建第一个新窗口并设置大小
    do script "cd ${PathofSource} && ./Sol_DFS"
    set the bounds of the front window to {100, 100, 580, 700}

    -- 创建第二个新窗口并设置大小
    do script "cd ${PathofSource} && ./Sol_BFS"
    set the bounds of the front window to {600, 100, 1080, 700}

    -- 创建第三个新窗口并设置大小
    do script "cd ${PathofSource} && ./Sol_Astar"
    set the bounds of the front window to {1100, 100, 1580, 700}
end tell
EOF

#!/bin/bash

# 编译项目
echo "编译项目..."
g++ -std=c++11 -o MazeGenerator \
    "./ExtenRepo/MazeGenerator.cpp" \
    "./SharedRepo/Map.cpp" \
    "./SharedRepo/Node.cpp"

# 运行可执行文件
echo "运行项目..."
osascript <<EOF
tell application "Terminal"
    do script "cd $(pwd) && ./MazeGenerator"
    delay 1
    set bounds of front window to {0, 0, 1440, 900} -- 可调整分辨率大小
    try
        set fullscreen of front window to true -- 将窗口设置为全屏
    end try
end tell
EOF

echo "项目运行完成"

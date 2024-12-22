#!/bin/bash

echo "MazeGenerator CompileRun:"

# 使用 AppleScript 设置终端窗口大小并在新窗口中运行程序
osascript -e 'tell application "Terminal"
    activate  -- 激活 Terminal 应用
    try
        -- 尝试关闭所有 Terminal 窗口
        set allWindows to every window
        repeat with aWindow in allWindows
            close aWindow
        end repeat
    end try
    -- 创建第一个新窗口并设置全屏
    do script "cd /Users/xlx/VScode/CPP/程序设计/TermWork/Source/ && g++ -std=c++11 -o MazeGenerator ./SharedRepo/Node.cpp ./SharedRepo/Map.cpp ./ExtenRepo/MazeGenerator.cpp && ./MazeGenerator"
    set the bounds of the front window to {0, 0, 1920, 1080}  -- 设置第一个窗口全屏 (根据你的屏幕分辨率调整)
end tell'
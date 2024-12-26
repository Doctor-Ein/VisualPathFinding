@echo off
SETLOCAL EnableDelayedExpansion

:: 编译项目
echo 编译项目...
g++ -std=c++11 -o MazeGenerator ^
    ".\ExtenRepo\MazeGenerator.cpp" ^
    ".\SharedRepo\Map.cpp" ^
    ".\SharedRepo\Node.cpp"

:: 运行可执行文件
echo 运行项目...
start /max cmd /c "cd %cd% && MazeGenerator"
timeout /t 1

echo 项目运行完成
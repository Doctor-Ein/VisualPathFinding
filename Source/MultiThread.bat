@echo off
SETLOCAL EnableDelayedExpansion

:: 记录当前目录
set PathofSource=%cd%

:: 编译 Sol_DFS
echo Starting Sol_DFS compilation
g++ -std=c++11 -o Sol_DFS .\SharedRepo\Node.cpp .\SharedRepo\Map.cpp .\ExtenRepo\Sol_DFS.cpp

:: 编译 Sol_BFS
echo Starting Sol_BFS compilation
g++ -std=c++11 -o Sol_BFS .\SharedRepo\Node.cpp .\SharedRepo\Map.cpp .\ExtenRepo\Sol_BFS.cpp

:: 编译 Sol_Astar
echo Starting Sol_Astar compilation
g++ -std=c++11 -o Sol_Astar .\SharedRepo\Node.cpp .\SharedRepo\Map.cpp .\ExtenRepo\Sol_Astar.cpp

:: 使用start命令打开新的终端窗口并运行命令
start cmd /k "cd %PathofSource% && Sol_DFS"
start cmd /k "cd %PathofSource% && Sol_BFS"
start cmd /k "cd %PathofSource% && Sol_Astar"
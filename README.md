# Visual PathFing

- Developers:
  - TheEin
  - 未蒙
  - York
  - Simon

# 主题：迷宫求解算法的可视化
## 项目概述
本项目是一个迷宫生成与求解的程序，它包括迷宫的生成、显示以及使用不同算法（如深度优先搜索、广度优先搜索、A*算法）求解迷宫的路径。程序旨在提供一个交互式的环境，让用户可以自定义迷宫大小、加载迷宫地图，并观察不同算法求解迷宫的过程。



## 项目使用说明
## 提供三个自动化脚本：（在source文件夹下打开终端运行）
+ `AutoCompileRun`：自动化编译运行完成地图生成以及DFS、BFS、Astar的顺序运行
+ `MultiThread`：利用终端多线程（伪）展开三种算法的同时比较
+ `MazeGenerator`：自动化编译运行，展示生成地图的过程

```shell
./AutoCompileRun.sh
./MultiThread.sh
./MazeGenerator.sh
# 请在source文件夹下打开终端
```

---

## 项目组成
+ **AsciiArt.h** 用于打印 ASCII 艺术字符画，增强程序的视觉效果。
+ **GlobalMap.h**: 声明全局地图对象，防止公共资源被篡改。
+ **Map.h/.cpp**: 定义地图类，包含地图的读取、打印和合法性检查等功能。
+ **Node.h/.cpp**: 定义节点类，表示地图上的每一个单元格。
+ **MazeGenerator.h/.cpp**: 迷宫生成器，负责生成随机迷宫并保存到文件。
+ **SolutionAstar.h**: 实现 A* 算法求解迷宫。
+ **SolutionBFS.h**: 实现广度优先搜索算法求解迷宫。
+ **SolutionDfs.h**: 实现深度优先搜索算法求解迷宫。
+ **main.cpp**: 程序的主入口，负责用户交互和算法调用。

## 项目架构：
![画板](https://cdn.nlark.com/yuque/0/2024/jpeg/50620204/1733736557280-1c0d5a0c-484c-4dbe-8fad-58df5b3fc181.jpeg)

---

# 项目库开发文档
## 1. 概述
本项目提供了一个用于迷宫求解和可视化展示的库。它包括地图的表示、节点的定义以及地图的读取和打印功能。开发者可以基于这个库设计和实现自己的迷宫求解算法。

## 2. 公共资源库组成
## Node 类
### 成员数据
+ `Color Frontground`: 节点的前景色。
+ `Color Background`: 节点的背景色。
+ `int number`: 节点关联的数字，用于输出。
+ `int status`: 管理输出模式的标志。
+ `int x, y`: 节点的坐标。
+ `int step`: 节点的步数。
+ `bool IsWall`: 标记节点是否为墙。
+ `bool flag`: 提供一个标记，可以标记节点是否被访问过。

### 成员函数
+ `setColor(Color _FrontColor = Color::Black, Color _BackColor = Color::White)`: 设置节点的前景色和背景色。
+ `int getNumber() const`: 获取节点关联的数字。
+ `void setNumber(int _num)`: 设置节点关联的数字，并设置输出模式。
+ `void Output()`: 输出节点的颜色和数字。

## Map 类
### 成员数据
+ `int width,lenght`：地图的长宽
+ `vector<vector<Node>> val`: 存储地图上所有节点的二维向量。
+ `pair<int, int> S, E`: 地图的起点和终点坐标。

### 成员函数
+ `Map(int len = 1, int wid = 1, pair<int, int> start = {0, 0}, pair<int, int> end = {0, 0})`: 构造函数，初始化地图大小和起点终点。
+ `void setMap(int len, int wid)`: 设置地图的大小。
+ `int ReadMap(string path)`: 从文件路径读取地图数据。
+ `void PrintMap(ull t = 500)`: 打印地图，并在指定时间后清屏。
+ `bool Islegal(int i, int j)`: 判断指定坐标是否合法。

### 2.3 enum class Color/Unicode
+ **Color使用方法：**`Color::CodeName`
    - **黑色**: <font style="color:black;">Black</font>
    - **红色**: <font style="color:red;">Red</font>
    - **绿色**: <font style="color:green;">Green</font>
    - **黄色**: <font style="color:yellow;">Yellow</font>
    - **蓝色**: <font style="color:blue;">Blue</font>
    - **品红色**: <font style="color:magenta;">Magenta</font>
    - **青色**: <font style="color:cyan;">Cyan</font>
    - **白色**: <font style="color:white;background-color:#000000;">White</font>
    - **亮黑色**: <font style="color:#808080;">BrightBlack</font>
    - **亮红色**: <font style="color:#ff0000;">BrightRed</font>
    - **亮绿色**: <font style="color:#00ff00;">BrightGreen</font>
    - **亮黄色**: <font style="color:#ffff00;">BrightYellow</font>
    - **亮蓝色**: <font style="color:#0000ff;">BrightBlue</font>
    - **亮品红色**: <font style="color:#ff00ff;">BrightMagenta</font>
    - **亮青色**: <font style="color:#00ffff;">BrightCyan</font>
    - **亮白色**: <font style="color:#ffffff;background-color:#000000;">BrightWhite</font>

## 3. 使用方法
**摘要：就用三种节点Node的**`set`**自定义对应节点，然后每一帧使用**`PrintMap`**输出一下就好啦，希望有很好的美术效果～**

### 3.1 包含头文件
在您的源文件中包含 `Map.h` 和 `Node.h` 头文件，以便使用库中定义的类和函数。

```cpp
#include "Map.h"
#include "Node.h" //其实是Map.h的前置依赖，可以不包含
```

### 3.2 设计迷宫求解算法
在您的代码中实现迷宫求解算法。算法应该能够遍历地图上的节点，并根据求解过程更新节点的状态。

```cpp
void SolveMaze(Map& map) {
    // 实现您的迷宫求解算法
    // 例如，设置起点和终点，标记路径等
}
```

### 3.3 可视化展示
+ 调用`setColor`、`setNumber`函数来设置地图上你希望输出的内容，请发挥你们的想象力和审美观：

```cpp
void Solution_Name(Map& map) {
    map[i][j].SetColor(Color::White,Color::Black);
    map[i][j].SetNumber(6);
    //输出结果为i,j位置的节点是黑底白字的数字6
}
```

+ 在完成了一帧图像的设置之后，请调用调用 `PrintMap` 函数来可视化展示迷宫的状态。

```cpp
// 完成这一帧地图颜色和输出的设置
map.PrintMap(); // 打印迷宫状态
```

### 3.4 一些功能支持：
+ `Map.Islegal(x,y)`方便的判断在这个地图上，坐标点(x,y)是否越界和触墙

## 4. 注意事项
+ 确保地图文件的格式正确，且与 `Map` 对象的尺寸相匹配。
+ `PrintMap` 函数中的延迟时间可能需要根据实际需求调整，以获得最佳的视觉效果。
+ 在设计算法时，合理使用 `Node` 类提供的方法来更新节点状态，以便在可视化展示中清晰地表示迷宫的状态。

## 5. 编译和运行
在编译时，确保包含了所有必要的头文件，并且链接了正确的库。如果使用了特定的系统调用（如 Windows 的 `windows.h` 或 Unix 的 `unistd.h`），确保在编译时指定了正确的编译选项。

如果电脑上有gcc的可以使用以下代码：`g++ -std=c++11 -o main Node.cpp Map.cpp main.cpp`

然后点击生成的可执行文件即可

## 
## 项目部署与使用
### 环境要求
+ C++ 编译器（如 g++, clang++）
+ 标准 C++ 库
+ 操作系统支持（Windows/Linux）

### 编译步骤
1. 将所有 `.h` 和 `.cpp` 文件放置在同一目录下。
2. 使用 C++ 编译器编译项目。例如，使用 g++ 可以执行以下命令：

```bash
g++ -o maze_solver *.cpp
```

3. 确保所有依赖库都已正确链接。

### 使用方法
1. 运行编译后的程序。
2. 按照提示设置迷宫的长度和宽度。
3. 输入地图文件的路径或使用默认路径。
4. 选择并观察不同算法求解迷宫的过程。

### 注意事项
+ 确保输入的地图路径正确，且文件格式符合要求。
+ 程序中的 ASCII 艺术字符画需要在支持 ANSI 转义序列的终端中运行。

## 贡献与反馈
+ 如果您有任何问题或建议，请通过 [Issue](https://github.com/yourusername/maze-solver/issues) 反馈。
+ 欢迎贡献代码，请遵循项目中的代码风格和规范。

---

希望这个 README 文件能帮助您快速了解和使用本项目。如果您需要进一步的开发细节或对算法实现感兴趣，可以查看各个源文件中的注释。


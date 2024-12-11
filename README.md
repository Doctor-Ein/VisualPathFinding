# Visual PathFing

- Developers:
  - TheEin
  - 未蒙
  - York
  - Simon

# 主题：迷宫求解算法的可视化
# 项目架构：
![画板](https://cdn.nlark.com/yuque/0/2024/jpeg/50620204/1733736557280-1c0d5a0c-484c-4dbe-8fad-58df5b3fc181.jpeg)

# 项目库使用文档
## 1. 概述
本项目提供了一个用于迷宫求解和可视化展示的库。它包括地图的表示、节点的定义以及地图的读取和打印功能。开发者可以基于这个库设计和实现自己的迷宫求解算法。

## 2. 库组成
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


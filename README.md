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
### 2.1 Node.h/Node.cpp
+ **描述**: 定义了迷宫中的节点（Node），包括节点的颜色、字符表示、坐标以及状态。
+ **功能**:
    - `SetColor(Color front, Color back)`: 设置节点的前景色和背景色。
    - `SetNumber(int num)`: 设置节点的数字表示，用于算法过程中的标记。
    - `SetUnicode(Unicode ch)`: 设置节点的 Unicode 字符表示。
    - `Output()`: 根据节点的状态输出字符或数字。

### 2.2 Map.h/Map.cpp
+ **描述**: 定义了地图（Map），包括地图的尺寸、起点和终点，以及地图上节点的储存和访问。
+ **功能**:
    - `ReadMap(string path)`: 从指定路径的文件中读取地图数据。
    - `PrintMap(ull t = 500)`: 打印地图的当前状态，`t`参数控制打印的延迟时间（毫秒）。

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
+ **Unicode使用方法：**`Unicode::CodeName`
+ 目前还没有实现真正的Unicode支持🥲 
+ 其实还是只支持ASCII，除了封装了一些，你们也可以自己查，然后直接把 0-127 的数字作为参数给`SetUnicode`

```cpp
enum class Unicode
{
    // RightArrow = 0x2192,     // →
    // LeftArrow = 0x2190,      // ←
    // UpArrow = 0x2191,        // ↑
    // DownArrow = 0x2193,      // ↓
    // NortheastArrow = 0x2197, // ↗
    // SoutheastArrow = 0x2198, // ↘
    // SouthwestArrow = 0x2199, // ↙
    // NorthwestArrow = 0x2196, // ↖
    Space = 0x0020,           // ' ' (空格)
    ExclamationMark = 0x0021, // '!' (感叹号)
    DoubleQuote = 0x0022,     // '"' (双引号)
    Hash = 0x0023,            // '#' (井号)
};
```

## 3. 使用方法
**摘要：就用三种节点Node的**`Set`**自定义对应节点，然后每一帧使用**`PrintMap`**输出一下就好啦，希望有很好的美术效果～**

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
+ 调用`SetColor`、`SetNumber`、`SetUnicode`函数来设置地图上你希望输出的内容，请发挥你们的想象力和审美观：

```cpp
void Solution_Name(Map& map) {
    map[i][j].SetColor(Color::White,Color::Black);
    map[i][j].SetNumber(6);
    // or map[i][j].SetUnicode(Unicode::Space);
    //输出结果为i,j位置的节点是黑底白字的数字6
}
```

+ 在完成了一帧图像的设置之后，请调用调用 `PrintMap` 函数来可视化展示迷宫的状态。

```cpp
// 完成这一帧地图颜色和输出的设置
map.PrintMap(); // 打印迷宫状态
```

## 4. 注意事项
+ 确保地图文件的格式正确，且与 `Map` 对象的尺寸相匹配。
+ `PrintMap` 函数中的延迟时间可能需要根据实际需求调整，以获得最佳的视觉效果。
+ 在设计算法时，合理使用 `Node` 类提供的方法来更新节点状态，以便在可视化展示中清晰地表示迷宫的状态。

## 5. 编译和运行
在编译时，确保包含了所有必要的头文件，并且链接了正确的库。如果使用了特定的系统调用（如 Windows 的 `windows.h` 或 Unix 的 `unistd.h`），确保在编译时指定了正确的编译选项。

如果电脑上有gcc的可以使用以下代码：`g++ -std=c++11 -o main Node.cpp Map.cpp main.cpp`

然后点击生成的可执行文件即可


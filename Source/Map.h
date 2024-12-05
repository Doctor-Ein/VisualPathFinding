#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#ifdef _WIN32
#include <io.h> // For _getch() and _isatty() on Windows
#else
#include <unistd.h> // For POSIX systems
#endif

using namespace std;

enum class Color
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97
};

void selectColor(Color color = Color::White);

class Map
{
private:
    int width, height;
    pair<int, int> S, E;
    vector<vector<Color>> val;

public:
    Map() : width(0), height(0) {}
    Map(int w, int h) : width(w), height(h)
    {
        val.resize(height, vector<Color>(width));
    }

    int getWidth() { return width; }    // 返回宽度
    int getHeight() { return height; }  // 返回高度
    pair<int, int> getS() { return S; } // 返回起点坐标对
    pair<int, int> getE() { return E; } // 返回终点坐标对，如果需要这个信息就可以调用

    int readMap(string map_path = "map.txt");
    void printMap(int ms = 500); // 参数是输出后想要休眠的时间（单位：毫秒），为你的Solution自定义
};

#endif

/*
 * 使用说明：
 *
 * 1. `Color` 枚举：
 *    `Color` 枚举类定义了多种颜色的 ANSI 转义码，可以用于设置输出的前景色和背景色。
 *    颜色列表：
 *      - Black
 *      - Red
 *      - Green
 *      - Yellow
 *      - Blue
 *      - Magenta
 *      - Cyan
 *      - White
 *      - BrightBlack
 *      - BrightRed
 *      - BrightGreen
 *      - BrightYellow
 *      - BrightBlue
 *      - BrightMagenta
 *      - BrightCyan
 *      - BrightWhite
 *
 * 2. `selectColor`
 *    `selectColor` 函数用于设置终端输出文本的颜色，使用 ANSI 转义序列进行控制。
 *    参数：`Color color`（默认值为 `Color::White`）
 *    用法：
 *      - `selectColor(Color::Red);` 将文本颜色设置为红色。
 *      - `selectColor(Color::Green);` 将文本颜色设置为绿色。
 *    **注意：** 使用此函数时，输出文本会受到 ANSI 转义序列控制，最终会显示指定颜色的文本或背景。
 *
 * 3. `Map` 类：
 *    `Map` 类表示一个二维地图，包含地图的宽度、高度、起点 `S` 和终点 `E` 的坐标，以及一个二维的颜色矩阵 `val` 用于表示地图上每个位置的颜色。
 *
 *    - `Map()`：默认构造函数，初始化一个空地图。
 *    - `Map(int w, int h)`：带参数的构造函数，初始化宽度为 `w`，高度为 `h` 的地图。
 *    - `int getWidth()`：返回地图的宽度。
 *    - `int getHeight()`：返回地图的高度。
 *    - `pair<int, int> getS()`：返回地图的起点坐标。
 *    - `pair<int, int> getE()`：返回地图的终点坐标。
 *
 *    - `void readMap()`：该函数用于读取并初始化地图数据（实现依赖于具体需求,从文件读取）。
 *    - `void printMap(int ms)`：该函数用于输出地图，并支持在输出后休眠 `ms` 毫秒，可以在调用时传入自定义的延迟时间，便于动画显示。
 *
 *
 * 4. 其他注意事项：
 *    - `selectColor` 函数的颜色控制使用 ANSI 转义序列，所以要确保你的终端支持该功能。
 *    - `Map` 类的 `printMap` 函数会根据给定的 `ms` 参数在每次输出后休眠一段时间，适合用在可视化或动画效果的实现中。
 *    - `Map` 类当前使用了一个二维的颜色矩阵 `val` 来存储每个位置的颜色信息，用户可以根据需要扩展 `readMap` 函数以支持不同的地图数据格式。
 *
 * 通过这些功能，用户可以创建一个带有颜色的地图表示，并可以根据需求动态调整地图显示。
 */

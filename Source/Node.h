#ifndef _NODE_H
#define _NODE_H

#define ull unsigned long long

#include <iostream>
#include <string>
using namespace std;

enum class Color
{
#ifdef _WIN32
    Black = 0,
    Red = 4,
    Green = 2,
    Yellow = 6,
    Blue = 1,
    Magenta = 5,
    Cyan = 3,
    White = 7,
    BrightBlack = 8, // 通常在 Windows 控制台中，8-15 并不总是表现为“亮色”
    BrightRed = 12,
    BrightGreen = 10,
    BrightYellow = 14,
    BrightBlue = 9,
    BrightMagenta = 13,
    BrightCyan = 11,
    BrightWhite = 15
#else
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
#endif
};

enum class Unicode
{
    RightArrow = 0x2192,     // →
    LeftArrow = 0x2190,      // ←
    UpArrow = 0x2191,        // ↑
    DownArrow = 0x2193,      // ↓
    NortheastArrow = 0x2197, // ↗
    SoutheastArrow = 0x2198, // ↘
    SouthwestArrow = 0x2199, // ↙
    NorthwestArrow = 0x2196, // ↖
    Space = 0x0020,          // ' '
    WrongMark = 0x0021       //'!'
};

class Node
{
private:
    Color Frontground;
    Color Background;
    char32_t ch32; // 用于存放unicode的字符类型
    int number;    // unicode的数字编码不便于运算
    int status;    // 管理输出数字还是输出unicode字符

public:
    int x, y; // 可公共访问的坐标

    Node() : Frontground(Color::White), Background(Color::Black), status(-1), number(-1), ch32(static_cast<char32_t>(Unicode::WrongMark)) {} //-1 表示此节点还未初始化

    inline void SetColor(Color _FrontColor, Color _BackColor);
    inline void SetNumber(int _num);
    inline void SetUnicode(Unicode _wch);
    void Output();
};

#endif
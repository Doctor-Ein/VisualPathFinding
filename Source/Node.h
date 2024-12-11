#ifndef _NODE_H
#define _NODE_H

#define ull unsigned long long

#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include "windows.h"
#else
#include "unistd.h"
#endif
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

class Node
{
private:
    Color Frontground;
    Color Background;
    int number; // unicode的数字编码不便于运算
    int status; // 管理输出模式

public:
    int x, y; // 可公共访问的坐标
    int step; // 可公共访问的另一个步数，呜呜疯狂给自己打补丁
    bool IsWall = false;
    bool flag = false; // 提供一个标记

    Node() : Frontground(Color::Black), Background(Color::White),
             status(-1), number(-1), step(-1) {} //-1 表示此节点还未初始化

    void setColor(Color _FrontColor = Color::Black, Color _BackColor = Color::White)
    {
        Frontground = _FrontColor;
        Background = _BackColor;
    }
    int getNumber() const { return number; }
    void setNumber(int _num)
    {
        number = _num;
        status = 0; // 输出数字模式
    }
    void Output();

    // operator=(const Node & _node)
    // {
    //     Frontground = _node.Frontground;
    //     Background = _node.Background;
    //     ch32 = _node.ch32;
    //     number = _node.number;
    //     status = _node.number;
    // }
};

#endif
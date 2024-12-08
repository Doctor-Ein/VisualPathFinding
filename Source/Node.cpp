#include "Node.h"
using namespace std;

inline void Node::SetColor(Color _FrontColor, Color _BackColor)
{
    Frontground = _FrontColor;
    Background = _BackColor;
}
inline void Node::SetNumber(int _num)
{
    number = _num;
    status = 1; // 数字模式
}
inline void Node::SetUnicode(Unicode _ch)
{
    ch32 = static_cast<char32_t>(_ch);
    status = 0; // unicode字符模式
}

void Node::Output()
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 设置控制台文本颜色
    SetConsoleTextAttribute(hConsole,
                            (static_cast<int>(Background) << 4) + static_cast<int>(Frontground));

    // 根据status的值输出数字或Unicode字符
    switch (status)
    {
    case -1:
        cout << " "; // 没有初始化默认输出空格
        break;
    case 0:
        cout << ch32;
        break;
    case 1:
        cout << number;
        break;
    default:
        cout << ch32;
        break;
    }

    // 重置控制台文本颜色
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
    cout << "\033[" << static_cast<int>(Frontground) << "m";     // 设置输出前景色
    cout << "\033[" << static_cast<int>(Background) + 10 << "m"; // 设置输出背景色
    switch (status)
    {
    case -1:
        cout << " "; // 没有初始化默认输出空格
        break;
    case 0:
        cout << ch32;
        break;
    case 1:
        cout << number;
        break;
    default:
        cout << ch32;
        break;
    }
    cout << "\033[0m"; // 恢复控制台颜色为默认
#endif
}
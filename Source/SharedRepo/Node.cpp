#include "Node.h"
using namespace std;

void Node::Output()
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 设置控制台文本颜色
    SetConsoleTextAttribute(hConsole,
                            (static_cast<int>(Background) << 4) + static_cast<int>(Frontground));

    // 根据status的值输出数字或者是空格
    if (!status)
    {
        cout << setw(2) << setfill(' ') << number;
    }
    else
    {
        cout << "  ";
    }
    // 重置控制台文本颜色
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
    cout << "\033[" << static_cast<int>(Frontground) << "m";     // 设置输出前景色
    cout << "\033[" << static_cast<int>(Background) + 10 << "m"; // 设置输出背景色

    // 根据status的值输出数字或者是空格
    if (!status)
    {
        cout << setw(2) << setfill(' ') << number;
    }
    else
    {
        cout << "  ";
    }

    cout << "\033[0m"; // 恢复控制颜色
#endif
}
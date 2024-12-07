#include "Map.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int Map::readMap(string map_path)
{
    ifstream file(map_path);
    if (!file.is_open())
    {
        cerr << "Error:Can't Open The File" << endl;
        return 1;
    }
    string line;
    for (int i = 0; i < height; i++)
    {
        getline(file, line);
        for (int j = 0; j < width; j++)
        {
            if (line[j] == '#')
            {
                val[i][j] = Color::Black;
            }
            else if (line[j] == ' ')
            {
                val[i][j] = Color::White;
            }
            else if (line[j] == 'S')
            {
                val[i][j] = Color::Green;
                S.first = i;
                S.second = j;
            }
            else if (line[j] == 'E')
            {
                val[i][j] = Color::Red;
                E.first = i;
                E.second = j;
            }
        }
    }
    file.close();
    return 0;
}

void Map::printMap(int ms) // 参数为想要休眠的毫秒时间，为你的Solution自定义
{
#ifdef _WIN32
    system("cls"); // Windows清屏命令
#else
    system("clear"); // Unix/Linux清屏命令
#endif
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            selectColor(val[i][j]);
            cout << " "; // 空格是我们的基本元素，因为背景色填充会比较满
        }
        cout << endl;
    }
#ifdef _WIN32
    Sleep（ms） // Windows
#else
    usleep(ms * 1000); // 休眠（Unix/Linux
#endif
}

void selectColor(Color color)
{
#ifdef _WIN32
    // Windows平台使用SetConsoleTextAttribute
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wColor = 0;
    switch (color)
    {
    case Color::Black:
        wColor = FOREGROUND_INTENSITY; // 深黑色近于灰色
        break;
    case Color::Red:
        wColor = FOREGROUND_RED;
        break;
    case Color::Green:
        wColor = FOREGROUND_GREEN;
        break;
    case Color::Yellow:
        wColor = FOREGROUND_RED | FOREGROUND_GREEN;
        break;
    case Color::Blue:
        wColor = FOREGROUND_BLUE;
        break;
    case Color::Magenta:
        wColor = FOREGROUND_RED | FOREGROUND_BLUE;
        break;
    case Color::Cyan:
        wColor = FOREGROUND_GREEN | FOREGROUND_BLUE;
        break;
    case Color::White:
        wColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        break;
    case Color::BrightBlack:
        wColor = FOREGROUND_INTENSITY;
        break;
    case Color::BrightRed:
        wColor = FOREGROUND_RED | FOREGROUND_INTENSITY;
        break;
    case Color::BrightGreen:
        wColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        break;
    case Color::BrightYellow:
        wColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        break;
    case Color::BrightBlue:
        wColor = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case Color::BrightMagenta:
        wColor = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case Color::BrightCyan:
        wColor = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case Color::BrightWhite:
        wColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    default:
        wColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // 默认白色
        break;
    }
    SetConsoleTextAttribute(hConsole, wColor);
#else
    // Unix-like平台使用ANSI escape codes
    cout << "\033[" << static_cast<int>(color) + 10 << "m";
#endif
}
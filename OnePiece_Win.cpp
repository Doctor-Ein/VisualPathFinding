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

void selectColor(Color color)
{
    // ANSI 转义序列格式：\033[<code>m
    cout << "\033[" << static_cast<int>(color) << "m"; // 全部改成背景色呜呜
}

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
    usleep(ms * 1000); // 休眠
}

#include <chrono> // 引入chrono库
#include <thread> // 引入std::this_thread::sleep_for()用于模拟延迟

using namespace std;
using namespace chrono;

int main()
{
    int w, h;
    cout << "Set the width of map:";
    cin >> w;
    cout << "\nSet the height of map:";
    cin >> h;
    Map shared_map(w, h);
    string map_path;
    cout << "\nThe Path to load the map:";
    while (shared_map.readMap(map_path))
    {
        cout << "Try again or quit by 'control+c'";
        cout << "\nThe Path to load the map:";
        cin >> map_path;
    }

    // 获取当前时间点（开始时间）
    auto start = high_resolution_clock::now();

    /*
        Solution Function:
    */
    shared_map.printMap(1000);

    // 获取当前时间点（结束时间）
    auto end = high_resolution_clock::now();

    // 计算算法的运行时间
    auto duration = duration_cast<milliseconds>(end - start); // 转换为毫秒

    // 输出运行时间
    cout << "算法运行时间： " << duration.count() << " 毫秒" << endl;

    return 0;
}
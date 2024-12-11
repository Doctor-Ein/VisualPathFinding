#include "Map.h"
#include <cassert>
using namespace std;

int Map::ReadMap(string path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cerr << "Error:Can't Open The File" << endl;
        return 1;
    }
    string line;
    for (int i = 0; i < width; i++)
    {
        getline(file, line);
        for (int j = 0; j < length; j++)
        {
            val[i][j].x = i;
            val[i][j].y = j;
            if (line[j] == '#')
            {
                val[i][j].setColor(Color::White, Color::Black);
                val[i][j].IsWall = true;
            }
            else if (line[j] == ' ')
            {
                val[i][j].setColor(Color::White, Color::White);
            }
            else if (line[j] == 'S')
            {
                val[i][j].setColor(Color::White, Color::Green);
                S.first = i;
                S.second = j;
            }
            else if (line[j] == 'E')
            {
                val[i][j].setColor(Color::White, Color::Red);
                E.first = i;
                E.second = j;
            }
        }
    }
    file.close();
    return 0;
}

void Map::PrintMap(ull t)
{
#ifdef _WIN32
    system("cls"); // Windows清屏命令
#else
    system("clear"); // Unix/Linux清屏命令
#endif
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            val[i][j].Output();
        }
        cout << endl;
    }
#ifdef _WIN32
    Sleep（t） // Windows
#else
    usleep(t * 1000); // Unix/Linux
#endif
}

bool Map::Islegal(int i, int j)
{

    assert(width == val.size() && (width > 0));
    assert(length == val[0].size() && (length > 0));

    if (i < 0 || i >= width || j < 0 || j >= length) // 检查索引是否合法
        return false;
    if (val[i][j].IsWall) // 检查是否为墙
        return false;
    return true;
}
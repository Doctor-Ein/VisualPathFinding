#include "Map.h"
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
    system("clear"); // 目前先只在MacOS上做适配，TODO：后期我会给Windows适配
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

void selectColor(Color color)
{
    // ANSI 转义序列格式：\033[<code>m
    cout << "\033[" << static_cast<int>(color) + 10 << "m"; // 全部改成背景色呜呜
}
#include "Map.h"
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
            if (line[j] == '#')
            {
                val[i][j].setColor(Color::White, Color::Black);
            }
            else if (line[j] == ' ')
            {
                val[i][j].setColor(Color::Black, Color::White);
            }
            else if (line[j] == 'S')
            {
                Start.setColor(Color::White, Color::Green);
                Start.x = i;
                Start.y = j;
                val[i][j] = Start;
            }
            else if (line[j] == 'E')
            {
                End.setColor(Color::White, Color::Red);
                End.x = i;
                End.y = j;
                val[i][j] = End;
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
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
#include <unistd.h> // 包含 sleep 函数
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(0, 1);
queue<pair<int, int>> searchQueue;

enum class Entity
{
    Wall = 0,
    Road = 1,
    Start = 2,
    End = 3,
    SearchHead = 10,
    Path = 4,
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool flag[12][12] = {false}; // 标记是否访问过
bool ff;

void setcolor(Entity entity)
{
    switch (entity)
    {
    case Entity::Wall:
        cout << "\033[40m"; // 黑色背景
        break;
    case Entity::Road:
        cout << "\033[107m"; // 白色背景
        break;
    case Entity::Start:
        cout << "\033[104m"; // 蓝色背景
        break;
    case Entity::End:
        cout << "\033[101m"; // 红色背景
        break;
    case Entity::SearchHead:
        cout << "\033[106m";
        break;
    default:
        cout << "\033[0m"; // 默认颜色
        break;
    }
}

class Map
{
public:
    int width, height;
    vector<vector<Entity>> val;

    Map(int _width, int _height) : width(_width), height(_height)
    {
        val.resize(height, vector<Entity>(width, Entity::Wall));
    }

    void printMap()
    {
        for (const auto &row : val)
        {
            for (Entity e : row)
            {
                setcolor(e);
                cout << " ";
                setcolor(Entity::Road); // 恢复为默认颜色
            }
            cout << endl;
        }
    }

    int Read()
    {
        ifstream file("map_1.txt");
        if (!file.is_open())
        {
            cerr << "无法打开文件！" << endl;
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
                    val[i][j] = Entity::Wall;
                }
                else if (line[j] == ' ')
                {
                    val[i][j] = Entity::Road;
                }
                else if (line[j] == 'S')
                {
                    val[i][j] = Entity::Start;
                }
                else if (line[j] == 'E')
                {
                    val[i][j] = Entity::End;
                }
            }
        }
        file.close();
        return 0;
    }
};

int main()
{
    // Map a(20, 27);
    Map a(10, 10);
    a.Read();
    a.printMap();
    usleep(500000);
    Solution_BFS.solve(a);
    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <random>
// #include <vector>
// #include <string>
// #include <queue>
// #include <cstdlib>
// #include <unistd.h> // 包含 sleep 函数
// using namespace std;

// random_device rd;
// mt19937 gen(rd());
// uniform_int_distribution<int> dist(0, 1);
// queue<pair<int, int>> head;

// enum class Entity // 枚举类，标识地图内的实体（组件）
// {
//     Wall, // 默认为0，之后递增
//     Road,
//     Start,
//     End
// };

// int dx[4] = {-1, 1, 0, 0};
// int dy[4] = {0, 0, -1, 1};
// bool flag[12][12];

// void setcolor(int v = -1)
// {
//     if (v == -1)
//     {
//         cout << "\033[0m";
//     }
//     else if (v == 0)
//     {
//         cout << "\033[40m";
//     }
//     else if (v == 1)
//     {
//         cout << "\033[107m";
//     }
//     else if (v == 10)
//     {
//         cout << "\033[106m";
//     }
// }

// class Map
// {
// public:
//     int width;
//     int height;
//     vector<vector<int>> val;
//     Map(int _width, int _height) : width(_width), height(_height)
//     {
//         // 使用给定的宽度和高度初始化二维 vector
//         val.resize(height, vector<int>(width, 0)); // 初始化所有值为 0
//     }

//     void printMap()
//     {
//         for (const auto &row : val)
//         {
//             for (int v : row)
//             {
//                 setcolor(v);
//                 cout << " ";
//                 setcolor();
//             }
//             cout << endl;
//         }
//     }
//     int Read()
//     {
//         // 创建一个输入文件流对象
//         ifstream file("map.txt");

//         // 检查文件是否成功打开
//         if (!file.is_open())
//         {
//             cerr << "无法打开文件！" << endl;
//             return 1; // 错误代码
//         }
//         string line;
//         // 逐行读取文件内容

//         for (int i = 0; i < height; i++)
//         {
//             getline(file, line);
//             for (int j = 0; j < width; j++)
//             {
//                 if (line[j] == '#')
//                 {
//                     val[i][j] = 0;
//                 }
//                 else if (line[j] == ' ')
//                 {
//                     val[i][j] = 1;
//                 }
//                 else
//                 {
//                     val[i][j] = -1;
//                 }
//             }
//         }
//         // 关闭文件
//         file.close();
//         return 0;
//     }
// };

// int main()
// {
//     Map a(10, 10);
//     a.Read();
//     a.printMap();
//     head.emplace(4, 1);
//     while (!head.empty())
//     {
//         pair<int, int> cur = head.front();
//         head.pop();
//         int x = cur.first;
//         int y = cur.second;
//         int tx, ty;
//         for (int i = 0; i < 4; i++)
//         {
//             tx = x + dx[i];
//             ty = y + dy[i];
//             if (tx >= 0 && tx < a.height && ty >= 0 && ty < a.width && a.val[tx][ty] != 0 && a.val[tx][ty] != 10)
//             {
//                 head.emplace(tx, ty);
//                 flag[tx][ty] = true;
//                 a.val[tx][ty] = 10;
//             }
//         }
//         system("clear");
//         a.printMap();
//         usleep(500000);
//     }
//     return 0;
// }
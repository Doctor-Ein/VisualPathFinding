#include "Map.h"
#include "GlobalMap.h"
#include <queue>
#include <cmath>
using namespace std;

Map my_map = globalMap; // 通过globalmap复制，避免修改公共资源叭～

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return my_map.val[a.first][a.second].getNumber() > my_map.val[b.first][b.second].getNumber();
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> SearchQueue;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

inline int CalDistance(const Node &a, const Node &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// bool test(int tx, int ty, Map my_map)
// {
//     if (my_map.Islegal(tx, ty))
//     {
//         cout << "Islegal Pass!" << endl;
//     }
//     return true;
// }

void Solution_Astar()
{
    Node &Start = my_map.Start;
    Node &End = my_map.End;
    Start.setNumber(0 + CalDistance(Start, End));
    SearchQueue.emplace(Start.x, Start.y);

    while (!SearchQueue.empty())
    {
        int ttx = SearchQueue.top().first; // 为了实际修改地图中的Node，通过坐标来实际访问地图
        int tty = SearchQueue.top().second;
        SearchQueue.pop();

        my_map.val[ttx][tty].flag = true;                         // 标记为走过
        my_map.val[ttx][tty].setColor(Color::White, Color::Cyan); // 已经走过的地方是浅青色
        if (my_map.val[ttx][tty].x == End.x && my_map.val[ttx][tty].y == End.y)
        {
            // Backtrack();
            my_map.PrintMap();
            cout << "SearchOver!" << endl;
            break;
        }
        int temp_cost = CalDistance(my_map.val[ttx][tty], End);
        // for (int k = 0; k < 4; k++) // 尝试探索四个方向
        // {
        //     int tx = my_map.val[ttx][tty].x + dx[k];
        //     int ty = my_map.val[ttx][tty].y + dy[k];
        //     if (my_map.Islegal(tx, ty) && !my_map.val[tx][ty].flag)
        //     {
        //         Node &next = my_map.val[tx][ty];
        //         next.setColor(Color::White, Color::BrightBlue);
        //         next.setNumber(my_map.val[ttx][tty].getNumber() - temp_cost + 1 + CalDistance(next, End));
        //         SearchQueue.push(next);
        //     }
        // }
        int k = 2;
        int tx = my_map.val[ttx][tty].x + dx[k];
        int ty = my_map.val[ttx][tty].y + dy[k];
        if (my_map.Islegal(tx, ty) && !my_map.val[tx][ty].flag)
        {
            Node &next = my_map.val[tx][ty];
            next.setColor(Color::White, Color::BrightBlue);
            next.setNumber(my_map.val[ttx][tty].getNumber() - temp_cost + 1 + CalDistance(next, End));
            SearchQueue.emplace(tx, ty);
        }
        usleep(1000000);
        my_map.PrintMap();
    }
}
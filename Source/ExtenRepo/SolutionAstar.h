#include "../SharedRepo/Map.h"
#include "../SharedRepo/GlobalMap.h"
#include <queue>
#include <cmath>
using namespace std;

Map my_map; // 稍后通过globalmap复制，避免修改公共资源叭～woc,全局的这里是直接替换！！！

inline int CalDistance(const Node &a, const Node &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        // if (my_map.val[a.first][a.second].getNumber() == my_map.val[b.first][b.second].getNumber())
        // {
        //     return CalDistance(my_map.val[a.first][a.second], my_map.val[my_map.E.first][my_map.E.second]) > CalDistance(my_map.val[b.first][b.second], my_map.val[my_map.E.first][my_map.E.second]);
        // }
        return my_map.val[a.first][a.second].getNumber() > my_map.val[b.first][b.second].getNumber();
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> SearchQueue;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// bool test(int tx, int ty, Map my_map)
// {
//     if (my_map.Islegal(tx, ty))
//     {
//         cout << "Islegal Pass!" << endl;
//     }
//     return true;
// }

void Backtrace(int x, int y)
{
    if (x == my_map.S.first && y == my_map.S.second)
    {
        my_map.val[x][y].setColor(Color::White, Color::BrightYellow);
        my_map.PrintMap(50); // 加速展示
        // cout << "S.first=" << my_map.S.first << "S.second=" << my_map.S.second << endl;
        // cerr << "Backtrace Over!" << endl;
        // sleep(1);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int tx = my_map.val[x][y].x + dx[k];
        int ty = my_map.val[x][y].y + dy[k];
        if (my_map.Islegal(tx, ty) && my_map.val[tx][ty].step == my_map.val[x][y].step - 1)
        {
            Backtrace(tx, ty);
            my_map.val[x][y].setColor(Color::White, Color::BrightYellow);
            my_map.PrintMap(40);
            return; // 找到就返回,就只会有一个回溯路径
        }
    }
}

void Solution_Astar()
{
    my_map = globalMap; // woccccc!!!!!太炸裂的bug啊啊啊啊啊我要升天了！
    // cout << my_map.S.first << endl; // 真的吐了，为啥啊？？？
    // my_map.PrintMap();
    Node &Start = my_map.val[my_map.S.first][my_map.S.second];
    Node &End = my_map.val[my_map.E.first][my_map.E.second];
    Start.step = 0;
    Start.setNumber(Start.step + CalDistance(Start, End));
    SearchQueue.emplace(Start.x, Start.y);
    while (!SearchQueue.empty())
    {
        int ttx = SearchQueue.top().first; // 为了实际修改地图中的Node，通过坐标来实际访问地图
        int tty = SearchQueue.top().second;
        // cout << ttx << " " << tty << endl; // 为啥输出是0^0，啊啊啊气死啦
        SearchQueue.pop();
        my_map.val[ttx][tty].flag = true;                         // 标记为走过
        my_map.val[ttx][tty].setColor(Color::White, Color::Cyan); // 已经走过的地方是浅青色
        if (my_map.val[ttx][tty].x == End.x && my_map.val[ttx][tty].y == End.y)
        {
            Backtrace(End.x, End.y);
            my_map.PrintMap(50);
            break;
        }
        int temp_cost = CalDistance(my_map.val[ttx][tty], End);
        for (int k = 0; k < 4; k++) // 尝试探索四个方向
        {
            int tx = my_map.val[ttx][tty].x + dx[k];
            int ty = my_map.val[ttx][tty].y + dy[k];
            if (my_map.Islegal(tx, ty) && !my_map.val[tx][ty].flag)
            {
                my_map.val[tx][ty].setColor(Color::White, Color::Blue);
                my_map.val[tx][ty].step = my_map.val[ttx][tty].step + 1;
                my_map.val[tx][ty].setNumber(my_map.val[tx][ty].step + CalDistance(my_map.val[tx][ty], End)); // 计算新节点的代价,悄悄加一点系数权重
                SearchQueue.emplace(tx, ty);
            }
        }
        my_map.PrintMap(50);
    }
}
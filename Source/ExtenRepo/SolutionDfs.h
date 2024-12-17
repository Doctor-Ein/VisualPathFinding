#ifndef _SOLUTION_DFS_H
#define _SOLUTION_DFS_H // 老蓝，这是危险的重名！
#include <iostream>
#include "../SharedRepo/Map.h"
#include "../SharedRepo/GlobalMap.h"
using namespace std;
// dfs
//     轮流以右下左上的顺序探路，符合下一个不是墙且没走过就进入下一步
//     递归形式，在到达出口之后弹出，配合回溯时清理，可以得到唯一路径
//     进入递归时首先涂蓝，进入下一步则当前涂青，碰墙回溯沿途涂红
//     最后用printPath打印一条黄色路径

bool flag = false;

class SolutionDfs
{
private:
    Map localMap;
    bool mark[100][100]; // 标记有没有走过的map
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    SolutionDfs(Map m) : localMap(m), mark{0} {}
    void solutionDfs(int, int);
    // void printPath() const;
};

void SolutionDfs::solutionDfs(int x, int y)
{
    if (x == localMap.E.first && y == localMap.E.second)
    {
        // char s;
        // cin >> s; // woccc被自己坑了一手
        // exit(0);老蓝啊，这样真是不好啊
        flag = true;
        return;
    }
    localMap.val[x][y].setColor(Color::Black, Color::Cyan); // 0是black,1是blue
    localMap.PrintMap(60);
    int dx, dy;
    for (int i = 0; i < 4; i++)
    {
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if (localMap.Islegal(dx, dy) && mark[dx][dy] == 0)
        {
            mark[dx][dy] = 1;
            localMap.val[dx][dy].setColor(Color::Black, Color::Blue);
            // localMap.PrintMap(60);这个是不是和紧接着的递归的打印地图重叠了
            solutionDfs(dx, dy);
            if (flag) // 咱们也就是尽量保持原状了
            {
                return;
            }
            localMap.val[dx][dy].setColor(Color::Black, Color::Magenta);
            localMap.PrintMap(20); // 来一个回溯加速叭～
            mark[dx][dy] = 0;
        }
    }
}
#endif
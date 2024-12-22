#include <queue>
#include <utility>
#include <map>
#include "../SharedRepo/Map.h"
#include "../SharedRepo/GlobalMap.h"
using namespace std;

Map globalMap(30, 30);
Map m_may; // 保留一个教训

void Solution_BFS()
{
    m_may = globalMap;
    int sX = m_may.S.first, sY = m_may.S.second;
    int nX = m_may.E.first, nY = m_may.E.second;
    queue<pair<int, int>> q;
    q.push({sX, sY});
    m_may.val[sX][sY].flag = true;
    m_may.val[sX][sY].step = 0; // 初始化起点的步数为0
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    map<pair<int, int>, pair<int, int>> par;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int dist = m_may.val[x][y].step; // 获取当前点到起点的距离
        Color color;
        if (dist < 10)
            color = Color::BrightRed; // 0-14 步内为亮红色
        else if (dist < 20)
            color = Color::BrightYellow; // 15-29 步内为亮黄色
        else if (dist < 30)
            color = Color::BrightBlue; // 30-44 步内为亮蓝色
        else if (dist < 40)
            color = Color::BrightMagenta; // 45-59 步内为亮品红色
        else if (dist < 50)
            color = Color::BrightCyan; // 60-74 步内为亮青色
        else
            color = Color::BrightGreen; // 75 步以上为亮绿色
        m_may.val[x][y].setColor(Color::Black, color);
        m_may.PrintMap(60);
        if (x == nX && y == nY)
        {
            m_may.val[x][y].setColor(Color::Black, Color::Blue);
            m_may.PrintMap(60);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (m_may.Islegal(nx, ny) && !m_may.val[nx][ny].flag)
            {
                m_may.val[nx][ny].flag = true;
                m_may.val[nx][ny].step = m_may.val[x][y].step + 1;
                m_may.val[nx][ny].setColor(Color::Black, color); // 设置新点的颜色
                q.push({nx, ny});
                par[{nx, ny}] = {x, y};
            }
        }
    }
}

int main()
{
    globalMap.ReadMap("../createmap.txt");
    globalMap.PrintMap(); // 地图展示
    Solution_BFS();
    return 0;
}
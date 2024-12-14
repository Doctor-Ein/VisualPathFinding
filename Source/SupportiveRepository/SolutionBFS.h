#include "GlobalMap.h"
#include <queue>
#include <utility>
#include <map>
#include "Map.h"
#include "Node.h"
using namespace std;

Map m_may; // 保留一个教训

void Solution_BFS()
{
    m_may = globalMap;
    int sX = m_may.S.first, sY = m_may.S.second;
    int nX = m_may.E.first, nY = m_may.E.second;
    queue<pair<int, int>> q;
    q.push({sX, sY});
    m_may.val[sX][sY].flag = true;
    m_may.val[sX][sY].setColor(Color::Black, Color::Green);
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    map<pair<int, int>, pair<int, int>> par;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        m_may.val[x][y].setColor(Color::Black, Color::Cyan);
        m_may.PrintMap(60);
        if (x == nX && y == nY)
        {
            m_may.val[x][y].setColor(Color::Black, Color::Blue);
            pair<int, int> cur = {x, y};
            int cnt = 3;
            while (cur != make_pair(sX, sY))
            {
                m_may.val[cur.first][cur.second].setColor(Color::Black, Color::Yellow);
                cur = par[cur];
                cnt++;
                if (cnt % 2 == 0)
                {
                    cnt = 0;
                    m_may.PrintMap(40);
                }
            }
            m_may.val[sX][sY].setColor(Color::Black, Color::Green);
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
                q.push({nx, ny});
                par[{nx, ny}] = {x, y};
            }
        }
    }
}

#include "Map.h"
#include "Solution.h"
#include "GlobalMap.h"
#include "PrintFunction.h"
#include <chrono>

using namespace std;
using namespace chrono;

Map globalMap(30, 30);

int main()
{
    globalMap = Map(30, 30); // 总之似乎是要求这样写了，setMap没有任何用处呜呜哇
    globalMap.ReadMap("createmap.txt");
    // printLargeAstar();
    // sleep(1);
    globalMap.PrintMap(); // 地图展示

    auto start = high_resolution_clock::now(); // 获取当前时间点（开始时间）

    Solution_Astar();

    auto end = high_resolution_clock::now(); // 获取当前时间点（结束时间）

    auto duration = duration_cast<milliseconds>(end - start); // 计算算法的运行时间,转换为毫秒

    cout << "算法运行时间： " << duration.count() << " 毫秒" << endl;
    return 0;
}
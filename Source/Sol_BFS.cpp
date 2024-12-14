#include "Map.h"
#include "SolutionBFS.h"
#include "GlobalMap.h"
#include "AsciiArt.h"
#include <chrono>

using namespace std;
using namespace chrono;

Map globalMap(30, 30);

int main()
{
    globalMap.ReadMap("createmap.txt");
    globalMap.PrintMap(); // 地图展示

    auto start = high_resolution_clock::now(); // 获取当前时间点（开始时间）

    Solution_BFS();
    printArtFromFile("./ASCII ART/BFS.txt");

    auto end = high_resolution_clock::now(); // 获取当前时间点（结束时间）

    auto duration = duration_cast<milliseconds>(end - start); // 计算算法的运行时间,转换为毫秒

    cout << "算法运行时间： " << duration.count() << " 毫秒" << endl;
    return 0;
}
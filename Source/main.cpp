#include "Map.h"
#include <chrono> // 引入chrono库
#include <thread> // 引入std::this_thread::sleep_for()用于模拟延迟

using namespace std;
using namespace chrono;

int main()
{
    int len, wid;
    cout << "Set the length of map:";
    cin >> len;
    cout << "Set the width of map:";
    cin >> wid;
    Map shared_map(len, wid);
    string map_path;
    cout << "The Path to load the map:";
    cin >> map_path;
    while (shared_map.ReadMap(map_path))
    {
        cout << "Try again or quit by 'control+c' ";
        // TODO: HelpDocument Here.
        cout << "\nThe Path to load the map:";
        cin >> map_path;
    }
    // 以上是地图初始化部分，
    // 算法可视化展示和性能测试部分，TODO：多线程多窗口比较～
    //----------------------------------------------------------------

    // 获取当前时间点（开始时间）
    auto start = high_resolution_clock::now();
    /*
        Solution Function:
    */
    shared_map.PrintMap();

    auto end = high_resolution_clock::now(); // 获取当前时间点（结束时间）

    auto duration = duration_cast<milliseconds>(end - start); // 计算算法的运行时间,转换为毫秒

    // 输出运行时间,这里大家返回一下自己算法的名字和写算法的组员名字
    cout << "算法运行时间： " << duration.count() << " 毫秒" << endl;
    // TODO：总结数据统计，得一个结论，然后记得多轮重复实验？还真得多线程？？？
    return 0;
}
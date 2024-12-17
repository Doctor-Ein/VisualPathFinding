#ifndef _MAP_H
#define _MAP_H

#include "Node.h"
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stdlib.h>

class Map
{
private:
    int length, width;

public:
    vector<vector<Node>> val; // 当你觉得不如直接公开访问的时候，还是public叭
    pair<int, int> S, E;      // 起点和终点的坐标对

    Map(int len = 1, int wid = 1, pair<int, int> start = {0, 0}, pair<int, int> end = {0, 0})
        : length(len), width(wid), S(start), E(end)
    {
        val.resize(width, vector<Node>(length));
    }
    Map(const Map &other) : length(other.length), width(other.width)
    {
        val.resize(width, vector<Node>(length));
        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < length; ++j)
            {
                val[i][j] = other.val[i][j]; // 调用 Node 的赋值运算符
            }
        }
        S = other.S;
        E = other.E;
    }

    void setMap(int len, int wid)
    {
        length = len;
        width = wid;
        val.resize(width, vector<Node>(length));
    }
    int ReadMap(string path);
    void PrintMap(ull t = 200); // 毫秒 ms
    bool Islegal(int i, int j); // 判断这一步在地图上看是否合法
};

#endif
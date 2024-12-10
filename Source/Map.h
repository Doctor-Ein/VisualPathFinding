#ifndef _MAP_H
#define _MAP_H

#include "Node.h"
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stdlib.h>

#ifdef _WIN32
#include "windows.h"
#else
#include "unistd.h"
#endif

class Map
{
private:
    int length, width;

public:
    vector<vector<Node>> val; // 当你觉得不如直接公开访问的时候，还是public叭
    Node Start, End;

    Map(int len = 0, int wid = 0) : length(len), width(wid)
    {
        val.resize(width, vector<Node>(length));
    }

    void setMap(int len, int wid)
    {
        length = len;
        wid = width;
        val.resize(width, vector<Node>(length));
    }
    int ReadMap(string path);
    void PrintMap(ull t = 500); // 毫秒 ms
    bool Islegal(int i, int j); // 判断这一步在地图上看是否合法
};

#endif
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
    Node Start, End;
    vector<vector<Node>> val;

public:
    Map(int len, int wid) : length(len), width(wid)
    {
        val.resize(width, vector<Node>(length));
    }

    int ReadMap(string path);
    void PrintMap(ull t = 500); // 毫秒 ms
};

#endif
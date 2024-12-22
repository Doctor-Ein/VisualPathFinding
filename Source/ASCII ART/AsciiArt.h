#include <iostream>
#include <fstream>
#include <string>
#include <thread> // 用于延迟
#include <chrono> // 用于延迟的时间类型

// 函数：从文件中读取字符画并打印
void printArtFromFile(const std::string &filename, int delay_ms = 200)
{
    std::ifstream file(filename); // 打开文件
    if (!file.is_open())          // 检查文件是否成功打开
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) // 按行读取文件内容
    {
        std::cout << line << std::endl;                                   // 输出当前行
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms)); // 延迟
    }

    file.close(); // 关闭文件
}
#include <iostream>
#include <thread> // 用于延迟
#include <chrono> // 用于延迟的时间类型

// 函数：打印大字符画"Astar"
void printLargeAstar()
{
    // 字母 "A" 的字符画
    std::string A[] = {
        "      /\\        ",
        "     // \\       ",
        "    //   \\      ",
        "   //-----\\     ",
        "  //       \\    ",
        " //         \\   ",
        "//           \\  "};

    // 字母 "S" 的字符画
    std::string S[] = {
        "  ///////      ",
        " //           ",
        " \\            ",
        "  \\\\\\\\       ",
        "       \\      ",
        "        \\     ",
        "  ////////     "};

    // 字母 "T" 的字符画
    std::string T[] = {
        "  ########    ",
        "     ||       ",
        "     ||       ",
        "     ||       ",
        "     ||       ",
        "     ||       ",
        "     ||       "};

    // 字母 "R" 的字符画
    std::string R[] = {
        "  #######     ",
        "  #     #     ",
        "  #     #     ",
        "  #######     ",
        "  #   #       ",
        "  #    #      ",
        "  #     #     "};

    // 输出"Astar"的字符画，确保对齐
    for (int i = 0; i < 7; ++i)
    {
        std::cout << A[i] << "   " << S[i] << "   " << T[i] << "   " << R[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 每行延迟500毫秒
    }
}

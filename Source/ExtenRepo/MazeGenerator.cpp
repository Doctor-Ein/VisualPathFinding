#include "../SharedRepo/Map.h"
#include "MazeGenerator.h"
#include "../ASCII ART/AsciiArt.h"
#include <string>

using namespace std;

int main()
{
    printArtFromFile("./ASCII ART/MazeGenerator.txt", 200);
    int L;
    cout << "Please input the size of your map(square):";
    cin >> L;
    string path_to_store;
    cout << "Please input \033[1mthe path to store your map\033[0m or using createmap.txt by defualt:" << endl;
    cin >> path_to_store;
    MazeGenerate(path_to_store, L);
    return 0;
}
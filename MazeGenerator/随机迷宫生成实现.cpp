#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	// 设置种子
	srand(static_cast<unsigned int>(time(nullptr)));
	// 确定行列数
	const int L = 30;
	int arr[42][42];
	// 1为墙，0为路，并且在正式的迷宫外在套上一圈代表路的0，后续会去掉
	for (int i = 0; i < L + 2; i++)
	{
		for (int j = 0; j < L + 2; j++)
		{
			if (i == 0 || i == L + 1 || j == 0 || j == L + 1)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 1;
			}
		}
	}
	// 任取起点位置
	const int start = rand() % (L - 2) + 2;
	arr[start][1] = 0;
	// 设置坐标的左下上右
	int Xchange[4] = {0, 1, -1, 0};
	int Ychange[4] = {-1, 0, 0, 1};
	// 储存等待检验是否可以为通路的坐标
	vector<int> X;
	vector<int> Y;
	// 设置初始值（入口右侧的一个必为通路）
	Y.push_back(2);
	X.push_back(start);
	// 当不再有可能的通路时循环结束
	while (X.size())
	{
		// 任取其中一个可能为通路的坐标
		int r = rand() % X.size();
		int x = X[r];
		int y = Y[r];
		int countxy = 0;
		// 判断是否可以为通路
		for (int i = 0; i < 4; i++)
		{
			if (arr[x + Xchange[i]][y + Ychange[i]] == 0)
				countxy++;
		}
		if (countxy < 2)
		{
			arr[x][y] = 0;
			// 在可以为通路的基础上看上下左右的墙
			for (int i = 0; i < 4; i++)
			{
				if (arr[x + Xchange[i]][y + Ychange[i]] > 0)
				{
					int count = 0;
					for (int k = 0; k < 4; k++)
					{
						if (arr[x + Xchange[i] + Xchange[k]][y + Ychange[i] + Ychange[k]] == 0)
							count++;
					}
					// 若该墙可能为通路则将坐标加入数组中
					if (count < 2)
					{
						X.push_back(x + Xchange[i]);
						Y.push_back(y + Ychange[i]);
					}
				}
			}
		}
		// 去除已经处理过的坐标
		X.erase(X.begin() + r);
		Y.erase(Y.begin() + r);
	}
	// 找到出口
	int point = 2;
	while (point < L)
	{
		if (arr[point][L - 1] == 0)
		{
			X.push_back(point);
		}
		point++;
	}
	int r = rand() % X.size();
	arr[X[r]][L] = 0;
	// 设置txt文件并输出
	ofstream outFile("createmap.txt");
	for (int i = 1; i < L + 1; i++)
	{
		for (int j = 1; j < L + 1; j++)
		{
			if (i == start && j == 1)
			{
				outFile << "S";
			}
			else if (i == X[r] && j == L)
			{
				outFile << "E";
			}
			else if (arr[i][j] == 0)
			{
				outFile << " ";
			}
			else
			{
				outFile << "#";
			}
		}
		outFile << endl;
	}
	outFile.close();
	return 0;
}

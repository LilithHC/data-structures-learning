#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include "maze.h"
using namespace std;
void work()
{
	bool command = true;
	do
	{
		Maze A;
		int kind, n;
		cout << "请选择迷宫生成方式 (1 自动 0 手动) 和 迷宫方阵大小：";	cin >> kind >> n;
		A.initialize(kind, n);
		A.printans();
		cout << "\n请选择是否继续游戏 1 继续 0 结束" << endl; cin >> command;
	} while (command);
}
void introduction()
{
	cout << "\n  欢迎进入迷宫求解游戏！" << endl
		<< "一般的迷宫可表示为一个二维平面图形，将迷宫的左上角作为入口，右下角作为出口。迷宫问题求解的目标是寻找一条从入口点到出口点的通路。" << endl
		<< "设“0”为通路，“1”为墙。可向“上、下、左、右、左上、左下、右上、右下”8个方向行走。" << endl
		<< "本程序，能自动生成或手动生成一个用户确定大小的方阵，判断能否从起点经过迷宫走到终点。如果能，给出一种走出迷宫的路径。" << endl << endl;
}
/*
一般的迷宫可表示为一个二维平面图形，将迷宫的左上角作为入口，右下角作为出口。迷宫问题求解的目标是寻找一条从入口点到出口点的通路。
例如，可设计一个8×8矩阵maze[8][8]来表示迷宫，如下所示
0	1	0	0	0	0	1	1
0	0	0	1	0	0	1	0
1	0	1	0	1	0	1	1
1	0	1	0	1	1	0	1
0	1	1	1	1	1	1	0
1	0	0	1	1	0	0	0
1	0	1	0	0	0	1	1
1	0	1	1	0	1	0	0
左上角maze[0][0]为起点，右下角maze[7][7]为终点；设“0”为通路，“1”为墙。假设一只老鼠从起点出发，目的为右下角的终点，可向“上、下、左、右、左上、左下、右上、右下”8个方向行走。
设计一个程序，能自动生成或手动生成一个8×8矩阵，针对这个矩阵，程序判断能否从起点经过迷宫走到终点。如果能，请给出一种走出迷宫的路径。
*/
int main()
{
	srand((unsigned int)time(NULL));
	introduction();
	work();
	return 0;
}

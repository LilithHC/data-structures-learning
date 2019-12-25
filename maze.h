#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
class Maze {
public:
	void initialize(int kind,int size);//初始化迷宫并从起点开始寻找路径
	void printans();//输出结果

private:
	void solve(int x, int y);		   //辅助函数
	int n;		//迷宫的大小
	bool findans;
	vector<pair<int, int> >path;				//路径
	int dis[10][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0}, {1,1} };//八个连通方向
	char maze[100][100];	 //迷宫图形
};

void Maze::initialize(int kind, int size)						//初始化迷宫
{
	n = size;
	findans = false;
	path.clear();
	path.push_back(make_pair(0, 0));//添加起点到路径中
	if (kind)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				int x = rand() % 2;
				maze[i][j] = '0' + x;
			}
		maze[0][0] = maze[n - 1][n - 1] = '0';
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cout << maze[i][j];
				j == n - 1 ? cout << endl : cout << " ";
			}
	}
	else
	{
		cout << "请输入迷宫：";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> maze[i][j];
	}
	solve(0, 0);
}

void Maze::solve(int x, int y)
{
	if (x == n - 1 && y == n - 1)
	{
		findans = true;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int nextx = x + dis[i][0]; int nexty = y + dis[i][1];
		pair<int, int> nextpos = make_pair(x + dis[i][0], y + dis[i][1]);
		if (nextx < 0 || nextx>n - 1 || nexty < 0 || nexty>n - 1 || maze[nextx][nexty] == '1' || find(path.begin(), path.end(), nextpos) != path.end()) continue;
		path.push_back(nextpos);
		solve(nextx, nexty);
		if (findans)	 return;
		path.pop_back();
	}
}
void Maze::printans()
{
	if (findans)
	{
		cout << "走出迷宫的一条路径为：";
		for (vector<pair<int, int> >::iterator itt = path.begin(); itt != path.end(); itt++)
			cout << "(" << itt->first << "," << itt->second << ")" << " ";
	}
	else
	{
		cout << "不存在路径！";
	}

}
//void work()
//{
//	bool command = true;
//	do
//	{
//		Maze A;
//		int kind,n;
//		cout << "请选择迷宫生成方式 (1 自动 0 手动) 和 迷宫方阵大小：";	cin >> kind >> n;
//		A.initialize(kind, n);
//		A.printans();
//		cout << "\n请选择是否继续游戏 1 继续 0 结束" << endl; cin >> command;
//	} while (command);
//}
//


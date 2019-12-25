#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
class Maze {
public:
	void initialize(int kind,int size);//��ʼ���Թ�������㿪ʼѰ��·��
	void printans();//������

private:
	void solve(int x, int y);		   //��������
	int n;		//�Թ��Ĵ�С
	bool findans;
	vector<pair<int, int> >path;				//·��
	int dis[10][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0}, {1,1} };//�˸���ͨ����
	char maze[100][100];	 //�Թ�ͼ��
};

void Maze::initialize(int kind, int size)						//��ʼ���Թ�
{
	n = size;
	findans = false;
	path.clear();
	path.push_back(make_pair(0, 0));//�����㵽·����
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
		cout << "�������Թ���";
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
		cout << "�߳��Թ���һ��·��Ϊ��";
		for (vector<pair<int, int> >::iterator itt = path.begin(); itt != path.end(); itt++)
			cout << "(" << itt->first << "," << itt->second << ")" << " ";
	}
	else
	{
		cout << "������·����";
	}

}
//void work()
//{
//	bool command = true;
//	do
//	{
//		Maze A;
//		int kind,n;
//		cout << "��ѡ���Թ����ɷ�ʽ (1 �Զ� 0 �ֶ�) �� �Թ������С��";	cin >> kind >> n;
//		A.initialize(kind, n);
//		A.printans();
//		cout << "\n��ѡ���Ƿ������Ϸ 1 ���� 0 ����" << endl; cin >> command;
//	} while (command);
//}
//


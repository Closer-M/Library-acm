#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<fstream>
#include<stdio.h>
using namespace std;
int T, head, tail, n, sum = 0;
int road[101][101];
int book[101][101] = { 0 };
int mini[101];
void dfs(int step)
{
	int r = 0;
	for (int i = 1; i <= T; i++)
	{
		if (book[step][i] == 1)
		{
			r = 1;
		}
	}
	if (r == 0)
	{
		return;
	}
	for (int i = 1; i <= T; i++)  //尝试每一种可能 
	{
		if (book[step][i] == 1)
		{
			sum += road[step][i];
			if (sum < mini[i])
			{
				mini[i] = sum;
			}
			book[step][i] = 0;
			dfs(i);
			sum -= road[step][i];
			book[step][i] = 1;
		}
	}
	return;
}
int main()
{
	for (int i = 0; i < 101; i++)
	{
		mini[i] = 9999;
	}
	cout << "输入点数：";
	cin >> n;
	cout << "输入路径的数量：";
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "输入路径:";
		cin >> head;
		cin >> tail;
		cin >> road[head][tail];
		book[head][tail] = 1;
	}
	dfs(1);
	mini[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		cout << mini[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
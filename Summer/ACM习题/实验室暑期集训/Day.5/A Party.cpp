#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
using namespace std;
//建立表头 head 制作邻接表
int head[6010], ver[6010], nxt[6010], step = 0;
int f[6010][2];
void add(int fa, int son)//每一次插入一个元素
{
	step++;//记录插入点的信息的所在位置
	ver[step] = son;//记录这个点的编号
	nxt[step] = head[fa];//从表头处将前一个点的指针承接过来
	head[fa] = step;//在表头处设定一个指针指向现在的元素
}
void dfs(int n)
{
	for (int i = head[n]; i; i = nxt[i])//将 n 为父节点的所有子节点历遍
	{
		int pre = ver[i];
		dfs(pre);//以这个子节点为父节点继续进行深搜
		//在 dfs(pre) 进行深搜后在输入运算相当于进行了一次回溯
		f[n][1] += f[pre][0];//动态规划的过程
		f[n][0] += max(f[pre][0], f[pre][1]);
	}
}
int list[6010];
int find(int i)
{
	if (list[i] == i)
	{
		return i;
	}
	else
	{
		find(list[i]);
	}
}
int main()
{
	int T;
	while (cin >> T)
	{
		for (int i = 1; i < T; i++)
		{
			list[i] = i;
		}
		memset(head, 0, sizeof(head));
		memset(ver, 0, sizeof(ver));
		memset(nxt, 0, sizeof(nxt));
		memset(f, 0, sizeof(f));
		step = 0;
		for (int i = 1; i <= T; i++)
		{
			cin >> f[i][1];
		}
		for (int i = 1; i <= T; i++)
		{
			int a, b;
			cin >> a >> b;
			list[a] = b;
			add(b, a);
		}
		int h = find(1);
		dfs(h);
		cout << max(f[h][1], f[h][0]) << endl;
	}


	system("pause");
	return 0;
}
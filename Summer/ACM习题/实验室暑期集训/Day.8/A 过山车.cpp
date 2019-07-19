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
#include<cstring>
using namespace std;
//若是将二分的所有点分成左右两组，这里的所有数据都是在记录右边一组的匹配情况
int head[505], nxt[505], ver[505], visit[505], match[505], step = 0;
int k, m, n, u, v;
int sum;
bool dfs(int x)//以 x 作为父节点
{
	for (int i = head[x]; i; i = nxt[i])//历遍下属的所有子节点
	{
		int y = ver[i];
		if (!visit[y])
		{
			visit[i] = 1;//将这个点的访问状态设为 1 即已访问
			// match 所指向的是这个点的匹配情况
			if (!match[y] || dfs(match[y]))//若是这个点已经匹配则对其之前的匹配对象进行递归回溯
			{
				match[y] = x;//赋值这个点的匹配对象为 x
				return true;
			}
		}
	}
	return false;
}
void add(int fa, int son)
{
	step++;
	ver[step] = son;
	nxt[step] = head[fa];
	head[fa] = step;
}
int main() {
	while (cin >> k)
	{
		if (k == 0)
		{
			break;
		}
		cin >> n >> m;
		sum = 0;
		//初始化
		memset(match, 0, sizeof(match));
		for (int i = 1; i <= k; i++)
		{
			cin >> u >> v;
			add(u, v);
		}
		for (int i = 1; i <= n; i++)
		{
			memset(visit, 0, sizeof(visit));
			if (dfs(i))sum++;
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}
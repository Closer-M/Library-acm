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
int a[1010][1010], d[1010], n, m, s, t;
bool v[1010];
void dijkstra()
{
	memset(d, 0x3f, sizeof(d));// idst 数组
	memset(v, 0, sizeof(v));//节点标记
	d[s] = 0;
	for (int i = 1; i < n; i++)
	{
		int x = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!v[j] && (x == 0 || d[j] < d[x]))
			{
				x = j;
			}
		}
		v[x] = 1;
		for (int y = 1; y <= n; y++)
		{
			d[y] = min(d[y], d[x] + a[x][y]);
		}
	}
}
int main()
{
	while (cin >> n >> m >> s >> t)
	{
		//构建邻接矩阵
		memset(a, 0x3f, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			a[i][i] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			a[x][y] = min(a[x][y], z);
			a[y][x] = a[x][y];
		}
		//求单源最短路径
		dijkstra();
		cout << d[t] << endl;
	}
	system("pause");
	return 0;
}
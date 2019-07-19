#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
using namespace std;
int main()
{
	int v, n;
	while (cin >> v)
	{
		if (v == 0)
		{
			break;
		}
		cin >> n;
		int z = 0;
		map<int, int>bi;
		priority_queue<int, vector<int>, less<int> >x;
		for (int i = 0; i < n; i++)
		{
			int p, m;
			cin >> p >> m;
			if (!bi.count(p))
			{
				bi[p] = m;
				x.push(p);
			}
			else
			{
				bi[p] += m;
			}
		}
		while (v != 0)
		{
			if (x.empty())
			{
				break;
			}
			if (bi[x.top()] <= v)
			{
				z += bi[x.top()] * x.top();
				v -= bi[x.top()];
				x.pop();
			}
			else
			{
				z += v * x.top();
				v = 0;
			}
		}
		cout << z << endl;
	}
	system("pause");
	return 0;
}
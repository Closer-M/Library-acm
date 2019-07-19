#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include <assert.h>
using namespace std;
int main()
{
	int n, m, x;
	while (cin >> n >> m)
	{
		priority_queue<int, vector<int>, less<int> >zuo;
		priority_queue<int, vector<int>, greater<int> >you;
		int a[30010];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int r = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			while (zuo.size() + you.size() < x)
			{
				you.push(a[r]);
				r++;
			}
			while (!zuo.empty() && zuo.top() > you.top())
			{
				int t = zuo.top(); zuo.pop(); you.push(t);
				t = you.top(); you.pop(); zuo.push(t);
			}
			cout << you.top() << endl;
			zuo.push(you.top());
			you.pop();
		}
	}
	system("pause");
	return 0;
}
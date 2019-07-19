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
int main()
{
	int t;
	while (cin >> t)
	{
		long long sum = 0, a = 0, b = 0, z = -1;
		while (t--)
		{
			long long n, m, x, r;
			cin >> n >> m;
			x = min(n, m);
			r = max(n, m);
			if (n < b || m < a)
			{
				a = n;
				b = m;
				z = r - 1;
				continue;
			}
			else
			{
				sum += x - z;
				if (n == m)
				{
					z = m;
				}
				else
				{
					z = r - 1;
				}
				a = n;
				b = m;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
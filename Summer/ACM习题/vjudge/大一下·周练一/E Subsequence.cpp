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
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int a, b, sum = 0, n, time = 0, min = 100001;
			queue<int>sha;
			cin >> a >> b;
			for (int i = 0; i < a; i++)
			{
				cin >> n;
				if (sum + n < b)
				{
					sha.push(n);
					sum += n;
					time++;
				}
				else
				{
					sha.push(n);
					sum += n;
					time++;
					while (sum >= b)
					{
						sum -= sha.front();
						sha.pop();
						time--;
					}
					if (min > time + 1)
					{
						min = time + 1;
					}
				}
			}
			if (min == 100001)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << min << endl;
			}
		}
	}
	system("pause");
	return 0;
}
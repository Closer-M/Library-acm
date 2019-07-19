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
		int sum = 0, n = 0, x, r = 0, max = 0;
		for (int i = 1; i <= T; i++)
		{
			cin >> x;
			if (x == 1)
			{
				sum++;
			}
			else
			{
				if (sum > max)
				{
					max = sum;
				}
				if (r == 0)
				{
					r = 1;
					n = sum;
				}
				sum = 0;
			}
		}
		if (sum + n > max)
		{
			cout << sum + n << endl;
		}
		else
		{
			cout << max << endl;
		}
	}
	system("pause");
	return 0;
}
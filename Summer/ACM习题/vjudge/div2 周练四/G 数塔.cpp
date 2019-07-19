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
using namespace std;
int main()
{
	int a[110][110], dp[110][110];
	int C;
	while (cin >> C)
	{
		while (C--)
		{
			int T;
			cin >> T;
			for (int i = 1; i <= T; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					cin >> a[i][j];
				}
			}
			for (int i = 1; i <= T; i++)
			{
				dp[T][i] = a[T][i];
			}
			for (int step = T; step > 1; step--)
			{
				for (int j = 1; j < step; j++)
				{
					if (dp[step][j] >= dp[step][j + 1])
					{
						dp[step - 1][j] = a[step - 1][j] + dp[step][j];
					}
					else
					{
						dp[step - 1][j] = a[step - 1][j] + dp[step][j + 1];
					}
				}
			}
			cout << dp[1][1] << endl;
		}
	}
	system("pause");
	return 0;
}
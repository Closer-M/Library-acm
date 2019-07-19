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
int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int n;
			int a[110][110];
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					cin >> a[i][j];
				}
			}
			for (int i = n - 1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (a[i][j] > a[i][j + 1])
					{
						a[i - 1][j] += a[i][j];
					}
					else
					{
						a[i - 1][j] += a[i][j + 1];
					}
				}
			}
			cout << a[0][0] << endl;
		}
	}
	system("pause");
	return 0;
}
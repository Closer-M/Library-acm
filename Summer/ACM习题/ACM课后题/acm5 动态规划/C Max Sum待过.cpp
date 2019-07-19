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
			int a[100010], mx[100010], n, z, y;
			int sum = -99999999;
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			mx[0] = -99999999;
			z = 1;
			for (int i = 1; i <= n; i++)
			{
				if (mx[i - 1] + a[i] < a[i])
				{
					z = i;
				}
				mx[i] = max(mx[i - 1] + a[i], a[i]);
				if (mx[i] > sum)
				{
					sum = mx[i];
					y = i;
				}
			}
			cout << sum << " " << z << " " << y << endl;
		}
	}
	system("pause");
	return 0;
}
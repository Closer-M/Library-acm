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
		int n = 1, x, sum = 0;
		for (int i = 1; i <= T; i++)
		{
			cin >> x;
			if (x > n)
			{
				n = x;
			}
			if (n == i)
			{
				sum++;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
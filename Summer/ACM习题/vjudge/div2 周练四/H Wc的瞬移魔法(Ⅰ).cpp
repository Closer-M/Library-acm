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
	int n, k;
	while (cin >> n >> k)
	{
		int i = 1, j = n, m = 1, sum = 0;
		while (m != k)
		{
			m = (i + j) / 2;
			if(k>m)
			{
				i = m + 1;
			}
			else
			{
				j = m - 1;
			}
			sum++;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
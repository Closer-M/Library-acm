#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<stdio.h>
#include<queue>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int t;
	while (cin >> t)
	{
		long long a = 1;
		long long b = 0;
		long long x;
		t--;
		while (t--)
		{
			x = a;
			a = (x + b) * 2;
			b = x;
		}
		cout << a * 3 + b * 2 << endl;
	}
	system("pause");
	return 0;
}
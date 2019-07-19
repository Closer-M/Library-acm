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
		while (t--)
		{
			int L, v, l, r;
			cin >> L >> v >> l >> r;
			
			
			cout << (l - 1) / v + L / v - r / v << endl;
			
		}
	}
	system("pause");
	return 0;
}
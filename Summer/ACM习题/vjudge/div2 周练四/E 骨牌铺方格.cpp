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
	long long n[100];
	n[1] = 1;
	n[2] = 2;
	for (int k = 3; k <= 50; k++)
	{
		n[k] = n[k - 1] + n[k - 2];
	}
	int t;
	while (cin >> t)
	{
		cout << n[t] << endl;
	}
	system("pause");
	return 0;
}
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
	string s;
	while (cin >> s)
	{
		char n[110];
		for (int i = 0; i < s.length(); i++)
		{
			n[i] = s[i];
		}
		sort(n, n + s.length(), cmp);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == n[0])
			{
				cout << s[i] << "(max)";
			}
			else
			{
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}
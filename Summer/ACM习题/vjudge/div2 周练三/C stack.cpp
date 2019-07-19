#include<iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include<cstdio>
using namespace std;
int a[100000];
int b[100000];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		while (n--)
		{
			string s;
			getline(cin, s);
			int x = s.length(), r = 0, z, h = x;
			while (x != 0)
			{
				h = x;
				r = 0;
				z = 0;
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] == '(')
					{
						r = 1;
						z = i;
					}
					if (s[i] == '[')
					{
						r = 2;
						z = i;
					}
					if (s[i] == ')'&&r == 1)
					{
						r = 0;
						s[z] = '0';
						s[i] = '0';
						x -= 2;
					}
					if (s[i] == ']'&&r == 2)
					{
						r = 0;
						s[z] = '0';
						s[i] = '0';
						x -= 2;
					}
					if ((s[i] == ')'&&r != 1) || (s[i] == ']'&&r != 2))
					{
						r = 0;
					}
				}
				if (h == x)
				{
					cout << "No" << endl;
					break;
				}
			}
			if (x == 0)
			{
				cout << "Yes" << endl;
			}
		}
	}
	system("pause");
	return 0;
}
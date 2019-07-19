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
			int book[100] = { 0 }, x, a[100] = { 0 }, z = 0;
			for (int i = 0; i < 7; i++)
			{
				cin >> x;
				if (x == 0)
				{
					z = 1;
				}
				if (x == 1)
				{
					a[5] = 1;
				}
				else if (x == 2)
				{
					a[6] = 1;
				}
				else if (x == 3)
				{
					a[1] = 1;
				}
				else if (x == 4)
				{
					a[3] = 1;
				}
			}
			for (int i = 0; i < 7; i++)
			{
				cin >> x;
				if (x == 1)
				{
					book[5] = 1;
				}
				else if (x == 2)
				{
					book[6] = 1;
				}
				else if (x == 3)
				{
					book[1] = 1;
				}
				else if (x == 4)
				{
					book[3] = 1;
				}
			}
			if (z == 0)
			{
				cout << "NO" << endl;
				continue;
			}
			if (book[1] == 1 || book[2] == 1 || a[1] == 1 || a[2] == 1)
			{
				if (book[3] == 1 || book[4] == 1 || a[3] == 1 || a[4] == 1)
				{
					if (book[5] == 1 || book[6] == 1 || a[5] == 1 || a[6] == 1)
					{
						book[5] = 0;
						book[6] = 0;
						a[5] = 0;
						a[6] = 0;
					}
					book[3] = 0;
					book[4] = 0;
					a[3] = 0;
					a[4] = 0;
				}
				book[1] = 0;
				book[2] = 0;
				a[1] = 0;
				a[2] = 0;
			}
			int r = 1;
			for (int i = 1; i <= 6; i++)
			{
				if (book[i] == 1)
				{
					r = 0;
				}
			}
			if (r == 0)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
			}
		}
	}
	system("pause");
	return 0;
}
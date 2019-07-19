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
	int n;
	while (cin >> n)
	{
		int book[100][100] = { 0 };
		char x;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> x;
				if (x == '.')
				{
					book[i][j] = 1;
				}
			}
		}
		int r = 1;
		for (int i = 0; i < n - 2; i++)
		{
			if (book[i][0] == 1 || book[i][n - 1] == 1)
			{
				cout << "NO" << endl;
				r = 0; 
				break;
			}
			for (int j = 1; j < n - 1; j++)
			{
				if (book[i][j] == 1)
				{
					if (book[i + 1][j - 1] == 1 && book[i + 1][j] == 1 && book[i + 1][j + 1] == 1 && book[i + 2][j] == 1)
					{
						book[i][j] = 0;
						book[i + 1][j - 1] = 0;
						book[i + 1][j] = 0;
						book[i + 1][j + 1] = 0;
						book[i + 2][j] = 0;
					}
					else
					{
						cout << "NO" << endl;
						r = 0;
						break;
					}
				}
			}
			if (r == 0)
			{
				break;
			}
		}
		if (r == 0)
		{
			continue;
		}
		for (int i = n - 2; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (book[i][j] == 1)
				{
					r = 0;
					cout << "NO" << endl;
					break;
				}
			}
			if (r == 0)
			{
				break;
			}
		}
		if (r == 0)
		{
			continue;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	system("pause");
	return 0;
}
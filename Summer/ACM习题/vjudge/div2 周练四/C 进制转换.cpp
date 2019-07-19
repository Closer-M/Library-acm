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
	int N, R;
	while (cin >> N >> R)
	{
		int n = N, r;
		if (n < 0)
		{
			cout << '-';
			n *= -1;
		}
		string s;
		while (n != 0)
		{
			r = n % R;
			char x = r + 48;
			n /= R;
			if (r == 10)
			{
				s= 'A'+s;
			}
			else if (r == 11)
			{
				s = 'B' + s;
			}
			else if (r == 12)
			{
				s = 'C' + s;
			}
			else if (r == 13)
			{
				s = 'D' + s;
			}
			else if (r == 14)
			{
				s = 'E' + s;
			}
			else if (r == 15)
			{
				s = 'F' + s;
			}
			else
			{
				s = x + s;
			}
		}
		cout << s << endl;
	}
	system("pause");
	return 0;
}
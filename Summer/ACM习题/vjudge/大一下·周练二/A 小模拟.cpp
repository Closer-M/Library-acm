#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
using namespace std;
int a[1000000];
int b[1000000];
bool cmp(int a, int b)
{
	return(a > b);
}
int main()
{
	int n;
	string s;
	priority_queue<int, vector<int>, greater<int> >su;
	while (cin >> n)
	{
		cin >> s;
		su.push(1);
		su.push(n);
		for (int i = 2; i <= sqrt(static_cast<double>(n)); i++)
		{
			if (n%i == 0)
			{
				if (i == n / i)
				{
					su.push(i);
				}
				else
				{
					su.push(i);
					su.push(n / i);
				}
			}
		}
		while (!su.empty())
		{
			int z = 0, y = su.top() - 1;
			while (z < y)
			{
				char t = s[z];
				s[z] = s[y];
				s[y] = t;
				z++;
				y--;
			}
			su.pop();
		}
		cout << s << endl;
	}
	system("pause");
	return 0;
}
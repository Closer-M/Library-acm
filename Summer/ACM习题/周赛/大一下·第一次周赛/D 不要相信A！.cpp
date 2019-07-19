#include<iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include<cstdio>
using namespace std;
int h[1000000];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	long long a, b;
	while (cin >> a >> b)
	{
		for (int i = 0; i < a; i++)
		{
			cin >> h[i];
		}
		sort(h, h + a);
		long long z = a / 2, c = 0, r = 0;
		while (z >= 0 && z <= a - 1)
		{
			if (h[z] > b)
			{
				if (r == 2)
				{
					break;
				}
				c = c + h[z] - b;
				z--;
				r = 1;
			}
			else if (h[z] < b)
			{
				if (r == 1)
				{
					break;
				}
				c = c + b - h[z];
				z++;
				r = 2;
			}
			else
			{
				break;
			}
		}
		cout << c << endl;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
using namespace std;
int main()
{
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			int year, month, day;
			cin >> year >> month >> day;
			int r = 0, sum = 0;
			r = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
			sum = (year - 1) * 365 + r;
			for (int i = 1; i <= 12; i++)
			{
				if (i == month)
				{
					sum += day;
					break;
				}
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					sum += 31;
				}
				else if (i == 2)
				{
					if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
					{
						sum += 29;
					}
					else
					{
						sum += 28;
					}
				}
				else
				{
					sum += 30;
				}
			}
			cout << sum << endl;
		}
	}
	system("pause");
	return 0;
}

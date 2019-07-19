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
	int n, x;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		sort(a, a + n, cmp);
		sort(b, b + n, cmp);
		x = 0;
		int ad = 0, ax = n - 1, bd = 0, bx = n - 1;
		while (ad <= ax)
		{
			if (a[ad] != b[bd])//双方最强相比，最强不同时
			{
				if (a[ad] > b[bd])//如果田忌的强则先赢一把
				{
					x++;
					ad++;
					bd++;
				}
				else//如果王的更强，则田忌用最弱的和王比
				{
					x--;
					ax--;
					bd++;
				}
			}
			else//双方最强不同时
			{
				if (a[ax] > b[bx])//田忌的最弱强于王时，先赢一场
				{
					ax--;
					bx--;
					x++;
				}
				else//直接拿田忌的最弱去对阵王的最强，达到最大收益
				{
					if (a[ax] == b[bd])//田忌的最弱和王的最强相同时，和局
					{
						ax--;
						bd++;
					}
					else if (a[ax] < b[bd])//田忌的最容不比王的最强时，输一场
					{
						ax--;
						bd++;
						x--;
					}
				}
			}
		}
		cout << x * 200 << endl;
	}
	system("pause");
	return 0;
}
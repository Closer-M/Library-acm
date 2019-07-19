#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int a[11] = { -1 };
		int x;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			a[i] = x;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> x;
			for (int j = 1; j <= n; j++)
			{
				if (x == a[j])
				{
					a[j] += 10;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] >= 10)
			{
				cout << a[i] - 10 << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
} 
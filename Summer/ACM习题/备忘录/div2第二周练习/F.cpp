#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int a[1000000];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1)
			{
				cout << " ";
			}
		}
	}
	cout << endl;
	return 0;
}
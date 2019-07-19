#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int a[1001] = { 0 };
		int b[51] = { 0 };
		int x = n;
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			a[b[i]]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[b[i]] > 1)
			{
				a[b[i]]--;
				b[i] = 0;
				x--;
			}
		}
		cout << x << endl;
		for (int i = 1; i <= n; i++)
		{
			if (b[i] != 0)
			{
				cout << b[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
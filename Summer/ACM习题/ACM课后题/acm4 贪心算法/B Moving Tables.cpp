#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, a, b, r[1000] = { 0 }, z = 0, x;
		cin >> n;
		while (n--)
		{
			cin >> a >> b;
			if (a > b)
			{
				x = a;
				a = b;
				b = x;
			}
			if (a % 2 == 0)
			{
				a--;
			}
			if (b % 2 == 1)
			{
				b++;
			}
			for (int i = a; i <= b; i++)
			{
				r[i]++;
			}
			for (int i = 1; i <= 400; i++)
			{
				if (r[i] > z)
				{
					z = r[i];
				}
			}
		}
		cout << z * 10 << endl;
	}
	system("pause");
	return 0;
}
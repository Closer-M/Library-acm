#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	int T;
	while (cin >> T)
	{
		int n = 0;
		if (T == 0)
		{
			break;
		}
		for (int i = 0; i < T; i++)
		{
			cin >> a[i] >> b[i];
		}
		for (int i = 0; i < T; i++)
		{
			for (int j = T - 1; j > i; j--)
			{
				if (b[j] < b[j - 1])
				{
					n = b[j];
					b[j] = b[j - 1];
					b[j - 1] = n;
					n = a[j];
					a[j] = a[j - 1];
					a[j - 1] = n;
				}
			}
		}
		n = 0;
		int m = 0;
		for (int i = 0; i < T; i++)
		{
			if (a[i] >= m)
			{
				m = b[i];
				n++;
			}
		}
		cout << n << endl;
	}
	system("pause");
	return 0;
}
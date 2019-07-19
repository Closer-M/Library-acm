#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
	int T;
	while (cin >> T)
	{
		if (T == 0)
		{
			break;
		}
		int a[101], b[101], x, n;
		for (int i = 0; i < T; i++)
		{
			cin >> x;
			a[i] = x;
			b[i] = abs(x);
		}
		for (int i = 0; i < T; i++)
		{
			for (int j = T - 1; j > i; j--)
			{
				if (b[j - 1] < b[j])
				{
					n = b[j - 1];
					b[j - 1] = b[j];
					b[j] = n;
					n = a[j - 1];
					a[j - 1] = a[j];
					a[j] = n;
				}
			}
		}
		for (int i = 0; i < T - 1; i++)
		{
			cout << a[i] << " ";
		}
		cout << a[T - 1] << endl;
	}
	return 0;
}
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	long long n, m, k;
	while (cin >> n >> m >> k)
	{
		long long a = 0, b = 0, z, q, e;
		while (n--)
		{
			cin >> z;
			if (z > a)
			{
				b = a;
				a = z;
			}
			else if (z <= a && z > b)
			{
				b = z;
			}
		}
		q = m / (k + 1);
		e = m % (k + 1);
		cout << q * (k*a + b) + e * a << endl;
	}
	system("pause");
	return 0;
}
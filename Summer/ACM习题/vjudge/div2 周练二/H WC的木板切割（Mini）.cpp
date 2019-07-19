#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int a[101];
int main()
{
	long long n;
	while (cin >> n)
	{
		long long x = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = n, j = 0; i > 0; i--, j++)
		{
			x += a[j] * i;
		}
		cout << x - a[0] << endl;
	}
	return 0;
}
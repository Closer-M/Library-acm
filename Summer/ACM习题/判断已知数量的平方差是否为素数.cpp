#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int su(long double a)//在用旧的版本进行ac时，sqrt中只能是浮点型，不然就会出错。
{
	int r = 1;
	long long b = a;
	for (long long i = 2; i <= sqrt(a); i++)
	{
		if (b%i == 0)
		{
			r = 0;
			break;
		}
	}
	return r;
}
int main()
{
	int T;
	cin >> T;
	long long x, y, b;
	long double a;
	while (T--)
	{
		cin >> x >> y;
		a = x + y;
		b = x - y;
		if (b == 1 && su(a) == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
} 
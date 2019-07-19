#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int z = 0, y = 100;
		double A = 0;
		int a;
		int i = n;
		while (n--)
		{
			cin >> a;
			A += a;
			if (a > z)
			{
				z = a;
			}
			if (a < y)
			{
				y = a;
			}
		}
		cout << fixed << setprecision(2) << (A - z - y) / (i - 2) << endl;

	}
	return 0;
}
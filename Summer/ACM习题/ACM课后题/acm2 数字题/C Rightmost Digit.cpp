#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	int n, T;
	cin >> T;
	while (T--)
	{
		int a[10] = { 0 }, z, y, l = 1;
		cin >> n;
		int h = n % 10;
		z = h;
		y = h;
		a[1] = z;
		while (z != y * h % 10)
		{
			y = y * h % 10;
			l++;
			a[l] = y;
		}
		a[0] = y;
		cout << a[(n % l)] << endl;
	}
	system("pause");
	return 0;
}
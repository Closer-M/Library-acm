#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	string n;
	while (cin >> n)
	{
		int z = 0;
		if (n[0] == '0')
		{
			break;
		}
		else
		{
			for (int i = 0; i < n.length(); i++)
			{
				z = z + n[i] - 48;
			}
		}
		int a = z, x = 0;
		while (a >= 10)
		{
			x = 0;
			while (a != 0)
			{
				x = x + a % 10;
				a = a / 10;
			}
			a = x;
		}
		cout << a << endl;
	}
	system("pause");
	return 0;
}
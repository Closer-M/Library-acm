#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	int  n;
	cin >> n;
	while (n--)
	{
		int a, b;
		char x;
		cin >> x >> a >> b;
		if (x == '+')
		{
			cout << a + b << endl;
		}
		else if (x == '-')
		{
			cout << a - b << endl;
		}
		else if (x == '*')
		{
			cout << a * b << endl;
		}
		else
		{
			if (a%b == 0)
			{
				cout << a / b << endl;
			}
			else
			{
				cout << fixed << setprecision(2) << static_cast<double>(a) / static_cast<double>(b) << endl;
			}
		}
	}
	system("pause");
	return 0;
}
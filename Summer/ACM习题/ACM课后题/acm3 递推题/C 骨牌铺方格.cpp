#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	long long a = 1, b = 2, c;
	int n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << 1 << endl;
		}
		else if (n == 2)
		{
			cout << 2 << endl;
		}
		else
		{
			a = 1, b = 2;
			for (int i = 0; i < n - 2; i++)
			{
				c = a + b;
				a = b;
				b = c;
			}
			cout << c << endl;
		}
	}
	system("pause");
	return 0;
}
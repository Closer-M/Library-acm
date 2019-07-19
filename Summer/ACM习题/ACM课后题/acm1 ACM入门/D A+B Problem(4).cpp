#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	int n, a, b;
	while (cin >> n)
	{
		b = 0;
		if (n == 0)
		{
			break;
		}
		while (n--)
		{
			cin >> a;
			b += a;
		}
		cout << b << endl;
	}
	system("pause");
	return 0;
}
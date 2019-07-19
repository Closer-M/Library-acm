#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<fstream>
using namespace std;
int max(int a, int b, int c)
{
	if (a > b&&a > c)
	{
		return a;
	}
	else if (b > a&&b > c)
	{
		return b;
	}
	else
	{
		return c;
	}
}
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int n = max(a, b, c);
		int num = 3 * n - a - b - c;
		if (num % 2 == 0)
		{
			cout << num / 2 << endl;
		}
		else
		{
			cout << (num + 3) / 2 << endl;
		}
	}
	system("pause");
	return 0;
}
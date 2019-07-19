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
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		int a = 0, b = 0, c = 0, d = 0, n;
		while (x--)
		{
			cin >> n;
			if (n % 2 == 1)
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		while (y--)
		{
			cin >> n;
			if (n % 2 == 1)
			{
				c++;
			}
			else
			{
				d++;
			}
		}
		cout << min(a, d) + min(c, b) << endl;
	}
	return 0;
}
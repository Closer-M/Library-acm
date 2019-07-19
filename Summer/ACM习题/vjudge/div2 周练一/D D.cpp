#include<iostream>
#include<string>
using namespace std;
int main()
{
	int x;
	while (cin >> x)
	{
		int y = x + 1;
		while (y < 10000)
		{
			int a = y % 10;
			int b = y / 10 % 10;
			int c = y / 100 % 10;
			int d = y / 1000;
			if (a != b && b != c && c != d && a != c && a != d && b != d)
			{
				cout << y << endl;
				break;
			}
			y++;
		}
	}
	return 0;
}
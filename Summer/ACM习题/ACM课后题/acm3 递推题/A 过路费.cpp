#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, a = 3;
		cin >> n;
		while (n--)
		{
			a = (a - 1) * 2;
		}
		cout << a << endl;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	string N;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int n = N.length(), l = 0;
		char a = N[0];
		for (int i = 0; i < n; i++)
		{
			if (N[i] == a)
			{
				l++;
			}
			else
			{
				if (l > 1)
				{
					cout << l;
				}
				cout << a;
				a = N[i];
				l = 1;
			}
		}
		if (l > 1)
		{
			cout << l;
		}
		cout << a;
		cout << endl;
	}
	system("pause");
	return 0;
}
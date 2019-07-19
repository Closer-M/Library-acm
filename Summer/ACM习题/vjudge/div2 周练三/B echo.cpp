#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	string T;
	while (cin >> T)
	{
		int l = T.length(), i, n;
		i = 0;
		while (i < l)
		{
			if (T[i] < 0)
			{
				n = i;
				while (n < l)
				{
					if (T[n] < 0)
					{
						cout << T[n] << T[n + 1];
						n += 2;
					}
					else
					{
						cout << T[n];
						n++;
					}
				}
				cout << "~" << endl;
				i += 2;
			}
			else
			{
				n = i;
				while (n < l)
				{
					if (T[n] < 0)
					{
						cout << T[n] << T[n + 1];
						n += 2;
					}
					else
					{
						cout << T[n];
						n++;
					}
				}
				cout << "~" << endl;
				i++;
			}
		}
	}
	system("pause");
	return 0;
}
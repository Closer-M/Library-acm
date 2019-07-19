#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		while (n--)
		{
			int a, r = 1;
			cin >> a;
			for (int i = 2; i <= sqrt(a); i++)
			{
				if (a%i == 0)
				{
					cout << "No" << endl;
					r = 0;
				}
			}
			if (r == 1)
			{
				cout << "Yes" << endl;
			}
		}
	}
	system("pause");
	return 0;
}

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
#include<stdio.h>
using namespace std;
int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int n, m;
			cin >> n >> m;
			long long sum;
			if (n == 1 && m!= 1)
			{
				sum = m - 2;
			}
			else if (n != 1 && m == 1)
			{
				sum = n - 2;
			}
			else if (n == 1 && m == 1)
			{
				sum = 1;
			}
			else if (n == 2 || m == 2)
			{
				sum = 0;
			}
			else
			{
				sum = (n - 2)*(m - 2);
			}
			if (sum % 2 == 0)
			{
				cout << "ひなつる あい" << endl;
			}
			else
			{
				cout << "そら ぎんこ" << endl;
			}
		}
	}
	system("pause");
	return 0;
}
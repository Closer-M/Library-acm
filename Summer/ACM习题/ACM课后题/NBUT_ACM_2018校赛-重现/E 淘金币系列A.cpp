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
			priority_queue <int, vector<int>, less<int> > a;
			int n, x, r = 1;
			cin >> n;
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> x;
				a.push(x);
			}
			for (int i = 0; i < min(5, n); i++)
			{
				if (a.top() >= 0)
				{
					sum += a.top();
					a.pop();
				}
				else
				{
					cout << sum << endl;
					r = 0;
					break;
				}
			}
			if (r == 1)
			{
				cout << sum << endl;
			}
		}
	}
	system("pause");
	return 0;
}
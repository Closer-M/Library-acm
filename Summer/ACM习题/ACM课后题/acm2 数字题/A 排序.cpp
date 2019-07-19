#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int a[1000000];
int main()
{
	string T;
	while (getline(cin, T))
	{
		int n = 0, m = 0, r;
		for (int i = 0; i < T.length(); i++)
		{
			if (T[i] == '5'&&r == 0)
			{
				continue;
			}
			if (T[i] == '5')
			{
				a[m] = n;
				m++;
				n = 0;
				r = 0;
				continue;
			}
			r = 1;
			n = n * 10 + T[i] - 48;
		}
		if (r == 1)
		{
			a[m] = n;
			m++;
		}
		sort(a, a + m);
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

//¸ß¼¶¸´ÔÓ°æ±¾

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
	string s;
	string x;
	priority_queue<int, vector<int>, greater<int> >su;
	while (cin >> s)
	{
		int n = 0;
		while (n < s.length())
		{
			int t = s.find('5', n);
			if (t < 0)
			{
				x.assign(s, n, s.length() - n);
				su.push(atoi(x.c_str()));
				break;
			}
			else if (n == t)
			{
				n++;
				continue;
			}
			x.assign(s, n, t - n);
			n = t + 1;
			su.push(atoi(x.c_str()));
		}
		while (!su.empty())
		{
			cout << su.top() << " ";
			su.pop();
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
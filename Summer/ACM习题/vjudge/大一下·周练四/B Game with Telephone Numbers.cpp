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
	int n;
	string s;
	while (cin >> n >> s)
	{
		int sum = 0;
		for (int i = 0; i < s.length() - 10; i++)
		{
			if (s[i] == '8')
			{
				sum++;
			}
		}
		if (sum > (n - 11) / 2)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
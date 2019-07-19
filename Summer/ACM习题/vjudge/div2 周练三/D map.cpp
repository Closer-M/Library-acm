#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
	
	int n;
	while (cin >> n)
	{
		string s;
		map<string, int>mapname;
		map<string, int>::iterator iter;
		int a[1000000] = { 0 };
		int x = 1;
		while (n--)
		{
			cin >> s;
			if (mapname[s] == 0)
			{
				mapname[s] = x;
				x++;
				cout << "OK" << endl;
			}
			else
			{
				iter = mapname.find(s);
				a[iter->second]++;
				cout << iter->first << a[iter->second] << endl;
			}
		}
	}
	system("pause");
	return 0;
}
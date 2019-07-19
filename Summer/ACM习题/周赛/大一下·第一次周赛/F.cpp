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
struct side
{
	int head, tail, book;
};
int main()
{
	string T;
	while (cin >> T)
	{
		string s;
		int x = 0;
		for (int i = 0; i < T.length(); i++)
		{
			if (T[i] != 'a')
			{
				s += T[i];
				x = 1;
			}
		}
		if (s.length() % 2 == 1)
		{
			cout << ":(" << endl;
			continue;
		}
		if (s.substr(0, s.length() / 2) == T.substr(T.length() - s.length() / 2))
		{
			cout << T.substr(0, T.length() - s.length() / 2) << endl;
		}
		else
		{
			cout << ":(" << endl;
		}
	}
	system("pause");
	return 0;
}
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
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			long long a, b, c, d;
			cin >> a >> b >> c >> d;
			if (a*b > c*d)
			{
				cout << "Idiot" << endl;
			}
			else
			{
				cout << "Foolish" << endl;
			}
		}
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		cin >> s;
		int l = s.length();
		char r = s[0];
		int q = 0;
		for (int i = 1; i < l; i++)
		{
			if (r == s[i])
			{
				q++;
			}
			else
			{
				r = s[i];
			}
		}
		cout << q << endl;
	}
	system("pause");
	return 0;
}
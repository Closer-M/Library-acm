#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	string n;
	while (getline(cin, n))
	{
		int i = n.length();
		while (i--)
		{
			if (isupper(n[i]))
			{
				n[i] = tolower(n[i]);
			}
			else if (islower(n[i]))
			{
				continue;
			}
			else
			{
				n[i] = '*';
			}
		}
		cout << n << endl;
	}
	system("pause");
	return 0;
}
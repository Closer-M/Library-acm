#include<iostream>
#include<string>
using namespace std;
int main()
{
	int T;
	cin >> T;
	cout;
	getchar();
	while (T--)
	{
		string n;
		getline(cin, n);
		int a[5] = { 0 };
		for (int i = 0; i <= n.length(); i++)
		{
			if (n[i] == 'a')
			{
				a[0]++;
			}
			else if (n[i] == 'e')
			{
				a[1]++;
			}
			else if (n[i] == 'i')
			{
				a[2]++;
			}
			else if (n[i] == 'o')
			{
				a[3]++;
			}
			else if (n[i] == 'u')
			{
				a[4]++;
			}
		}
		cout << "a:" << a[0] << endl;
		cout << "e:" << a[1] << endl;
		cout << "i:" << a[2] << endl;
		cout << "o:" << a[3] << endl;
		cout << "u:" << a[4] << endl;
		if (T != 0)
		{
			cout << endl;
		}
	}
	return 0;
}
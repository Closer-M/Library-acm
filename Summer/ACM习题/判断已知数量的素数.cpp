#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool su(long long a)
{
	int i = 2;
	bool r = 1;
	if (a > 1)
	{
		while (i <= sqrt(a))
		{
			if (a%i == 0)
			{
				r = 0;
			}
			i++;
		}
	}
	return r == 1;
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		if (su(n) == 1)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}
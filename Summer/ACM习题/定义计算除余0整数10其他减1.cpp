#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		while (k--)
		{
			if (n % 10 == 0)
			{
				n /= 10;
			}
			else
			{
				n -= 1;
			}
		}
		cout << n << endl;
	}
	system("pause");
	return 0;
}
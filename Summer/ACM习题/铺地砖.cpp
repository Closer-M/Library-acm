#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long a, b, n;
	while (cin >> a >> b >> n)
	{
		long long j = a / n, k = b / n;
		if (a%n != 0)
		{
			j++;
		}
		if (b%n != 0)
		{
			k++;
		}
		cout << j * k << endl;
	}
	system("pause");
	return 0;
}
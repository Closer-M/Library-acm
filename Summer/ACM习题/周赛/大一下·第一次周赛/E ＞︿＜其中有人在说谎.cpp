#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	long long n, m;
	while (cin >> n >> m)
	{
		long long z = 1;
		while (n != 0 && z <= m)
		{
			z *= 2;
			n--;
		}
		cout << m % z << endl;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
long long k(long long n)
{
	if (n == 2)
	{
		return  1;
	}
	else if (n == 3)
	{
		return 2;
	}
	else 
	{
		return (k(n - 1) + k(n - 2))*(n - 1);
	}
}
int main()
{
	int a;
	while (cin >> a)
	{
		cout << k(a) << endl;
	}
	system("pause");
	return 0;
}
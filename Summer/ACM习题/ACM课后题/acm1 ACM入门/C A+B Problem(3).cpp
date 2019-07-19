#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		cout << a + b << endl;
	}
	system("pause");
	return 0;
}
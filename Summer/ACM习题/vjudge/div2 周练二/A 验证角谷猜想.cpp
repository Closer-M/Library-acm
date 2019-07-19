#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int n, r = 0, a[100001], j = 0;
		cin >> n;
		while (n != 1)
		{
			if (n % 2 == 1)
			{
				j++;
				a[j] = n;
				r = 1;
				n = n * 3 + 1;
			}
			else
			{
				n = n / 2;
			}
		}
		if (r == 0)
		{
			cout << "No number can be output !" << endl;
		}
		else
		{
			for (int k = 1; k < j; k++)
			{
				cout << a[k] << " ";
			}
			cout << a[j] << endl;
		}
	}
	return 0;
}
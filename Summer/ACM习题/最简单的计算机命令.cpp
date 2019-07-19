#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int m1, m2;
	while (cin >> m1 >> m2)
	{
		int r1 = 0, r2 = 0, r3 = 0;
		string N;
		getchar();
		getline(cin, N);
		int n = N.length();
		for (int i = 0; i < n; i++)
		{
			if (N[i] == 'A')
			{
				r1 = m1;
			}
			else if (N[i] == 'B')
			{
				r2 = m2;
			}
			else if (N[i] == 'C')
			{
				m1 = r3;
			}
			else if (N[i] == 'D')
			{
				m2 = r3;
			}
			else if (N[i] == 'E')
			{
				r3 = r1 + r2;
			}
			else
			{
				r3 = r1 - r2;
			}
		}
		cout<< m1 << "," << m2 << endl;
	}
	system("pause");
	return 0;
}
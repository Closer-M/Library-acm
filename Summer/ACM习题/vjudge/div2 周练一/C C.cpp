#include<iostream>
#include<string>
using namespace std;
int main()
{
	string T;
	while (getline(cin, T))
	{
		int r = 1;
		for (int i = 0; i < T.length(); i++)
		{
			if (r == 1 && (T[i] >= 97 && T[i] <= 122))
			{
				T[i] = T[i] - 32;
				r = 0;
			}
			if (r == 0 && T[i] == 32)
			{
				r = 1;
			}
		}
		cout << T << endl;
	}
	return 0;
}
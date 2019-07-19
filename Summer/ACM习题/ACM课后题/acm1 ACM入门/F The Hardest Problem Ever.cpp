#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	string T;
	while (getline(cin,T))
	{
		if (T == "START" || T == "END")
		{
			continue;
		}
		else if (T == "ENDOFINPUT")
		{
			break;
		}
		else
		{
			for (int i = 0; i < T.length(); i++)
			{
				if (isupper(T[i]))
				{
					T[i] = T[i] - 5;
					if (T[i] < 65)
					{
						T[i] = T[i] + 26;
					}
				}
				else
				{
					continue;
				}
			}
			cout << T << endl;
		}
	}
	system("pause");
	return 0;
}
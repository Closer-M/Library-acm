#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
int main()
{
	int t, time = 1;
	string s;
	while (cin >> t)
	{
		if (t == 0)
		{
			break;
		}
		cout << "Scenario #" << time << endl;
		time++;
		map<int, int>student;//<Ñ§ºÅ,°à¼¶>
		queue<int>dui[10000], ban;
		int n;
		for (int j = 0; j < t; j++)
		{
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> s;
				student[atoi(s.c_str())] = j;
			}
		}
		while (cin >> s)
		{
			if (s == "ENQUEUE")
			{
				cin >> s;
				if (dui[student[atoi(s.c_str())]].empty())
				{
					ban.push(student[atoi(s.c_str())]);
				}
				dui[student[atoi(s.c_str())]].push(atoi(s.c_str()));
			}
			else if (s == "DEQUEUE")
			{
				if (!dui[ban.front()].empty())
				{
					cout << dui[ban.front()].front() << endl;
					dui[ban.front()].pop();
				}
				if (dui[ban.front()].empty())
				{
					ban.pop();
				}
			}
			else
			{
				break;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
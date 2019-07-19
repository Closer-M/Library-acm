#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
struct music
{
	int length, value;
};
bool cmp(music a, music b)
{
	return a.value > b.value;
}
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		priority_queue<long long, vector<long long>, greater<long long> >Long;
		music *song = new music[n];
		long long total = 0, step = 0, result = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> song[i].length >> song[i].value;
		}

		sort(song, song + n, cmp);

		for (int i = 0; i < n; i++)
		{
			if (Long.size() < k)
			{
				total += song[i].length;
				Long.push(song[i].length);
				step = song[i].value;
				if (total * step > result)
				{
					result = total * step;
				}
			}
			else
			{
				if (step == song[i].value)
				{
					total += song[i].length;
					Long.push(song[i].length);
					total -= Long.top();
					Long.pop();
				}
				else
				{
					total -= Long.top();
					Long.pop();
					total += song[i].length;
					Long.push(song[i].length);
				}
				step = song[i].value;
				if (total * step > result)
				{
					result = total * step;
				}
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}
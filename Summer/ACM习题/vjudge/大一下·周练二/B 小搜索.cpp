#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	int sushu[10000], book[10000], n, m, add, result, people, tail, r;
	for (int i = 1; i <= 9999; i++)
	{
		sushu[i] = 0;
	}
	for (int i = 2; i <= 100; i++)
	{
		if (sushu[i] == 0)
		{
			for (int j = i + i; j <= 9999; j += i)
			{
				sushu[j] = 1;
			}
		}
	}
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			queue<int>now, later;
			for (int i = 1000; i <= 9999; i++)
			{
				book[i] = sushu[i];
			}
			cin >> n >> m;

			add = 0;
			people = n;
			result = m;

			now.push(people);
			book[people] = 1;
			r = 1;
			while (!now.empty())
			{
				
				people = now.front();
				if (now.front() == result)
				{
					cout << add << endl;
					r = 0;
					break;
				}
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1)
					{
						for (int j = 1; j <= 9; j++)
						{
							tail = people % 1000 + j * 1000;
							if (book[tail]==0)
							{
								book[tail] = 1;
								later.push(tail);
							}
						}
					}
					else if (i == 2)
					{
						for (int j = 0; j <= 9; j++)
						{
							tail = people / 1000 * 1000 + j * 100 + people % 100;
							if (book[tail] == 0)
							{
								book[tail] = 1;
								later.push(tail);
							}
						}
					}
					else if (i == 3)
					{
						for (int j = 0; j <= 9; j++)
						{
							tail = people / 100 * 100 + j * 10 + people % 10;
							if (book[tail] == 0)
							{
								book[tail] = 1;
								later.push(tail);
							}
						}
					}
					else
					{
						for (int j = 0; j <= 9; j++)
						{
							tail = people / 10 * 10 + j * 1;
							if (book[tail] == 0)
							{
								book[tail] = 1;
								later.push(tail);
							}
						}
					}
				}
				now.pop();
				if (now.empty() && (!later.empty()))
				{
					add++;
					now = later;
					while (!later.empty())
					{
						later.pop();
					}
				}
			}
			if (r == 1)
			{
				cout << 0 << endl;
			}
			
		}
	}
	system("pause");
	return 0;
}
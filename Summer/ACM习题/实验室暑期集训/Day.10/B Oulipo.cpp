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
#include<cstring>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
string Origin, Find;
int n, m, sum;
int Next[10010];
void getNext()
{
	Next[0] = -1;
	int i = 0, j = -1;
	while (i < m)
	{
		if (j == -1 || Find[j] == Find[i])
		{
			i++;
			j++;
			Next[i] = j;
		}
		else
		{
			j = Next[j];
		}
	}
}
int FirstKmp()
{
	int i = 0, j = 0;
	while (i < n)
	{
		if (j == -1 || Origin[i] == Find[j])
		{
			i++;
			j++;
			if (j == m)
			{
				sum++;// Find[3] ÊÇ¿Õ£¬£¿£¿
			}
		}
		else
		{
			j = Next[j];
		}
	}
	return -1;
}
int main()
{
	FAST_IO;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> Find >> Origin;
		n = Origin.length();
		m = Find.length();
		memset(Next, 0, sizeof(Next));
		getNext();
		sum = 0;
		FirstKmp();
		cout << sum << endl;
	}
	
	system("pause");
	return 0;
}
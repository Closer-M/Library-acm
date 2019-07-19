#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include <assert.h>
using namespace std;
struct node
{
	int from, to;//两个被绑定到一起的数据，右前后之分
};
node ad[150];
bool cmp(node a, node b)
{
	return a.to < b.to;
}

int main()
{
	int n, sum, k;
	while (cin >> n)
	{
		if (n == 0)return 0;
		for (int i = 0; i < n; i++)
		{
			cin >> ad[i].from >> ad[i].to;
		}
		sort(ad, ad + n, cmp);
		k = ad[0].to; sum = 1;
		for (int i = 1; i < n; i++)
			if (ad[i].from >= k)
			{
				sum++;
				k = ad[i].to;
			}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
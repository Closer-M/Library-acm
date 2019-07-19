#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<fstream>
using namespace std;
struct people
{
	long long left, right, gap;
};
bool cmp(people a, people b)
{
	return a.gap > b.gap;
}
int main()
{
	int n;
	while (cin >> n)
	{
		people man[100010];
		for (int i = 0; i < n; i++)
		{
			cin >> man[i].left >> man[i].right;
			man[i].gap = man[i].left - man[i].right;
		}
		sort(man, man + n,cmp);
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (i - 0)*man[i].left + (n - i - 1)*man[i].right;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
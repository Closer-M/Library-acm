#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
struct man
{
	string m, js, jc;
};
man a[100];
bool cmj(man a, man b)
{
	return a.js < b.js;
}
bool cmc(man a, man b)
{
	return a.jc > b.jc;
}

int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int M;
			cin >> M;
			int n = 0;
			for (int i = 0; i < M; i++)
			{
				cin >> a[i].m >> a[i].js >> a[i].jc;
			}
			sort(a, a + M, cmj);
			cout << a[0].m << " ";
			sort(a, a + M, cmc);
			cout << a[0].m << endl;
		}
	}
	return 0;
}
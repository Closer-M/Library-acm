#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)

int main()
{
	const double PI = acos(-1);
	FAST_IO;
	int n;
	while (cin >> n)
	{
		double r = n / PI;
		cout << fixed << setprecision(3) << PI * r*r / 2 << endl;
	}
	system("pause");
	return 0;
}
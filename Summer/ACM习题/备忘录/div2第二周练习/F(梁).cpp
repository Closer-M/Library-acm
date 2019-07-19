#include <cmath>
#include <string.h>
#include <algorithm>
#define   MAXN 1000000
#include <stdio.h>
#include <stdlib.h>
using namespace std;
bool cmp(const int x, const int y) {
	return x > y;
}
long int n[MAXN];
int main()
{
	long long int N, i = 0, m;

	while (~scanf("%lld", &N)) 
	{
		i = 0;
		scanf("%lld", &m);
		while (i < N) {

			scanf("%lld", &n[i]);
			i++;
		}
		sort(n, n + N, cmp);
		for (i = 0; i < m; i++) {
			printf("%d", n[i]);
			if (i != (m - 1)) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
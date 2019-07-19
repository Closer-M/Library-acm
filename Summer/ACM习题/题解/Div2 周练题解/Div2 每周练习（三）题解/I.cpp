#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

#define MAXN 100001
int s[MAXN];

int main(){
	int a,b,sum,T;
	scanf("%d",&T);
	for(int j = 1;j <= T; j ++){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i ++){
			scanf("%d",&s[i]);
		}
		int Max = -20000;
		int l,r,l1,r1; //l1，l2 为最终坐标，l.r为临时下标区间
		int under = 0;
		sum = 0;
		l = 0,r = 0;
		for(int i = 0;i < n;i ++){
			sum += s[i];
			if(Max < sum){//当前值大于最大值
				Max = sum;//更新值
				r = i;
				l1 = l,r1 = r;
			}
			if(sum < 0){
				sum = 0; //归零，因为负的比0小
				l = i+1,r = i+1;
			}
		}
		printf("Case %d:\n%d %d %d\n",j,Max,l1+1,r1+1);
		if(j < T)cout<<endl;
	}
	return 0;
}

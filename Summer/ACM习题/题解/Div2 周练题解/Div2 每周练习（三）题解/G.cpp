#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define N 105

struct node{
	int pi,mi;
};

node arr[N];

bool cmp(node a,node b){
	return a.pi>b.pi;
}

int main(){
	int v,n,i,ans;
	while (scanf("%d",&v)!=EOF&&v){
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d%d",&arr[i].pi,&arr[i].mi);
		sort(arr,arr+n,cmp);
		ans=0;
		for (i=0;i<n&&v;i++){
			if (v>=arr[i].mi){
				v-=arr[i].mi;
				ans+=arr[i].mi*arr[i].pi;
			}
			else {
				ans+=arr[i].pi*v;
				v=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

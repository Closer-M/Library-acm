#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m;
int h[N][N], l[N], r[N];
char c[5];
int top, sk[N];

int cal(int* a){
    top = 0;
    a[0] = a[m+1] = -1;
    sk[++top] = 0;
    for(int i=1;i<=m;i++){
        while(a[sk[top]] >= a[i]) top--;
        l[i] = sk[top];
        sk[++top] = i;
    }
    top = 0;
    sk[++top] = m+1;
    for(int i=m;i>=1;i--){
        while(a[sk[top]] >= a[i]) top--;
        r[i] = sk[top];
        sk[++top] = i;
    }
    int ret = 0;
    for(int i=1;i<=n;i++) ret = max(ret,a[i]*(r[i]-l[i]-1));
    return ret;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(h,0,sizeof h);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
            scanf("%s", c);
            h[i][j] = c[0]=='F' ? 1 : 0;
            if(h[i][j]) h[i][j]+=h[i-1][j];
        }
        int ans = 0;
        for(int i=1;i<=n;i++) ans = max(ans, cal(h[i]));
        printf("%d\n", 3*ans);
    }
}
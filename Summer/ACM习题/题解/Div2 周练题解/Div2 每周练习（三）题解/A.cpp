#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
int a[400];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        memset(a,0,sizeof(a));
        for(int j=0;j<n;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x%2==0)
                x--;
            if(y%2==0)
                y--;
            int p=min(x,y);
            int q=max(x,y);
            for(int i=p;i<=q;i++)
                {
                    a[i]++;
                    if(ans<a[i])
                        ans=a[i];
                }
        }
        printf("%d\n",ans*10);
    }
    return 0;
}

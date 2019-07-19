#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define ll long long
#define N 200500
#define MAX 10000000000000
map<int,int>w[N];
int way[N];  
int main()
{
    int m;
    while(cin>>m)
    {
        int i;
        for(i=0;i<m-1;i++)
        {
            int a,b;
            cin>>a>>b;
            w[a][b]=1;
            w[b][a]=1;
        }
        for(i=0;i<m;i++)
        {
            cin>>way[i];
        }
        int k=1;
        for(i=0;i<m;i++)
        {
            while(w[way[i]][way[k]])
            {
                k++;
            }
        }
        if(k==m&&way[0]==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
} 
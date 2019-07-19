#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+20;

int n,u,v;
vector<int>g[N],ng[N],vec;
int ord[N], dep[N], id[N];

void dfs(int u,int f){
    for(int v:g[u]){
        if(v==f) continue;
        ng[u].push_back(v);
        dep[v] = dep[u] + 1;
        dfs(v,u);
    }
}

void bfs(int u){
    queue<int>q;
    q.push(u);
    while(q.size()){
        u = q.front(); q.pop();
        vec.push_back(u);
        sort(ng[u].begin(), ng[u].end(), [](int a,int b){return id[a]<id[b];});
        for(int v:ng[u]){
            q.push(v);
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        cin >> ord[i];
        id[ord[i]] = i;
    }
    if(ord[1]!=1){
        puts("No");
        return 0;
    }
    int rt = ord[1];
    dfs(rt,-1);
    for(int i=1;i<n;i++){
        if(dep[ord[i]]>dep[ord[i+1]]){
            puts("No");
            return 0;
        }
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(vec[i-1]!=ord[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}
d#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int> bigque;
priority_queue<int, vector<int> ,greater<int> > smallque;
int num[30010];
int main() {
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    int k=1;
    for(int i=1;i<=m;i++) {
        scanf("%d",&x);
        while(k<=x) {
            smallque.push(num[k]);
            if(!bigque.empty() && bigque.top()>smallque.top()) {
                int t=bigque.top();bigque.pop();smallque.push(t);
                t=smallque.top();smallque.pop();bigque.push(t);
            }
            k++;
        }
        printf("%d\n",smallque.top());
        int t=smallque.top();smallque.pop();bigque.push(t);
    }
    return 0;
}

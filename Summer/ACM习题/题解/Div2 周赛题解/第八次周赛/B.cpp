#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define clr(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N = 1e5+20;

struct BIT{
    int size,t[N];
    void init(int n){
        size = n;
        clr(t,0);
    }
    void add(int x){
        for(int i=x;i<=size;i+=(i&-i)) t[i]++;
    }
    int sum(int x,int res = 0){
        for(int i=x;i;i-=(i&-i)) res += t[i];
        return res;
    }
};

int n;
ll a[N],pos[2][N],neg[2][N];
BIT bit;

int main(){
    FAST_IO;
    int T;
    cin >> T;
    while(T--){
        bit.init(100000);
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            pos[0][i] = bit.sum(a[i]-1);
            pos[1][i] = bit.sum(100000) - bit.sum(a[i]);
            bit.add(a[i]);
        }
        bit.init(100000);
        for(int i=n;i;i--){
            neg[0][i] = bit.sum(a[i]-1);
            neg[1][i] = bit.sum(100000) - bit.sum(a[i]);
            bit.add(a[i]);
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans += pos[1][i] * neg[0][i];
            ans += pos[0][i] * neg[1][i];
        }
        cout << ans << endl;
    }
}
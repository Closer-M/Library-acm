#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n;
int a[N];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(i>1) ans = min(ans, min(a[i], a[1]) / (i - 1));
        if(i<n) ans = min(ans, min(a[i], a[n]) / (n - i));
    }
    cout << ans << endl;
    return 0;
}
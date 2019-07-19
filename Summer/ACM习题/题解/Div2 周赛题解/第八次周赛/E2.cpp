#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

long long n, x;
vector<pair<int, int>> a;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back({x,i});
    }
    int ans = 0x3f3f3f3f;
    sort(a.rbegin(), a.rend());
    int l = n, r = -1;
    for(int i=0;i<n;i++){
        if(r!=-1){
            ans = min(ans, a[i].first/abs(a[i].second-l));
            ans = min(ans, a[i].first/abs(a[i].second-r));
        }
        l = min(l,a[i].second);
        r = max(r,a[i].second);
    }
    cout << ans << endl;
}
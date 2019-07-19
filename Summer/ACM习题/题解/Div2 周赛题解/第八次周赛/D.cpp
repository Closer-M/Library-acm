#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        string s;
        bool flg = 0;
        int cnt = 0;

        cin >> n >> s;

        for(int i=0;i<n;i++){
            if(s[i]=='8') flg = 1;
            if(flg) cnt++;
        }
        
        cout << (cnt>=11?"YES":"NO") << endl;
    }
    return 0;
}
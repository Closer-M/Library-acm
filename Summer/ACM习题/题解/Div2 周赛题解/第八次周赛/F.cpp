#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
int main(){
    string s,c;
    cin>>s;
    int len=s.length();
    c.clear();
    for(int i=0;i<s.size();i++){
        if(s[i]!='a') c+=s[i];
        if(c==s.substr(i+1)){
            cout<<s.substr(0,i+1)<<endl;
            exit(0);
        }
    }
    cout<<":(\n";
}
//by wyh
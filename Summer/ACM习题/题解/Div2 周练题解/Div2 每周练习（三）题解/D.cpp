#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
map<string,int>mm;
int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        if(mm[s]==0)cout<<"OK"<<endl,mm[s]++;
        else cout<<s<<mm[s]++<<endl;
    }


	return 0;
}

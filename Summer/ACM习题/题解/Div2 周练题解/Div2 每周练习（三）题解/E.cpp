#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cctype>
#include<sstream>
using namespace std;

string s,buf;
set<string>dict;
int main()
{

    while(cin>>s)
    {
        //cout<<"   1   "<<s<<endl;
        int len=s.length();
        string ss="";
        for(int i=0;i<len;i++)
        {
            if(isalpha(s[i]))
            {
                ss+=tolower(s[i]);
            }
            else
            {
                if(ss.empty())continue;
                else
                {
                    dict.insert(ss);
                    ss="";
                }
            }
        }
        if(!ss.empty())dict.insert(ss);

    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;
    return 0;
}

#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
char a[400000];

int main()
{

    char s;
    while(~scanf("%s",a))
    {
        int len=strlen(a);
        int l=0;
        while(l<len)
        {
            for(int i=l;i<len;i++)
            {
                printf("%c",a[i]);
            }
            printf("~\n");
            if(a[l]<0)l+=2;
            else l++;
        }
    }



    return 0;
}

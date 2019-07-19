#include<iostream>
using namespace std;
int year, month, day;
bool check(int y){
	if((y%4 ==0 && y%100 != 0)||y%400==0)
		return true;
	else
		return false;
}
int main()
{
	int n, sum, i, j;
	int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	cin>>n;
	for(i=0;i<n; i++){
		cin>>year>>month>>day;
		sum=0;
		for(j=1; j<year; j++){
			if(check(j))
				sum+=366;
			else
				sum+=365;
		}
		for(j=1; j<month; j++){
			if(j==2){
				if(check(year)) sum+=29;
				else sum+=m[2];
			}
				else sum+=m[j];
		}
		sum+=day;
		cout<<sum<<endl;
	}
}

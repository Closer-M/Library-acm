#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;
stack<char> S;

void cle()    //stack没有清空的成员函数，所以用pop清
{
	while (!S.empty())
		S.pop();
}
bool match(string str)   //进行括号匹配
{

	for (int i = 0; i<str.size(); i++)
	{
		switch (str[i])
		{
		case '[':
		case '(':
			S.push(str[i]);      //左括号先进栈
			break;
		case ')':
		    if(S.empty())return false;                       //line 22 to 39  就像消消乐，如果匹配，那么最靠近该类型右括号的肯定是相应类型的左括号，此时左右抵消
			else if (S.top() == '(')
				S.pop();           //抵消的操作，出栈这个匹配的左括号
			else
				return false;
			break;
		case ']':
		    if(S.empty())return false;
		    else if (S.top() == '[')
				S.pop();
			else
				return false;
			break;
		}
	}
	if (S.empty())
		return true;
	else
		return false;
}
int main()
{
	int t;
	string str;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
	    getline(cin,str);
		//scanf("%s",str);

		if (match(str))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cle();
	}
	return 0;
}

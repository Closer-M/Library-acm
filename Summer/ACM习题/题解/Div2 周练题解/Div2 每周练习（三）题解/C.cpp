#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;
stack<char> S;

void cle()    //stackû����յĳ�Ա������������pop��
{
	while (!S.empty())
		S.pop();
}
bool match(string str)   //��������ƥ��
{

	for (int i = 0; i<str.size(); i++)
	{
		switch (str[i])
		{
		case '[':
		case '(':
			S.push(str[i]);      //�������Ƚ�ջ
			break;
		case ')':
		    if(S.empty())return false;                       //line 22 to 39  ���������֣����ƥ�䣬��ô��������������ŵĿ϶�����Ӧ���͵������ţ���ʱ���ҵ���
			else if (S.top() == '(')
				S.pop();           //�����Ĳ�������ջ���ƥ���������
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

// stack �ںܴ�̶����Ǻ� queue �ǲ���
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>//ʹ�� stack ջ������Ҫ����ͷ�ļ�
using namespace std;
int main()
{
	stack<int>s;//Ĭ�Ϲ��캯��������һ���յ�stack���� s 
	/* ���������� stack �ĳ�Ա����
	empty() ջ�� Ϊ���򷵻��棨ջ��û��Ԫ�أ�
	pop() ɾ�� ջ��Ԫ�� �����������ж�ջ���Ƿ�Ϊ��
	push() �� ջ�� ����Ԫ��
	size() ���� ջ�е�Ԫ����Ŀ
	top() ���� ջ����Ԫ��
	*/
	while (!s.empty())
	{
		s.pop();// ��ջ �����ǽ�ջ�е�����Ԫ��ɾ��
	}//�����õ��� empty ���Ƕ�ջ���Ƿ�Ϊ�յ��ж�

	system("pause");
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	// ������ջ����
	stack<int> s;
	// Ԫ����ջ
	s.push(3);
	s.push(19);
	s.push(23);
	s.push(36);
	s.push(50);
	s.push(4);

	// Ԫ�����γ�ջ
	while (!s.empty())
	{
		// ��ӡջ��Ԫ�أ���ӡ����4 50 36 23 19 3
		cout << s.top() << endl;
		// ��ջ
		s.pop();
	}
	system("pause");
	return 0;
}
/*
����һ�εĴ���Ϳ��Կ��� stack �� queue ֮������� ���� Ԫ�صĳ�ջ����ջ��
queue �Ƕ��� �Ƚ�ȥ���ȳ��� �ͺ��Ŷ�һ��
stack ���Ǻ��ȥ���ȳ���
*/
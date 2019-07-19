/*
һ������˼·��
������ı��ʽת���ɺ�׺���ʽ��Ȼ��Ժ�׺���ʽ��������

��������ʽת��Ϊ��׺���ʽ��
1���������Ҷ�ȡ����������
2����Ϊ���ֽ�����д���ַ���A��
3����Ϊ���������ջ����������Ƚ����ȼ�

3 - 1����ջΪ�ջ�Ϊ��(����ֱ��ѹ��ջ��
3 - 2�������ȼ���ֱ��ѹ�뵽ջ��
3 - 3�������ȼ��ͻ������ջ����Ԫ�ص��������뵽A�У������µ�ջ��Ԫ�رȽ�

4����Ϊ����

4 - 1����Ϊ'( '����ֱ��Ҫ�뵽ջ��
4 - 2����Ϊ'��'���ջ����ʼ����Ԫ�����η��뵽A��ֱ����������ɾ���������

5���ظ���������ֱ����ʽ����

ע����Ϊ�������ȼ���ͬ����ߵ��������ʱҪ��ջ������������������뵽�ַ����У��������ڵ������������С�ڵ��ڶ���������3 - 3�����ֻ���ж����μ��ɡ�

��������
1����ȡ�ո�ת���ɺ�׺���ʽ���ַ���A���������Ҷ�ȡ
2����Ϊ���֣�����ѹ�뵽ջB��
3����Ϊ����������ȡ������ջ���ϵ�����Ԫ�ؽ������㣨�ȳ���Ԫ��Ϊ��һ��Ԫ�أ��������ѹ�뵽ջ�г�Ϊ�µ�ջ��Ԫ�ء�
4���ظ�������������ֱ��A���������Ϊջ��Ԫ��
*/
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
	map<char, int>symbol;
	symbol[')'] = 1;
	symbol['('] = 2;
	symbol['+'] = 3;
	symbol['-'] = 3;
	symbol['/'] = 4;
	symbol['*'] = 5;
	symbol['^'] = 6;
	string s;
	while (cin >> s)
	{
		stack<char>sign;
		stack<int>digit;
		string storage;
		for (int i = 0; i < s.length(); i++)// ��������ʽת��Ϊ��׺���ʽ
		{
			if (s[i] >= '0'&&s[i] <= '9')//��������� ֱ�� �ӵ� storage �н��д洢
			{
				storage = storage + s[i];
			}
			else
			{
				if (sign.empty())//������������ �� sign ��Ϊ�� ��ֱ�ӽ�������ż��� sign ��
				{
					sign.push(s[i]);
				}
				else if (symbol[s[i]] >= symbol[sign.top()] || s[i] == '(')//����� ( ����������ŵ����ȼ����� sign ��ջ���ĵ�������� ��ֱ��ѹ��ջ��
				{
					sign.push(s[i]);
				}
				else if (symbol[s[i]] < symbol[sign.top()] && symbol[s[i]]>1)//�������������ȼ����� sign ��ջ����������� �� sign �е�Ԫ��һ����ѹ�����ԱȲ��������storage ֱ�����ȼ���Ȼ��߸���Ϊֹ
				{
					while (symbol[s[i]] < symbol[sign.top()])
					{
						storage = storage + sign.top();
						sign.pop();
						if (sign.empty())//��� sign Ϊ�յ�ʱ�� ����ֱ���˳�ѭ�� ��������һ��ѭ��ʱ�ĶԱ�Ҳ�ᵼ�´���
						{
							break;
						}

					}
					sign.push(s[i]);
				}
				else if (s[i] == ')')//����� ) �� sign ��ջ����Ԫ��һ����ѹ�������뵽 storage �н��д洢 ֱ���ҵ� ) Ϊֹ���� ͬʱ����һ������ɾ��
				{
					while (sign.top() != '(')
					{
						storage = storage + sign.top();
						sign.pop();
					}
					sign.pop();
				}
			}
		}
		while (!sign.empty())
		{
			storage = storage + sign.top();
			sign.pop();
		}
		int result;
		for (int i = 0; i < storage.length(); i++)// ��������
		{
			int a, b;
			if (storage[i] >= '0'&&storage[i] <= '9')//��������� ֱ�� �ӵ� digit �н��д洢
			{
				digit.push(storage[i] - '0');
			}
			else
			{
				b = digit.top();
				digit.pop();
				a = digit.top();
				digit.pop();
				if (storage[i] == '+')
				{
					result = a + b;
				}
				else if (storage[i] == '-')
				{
					result = a - b;
				}
				else if (storage[i] == '*')
				{
					result = a * b;
				}
				else if (storage[i] == '/')
				{
					result = a / b;
				}
				else if (storage[i] == '^')
				{
					result = pow(a, b);
				}
				digit.push(result);
			}
		}
		cout << digit.top() << endl;
	}
	system("pause");
	return 0;
}
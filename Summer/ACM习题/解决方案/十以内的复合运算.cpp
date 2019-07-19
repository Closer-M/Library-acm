/*
一、基本思路：
将输入的表达式转化成后缀表达式，然后对后缀表达式进行运算

二、将算式转化为后缀表达式：
1、从左向右读取输入的运算符
2、若为数字将数字写入字符串A中
3、若为运算符，与栈顶的运算符比较优先级

3 - 1、若栈为空或为‘(’则直接压入栈中
3 - 2、若优先级高直接压入到栈中
3 - 3、若优先级低或相等则将栈顶的元素弹出并放入到A中，再与新的栈顶元素比较

4、若为括号

4 - 1、若为'( '则将其直接要入到栈中
4 - 2、若为'）'则从栈顶开始弹出元素依次放入到A中直到遇到（并删除这对括号

5、重复上述步骤直到算式读完

注：因为遇到优先级相同或更高的运算符号时要将栈顶的运算符弹出并加入到字符串中，所以相邻的运算符的数量小于等于二，所以在3 - 3处最多只需判断两次即可。

三、运算
1、读取刚刚转化成后缀表达式的字符串A，从左向右读取
2、若为数字，则将其压入到栈B中
3、若为运算符，则读取并弹出栈堆上的两个元素进行运算（先出的元素为第一个元素），将结果压入到栈中成为新的栈顶元素。
4、重复上述两个步骤直到A结束，结果为栈顶元素
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
		for (int i = 0; i < s.length(); i++)// 二：将算式转化为后缀表达式
		{
			if (s[i] >= '0'&&s[i] <= '9')//如果是数字 直接 加到 storage 中进行存储
			{
				storage = storage + s[i];
			}
			else
			{
				if (sign.empty())//如果是运算符号 且 sign 中为空 则直接将运算符号加入 sign 中
				{
					sign.push(s[i]);
				}
				else if (symbol[s[i]] >= symbol[sign.top()] || s[i] == '(')//如果是 ( 或者运算符号的优先级高于 sign 中栈顶的的运算符号 则直接压入栈中
				{
					sign.push(s[i]);
				}
				else if (symbol[s[i]] < symbol[sign.top()] && symbol[s[i]]>1)//如果运算符的优先级低于 sign 中栈顶的运算符号 则将 sign 中的元素一个个压出并对比并将其加入storage 直到优先级相等或者高于为止
				{
					while (symbol[s[i]] < symbol[sign.top()])
					{
						storage = storage + sign.top();
						sign.pop();
						if (sign.empty())//如果 sign 为空的时候 必须直接退出循环 就算是下一次循环时的对比也会导致错误
						{
							break;
						}

					}
					sign.push(s[i]);
				}
				else if (s[i] == ')')//如果是 ) 则将 sign 中栈顶的元素一个个压出并加入到 storage 中进行存储 直到找到 ) 为止结束 同时将这一对括号删除
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
		for (int i = 0; i < storage.length(); i++)// 三：运算
		{
			int a, b;
			if (storage[i] >= '0'&&storage[i] <= '9')//如果是数字 直接 加到 digit 中进行存储
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
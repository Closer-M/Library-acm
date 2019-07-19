// stack 在很大程度上是和 queue 是差不多的
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
#include<stack>//使用 stack 栈容器需要加入头文件
using namespace std;
int main()
{
	stack<int>s;//默认构造函数，创建一个空的stack对象 s 
	/* 接下来介绍 stack 的成员函数
	empty() 栈堆 为空则返回真（栈内没有元素）
	pop() 删除 栈顶元素 ，不会自行判断栈堆是否为空
	push() 在 栈顶 增加元素
	size() 返回 栈中的元素数目
	top() 返回 栈顶的元素
	*/
	while (!s.empty())
	{
		s.pop();// 出栈 ，这是将栈中的所有元素删除
	}//这里用到的 empty 就是对栈内是否为空的判断

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
	// 创建堆栈对象
	stack<int> s;
	// 元素入栈
	s.push(3);
	s.push(19);
	s.push(23);
	s.push(36);
	s.push(50);
	s.push(4);

	// 元素依次出栈
	while (!s.empty())
	{
		// 打印栈顶元素，打印出：4 50 36 23 19 3
		cout << s.top() << endl;
		// 出栈
		s.pop();
	}
	system("pause");
	return 0;
}
/*
从这一段的代码就可以看出 stack 和 queue 之间的区别 在于 元素的出栈和入栈上
queue 是队列 先进去的先出来 就和排队一样
stack 则是后进去的先出来
*/
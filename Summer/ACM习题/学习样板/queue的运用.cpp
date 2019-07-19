#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
int main()
{
	int e, n, m;
	queue<int> q1, q[100000];//用queue可以同时开多个队列，如 q[100000]
	for (int i = 0; i < 10; i++)
		q1.push(i);//在队列最后加入元素
	if (!q1.empty())
		cout << "dui lie  bu kongn" << endl;
	n = q1.size();
	cout << n << endl;//输出元素个数
	m = q1.back();
	cout << m << endl;//输出最后队列中的最后一个元素
	for (int j = 0; j < n; j++)//依次输出队列中最前面的元素，然后删除掉最前面的元素
	{
		e = q1.front();
		cout << e << " ";
		q1.pop();
	}
	cout << endl;
	if (q1.empty())
		cout << "dui lie  bu kongn" << endl;
	system("pause");
	return 0;
}

//back() 返回最后一个元素

//empty() 如果队列空则返回真

//front() 返回第一个元素

//pop() 删除第一个元素

//push() 在末尾加入一个元素

//size() 返回队列中元素的个数

#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include <assert.h>
/*
调用的时候要有头文件： #include<stdlib.h> 或 #include<cstdlib> +
#include<queue>       #include<queue>
详细用法:
定义一个queue的变量     queue<Type> M
查看是否为空范例        M.empty()    是的话返回1，不是返回0;
从已有元素后面增加元素   M.push()
输出现有元素的个数      M.size()
显示第一个元素          M.front()
显示最后一个元素        M.back()
清除第一个元素          M.pop()
*/
using namespace std;
int main()
{
	//https://blog.csdn.net/woshihuangjianwei/article/details/78022521
	//priority_queue默认为大顶堆，即堆顶元素为堆中最大元素
	//如果我们想要用小顶堆的话需要增加使用两个参数
	priority_queue<int, vector<int>, greater<int> > q;  // 小顶堆,用top()输出,后面只能 > > ,不能>>
	priority_queue<int, vector<int>, less<int> > q;     // 大顶堆
	queue <int> myQ;
	cout << "现在 queue 是否 empty? " << myQ.empty() << endl;
	for (int i = 0; i < 10; i++)
	{
		myQ.push(i);
	}
	for (int i = 0; i < myQ.size(); i++)
	{
		printf("myQ.size():%d\n", myQ.size());
		cout << myQ.front() << endl;
		myQ.pop();
	}
	system("pause");
	return 0;
}

//尽管提供了大小顶堆的模板

//但是我们在实际应用过程中往往会使用更加复杂的数据结构构建堆

//这时候我们就需要自定义数据结构的比较方式了

int main()
{
	//方式一：
	struct Node {
		int x, y;
		Node(int a = 0, int b = 0) :x(a), y(b) {}
	};

	struct cmp {
		bool operator() (const Node& a, const Node& b) {
			if (a.x == b.x)
				return a.y > b.y;
			return a.x > b.x;
		}
	};

	priority_queue<Node, vector<Node>, cmp> q;

	//方式二 
	struct Node {
		int x, y;
		Node(int a = 0, int b = 0) :x(a), y(b) {}
	};

	bool operator < (const Node& a, const Node& b) {
		if (a.x == b.x)
			return a.y > b.y;
		return a.x > b.x;
	}
	system("pause");
	return 0;
}
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
	queue<int> q1, q[100000];//��queue����ͬʱ��������У��� q[100000]
	for (int i = 0; i < 10; i++)
		q1.push(i);//�ڶ���������Ԫ��
	if (!q1.empty())
		cout << "dui lie  bu kongn" << endl;
	n = q1.size();
	cout << n << endl;//���Ԫ�ظ���
	m = q1.back();
	cout << m << endl;//����������е����һ��Ԫ��
	for (int j = 0; j < n; j++)//���������������ǰ���Ԫ�أ�Ȼ��ɾ������ǰ���Ԫ��
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

//back() �������һ��Ԫ��

//empty() ������п��򷵻���

//front() ���ص�һ��Ԫ��

//pop() ɾ����һ��Ԫ��

//push() ��ĩβ����һ��Ԫ��

//size() ���ض�����Ԫ�صĸ���

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
���õ�ʱ��Ҫ��ͷ�ļ��� #include<stdlib.h> �� #include<cstdlib> +
#include<queue>       #include<queue>
��ϸ�÷�:
����һ��queue�ı���     queue<Type> M
�鿴�Ƿ�Ϊ�շ���        M.empty()    �ǵĻ�����1�����Ƿ���0;
������Ԫ�غ�������Ԫ��   M.push()
�������Ԫ�صĸ���      M.size()
��ʾ��һ��Ԫ��          M.front()
��ʾ���һ��Ԫ��        M.back()
�����һ��Ԫ��          M.pop()
*/
using namespace std;
int main()
{
	//https://blog.csdn.net/woshihuangjianwei/article/details/78022521
	//priority_queueĬ��Ϊ�󶥶ѣ����Ѷ�Ԫ��Ϊ�������Ԫ��
	//���������Ҫ��С���ѵĻ���Ҫ����ʹ����������
	priority_queue<int, vector<int>, greater<int> > q;  // С����,��top()���,����ֻ�� > > ,����>>
	priority_queue<int, vector<int>, less<int> > q;     // �󶥶�
	queue <int> myQ;
	cout << "���� queue �Ƿ� empty? " << myQ.empty() << endl;
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

//�����ṩ�˴�С���ѵ�ģ��

//����������ʵ��Ӧ�ù�����������ʹ�ø��Ӹ��ӵ����ݽṹ������

//��ʱ�����Ǿ���Ҫ�Զ������ݽṹ�ıȽϷ�ʽ��

int main()
{
	//��ʽһ��
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

	//��ʽ�� 
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
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<stdio.h>
#include<queue>
using namespace std;
const int V = 100000;
const int E = 100000;
struct Edge
{
	int to;//��ʾ�����ߵ���һ������
	int cost;//ָ����һ���ߵ������±꣬���ֵΪ -1 ���ʾû����һ����
};

// head[i] ��ʾ���� i �ĵ�һ���ߵ������±꣬-1 ��ʾ���� i û�б�
int head[V];
Edge edge[E];

memset(head, -1, sizeof(head));//��ʽǰ����

//���ӱߵķ�ʽ��a -> b �ñߵ������±�Ϊ id
inline void addedge(int a, int b, int id)
{
	edge[id].to = b;
	edge[id].cost = head[a];
	head[a] = id;
	return;
}

int main()
{
	//����� a ���ȥ�����б�
	for (int i = head[a]; i != -1; i = edge[i].cost)
	{

	}
	return 0;
}
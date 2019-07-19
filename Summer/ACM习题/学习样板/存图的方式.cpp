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
	int to;//表示这条边的下一个顶点
	int cost;//指向下一条边的数组下标，如果值为 -1 则表示没有下一条边
};

// head[i] 表示顶点 i 的第一条边的数组下标，-1 表示顶点 i 没有边
int head[V];
Edge edge[E];

memset(head, -1, sizeof(head));//链式前向星

//增加边的方式，a -> b 该边的数组下标为 id
inline void addedge(int a, int b, int id)
{
	edge[id].to = b;
	edge[id].cost = head[a];
	head[a] = id;
	return;
}

int main()
{
	//历遍从 a 点出去的所有边
	for (int i = head[a]; i != -1; i = edge[i].cost)
	{

	}
	return 0;
}
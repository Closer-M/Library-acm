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
//������ͷ head �����ڽӱ�
int head[6010], ver[6010], nxt[6010], step = 0;
int f[6010][2];
void add(int fa, int son)//ÿһ�β���һ��Ԫ��
{
	step++;//��¼��������Ϣ������λ��
	ver[step] = son;//��¼�����ı��
	nxt[step] = head[fa];//�ӱ�ͷ����ǰһ�����ָ��нӹ���
	head[fa] = step;//�ڱ�ͷ���趨һ��ָ��ָ�����ڵ�Ԫ��
}
void dfs(int n)
{
	for (int i = head[n]; i; i = nxt[i])//�� n Ϊ���ڵ�������ӽڵ�����
	{
		int pre = ver[i];
		dfs(pre);//������ӽڵ�Ϊ���ڵ������������
		//�� dfs(pre) �������Ѻ������������൱�ڽ�����һ�λ���
		f[n][1] += f[pre][0];//��̬�滮�Ĺ���
		f[n][0] += max(f[pre][0], f[pre][1]);
	}
}
int list[6010];
int find(int i)
{
	if (list[i] == i)
	{
		return i;
	}
	else
	{
		find(list[i]);
	}
}
int main()
{
	int T;
	while (cin >> T)
	{
		for (int i = 1; i < T; i++)
		{
			list[i] = i;
		}
		memset(head, 0, sizeof(head));
		memset(ver, 0, sizeof(ver));
		memset(nxt, 0, sizeof(nxt));
		memset(f, 0, sizeof(f));
		step = 0;
		for (int i = 1; i <= T; i++)
		{
			cin >> f[i][1];
		}
		for (int i = 1; i <= T; i++)
		{
			int a, b;
			cin >> a >> b;
			list[a] = b;
			add(b, a);
		}
		int h = find(1);
		dfs(h);
		cout << max(f[h][1], f[h][0]) << endl;
	}


	system("pause");
	return 0;
}
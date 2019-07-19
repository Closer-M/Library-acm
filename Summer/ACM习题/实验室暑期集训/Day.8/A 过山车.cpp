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
#include<cstring>
using namespace std;
//���ǽ����ֵ����е�ֳ��������飬������������ݶ����ڼ�¼�ұ�һ���ƥ�����
int head[505], nxt[505], ver[505], visit[505], match[505], step = 0;
int k, m, n, u, v;
int sum;
bool dfs(int x)//�� x ��Ϊ���ڵ�
{
	for (int i = head[x]; i; i = nxt[i])//���������������ӽڵ�
	{
		int y = ver[i];
		if (!visit[y])
		{
			visit[i] = 1;//�������ķ���״̬��Ϊ 1 ���ѷ���
			// match ��ָ�����������ƥ�����
			if (!match[y] || dfs(match[y]))//����������Ѿ�ƥ�������֮ǰ��ƥ�������еݹ����
			{
				match[y] = x;//��ֵ������ƥ�����Ϊ x
				return true;
			}
		}
	}
	return false;
}
void add(int fa, int son)
{
	step++;
	ver[step] = son;
	nxt[step] = head[fa];
	head[fa] = step;
}
int main() {
	while (cin >> k)
	{
		if (k == 0)
		{
			break;
		}
		cin >> n >> m;
		sum = 0;
		//��ʼ��
		memset(match, 0, sizeof(match));
		for (int i = 1; i <= k; i++)
		{
			cin >> u >> v;
			add(u, v);
		}
		for (int i = 1; i <= n; i++)
		{
			memset(visit, 0, sizeof(visit));
			if (dfs(i))sum++;
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
#define ll long long
const long long N = 1e5 + 7;
//��ȫ������
//    1         �ô�������ֻ�Ǹýڵ�ı�Ƕ��ѣ�l �� r ��ֵ���Ǹýڵ������е���������
//  2   3
// 4 5 6 7
ll save[N * 4];
struct Tree
{
	int l, r;
	ll sum, lz, max, min;
	void newdate(ll v)//����ȡ������ֵ��������
	{
		sum += v * (r - l + 1);
		lz += v;
		max += v;
		min += v;
	}
}tree[N * 4];
/*void modify(ll *arr)//�洢����
{
	save = arr;
}*/
void pushup(int x)//���ϻ���,�ع�����
{
	tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
	//tree[x].max = max(tree[2 * x].max, tree[2 * x + 1].max);
	//tree[x].min = min(tree[2 * x].min, tree[2 * x + 1].min);
}
void pushdown(int x)//���� lz ������չ��ͬʱ���� lz
{
	if (tree[x].lz != 0)
	{
		tree[2 * x].newdate(tree[x].lz);
		tree[2 * x + 1].newdate(tree[x].lz);
		tree[x].lz = 0;
	}
}
	//����,���������ÿ���ڵ��������ĸ����ݣ��½��ܺ� sum �½����ֵ max �½���Сֵ min �ӳټ���ֵ lazy��lz��
void build(int x, int l, int r)
{
	tree[x].l = l;
	tree[x].r = r;
	tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;//��ʼ��ÿ���ڵ㴦���ĸ�ֵ
	if (l == r)//�� l==r ��ʱ��˵���Ѿ���չ����ײ�Ҷ�Ӵ�����ʼ��ֵ��׼������
	{
		tree[x].sum = tree[x].max = tree[x].min = save[l];//�� save �д洢�е�������ȡ�����У�������ֵ���ܺͣ����ֵ�Լ���Сֵ�����Լ�
		return;
	}
	int mid = (l + r) / 2;
	build(2 * x, l, mid);//���¹�������
	build(2 * x + 1, mid + 1, r);//���¹�������
	pushup(x);//�������׺����ϻ���
}
	//���� l-r �� c
void updateADD(int x, int l, int r, ll c)//������һ��Ҷ�Ӵ������ݽ��и���
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;// mid �Ǹ�������ʱ��һ����ǣ������˽��������������һ�����������
	if ((l <= L) && (r >= R))//���Ѳ�Ķ����������ڵ�ʱ��ֱ���ڸýڵ�������ݸ���
	{
		tree[x].newdate(c);
		return;
	}
	pushdown(x);//�ýڵ㴦����������� lz ֵ���䴫����ȥ
	if (l <= mid)//������������չ
	{
		updateADD(2 * x, l, r, c);
	}
	if (r > mid)//������������չ
	{
		updateADD(2 * x + 1, l, r, c);
	}
	pushup(x);//����
}
	//��ѯ���� l-r �ĺ�
ll querySUM(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;
	ll res = 0;
	if ((l <= L) && (r >= R))//Ҫ������������˸�����
	{
		return tree[x].sum;
	}
	pushdown(x);
	if (l <= mid)
	{
		res += querySUM(2 * x, l, r);
	}
	if (r > mid)
	{
		res += querySUM(2 * x + 1, l, r);
	}
	pushup(x);
	return res;
}
	//��ѯ���� l-r ����Сֵ
ll queryMIN(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;
	ll res = 0x3f;
	if ((l <= L) && (r >= R))//Ҫ������������˸�����
	{
		return tree[x].min;//ֱ�ӽ��ܺͷ���
	}
	pushdown(x);//������ lz ֵ�����Ľڵ㣬����� lz ֵ�����ƽ���ȥ
	if (l <= mid)
	{
		res = min(res, queryMIN(2 * x, l, r));
	}
	if (r > mid)
	{
		res = min(res, queryMIN(2 * x + 1, l, r));
	}
	pushup(x);//��Ϊ�����ƽ��� lz ֵ��������Ҫ����
	return res;
}
	//���Ҫ����ֵ��������ȫ�ֱ���
	//ʹ��ǰ�ǵý� SUM��MAX,MIN ��ʼ��
ll SUM, MAX, MIN;
void query(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;
	if ((l <= L) && (r >= R))//Ҫ������������˸�����
	{
		SUM += tree[x].sum;
		MAX = max(MAX, tree[x].max);
		MIN = min(MIN, tree[x].min);
		return;
	}
	pushdown(x);
	if (l <= mid)
	{
		query(2 * x, l, r);
	}
	if (r > mid)
	{
		query(2 * x + 1, l, r);
	}
	pushup(x);
}
int main()
{
	FAST_IO;
	int T;
	while (cin >> T)
	{
		int load = 0;
		while (T--)
		{
			load++;
			int n, step = 0;
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				cin >> save[i];
			}
			build(1, 1, n);
			string s;
			cout << "Case " << load << ":" << endl;
			while (cin >> s)
			{
				int a, b;
				if (s == "Query")
				{

					cin >> a >> b;
					cout << querySUM(1, a, b) << endl;
				}
				else if (s == "Add")
				{
					cin >> a >> b;
					updateADD(1, a, a, b);
				}
				else if (s == "Sub")
				{
					cin >> a >> b;
					updateADD(1, a, a, -1 * b);
				}
				else
				{
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}
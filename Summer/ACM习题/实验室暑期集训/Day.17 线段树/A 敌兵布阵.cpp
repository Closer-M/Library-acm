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
//完全二叉树
//    1         该处的数字只是该节点的标记而已，l 与 r 的值才是该节点在题中的数据所在
//  2   3
// 4 5 6 7
ll save[N * 4];
struct Tree
{
	int l, r;
	ll sum, lz, max, min;
	void newdate(ll v)//将获取到的数值并入树中
	{
		sum += v * (r - l + 1);
		lz += v;
		max += v;
		min += v;
	}
}tree[N * 4];
/*void modify(ll *arr)//存储数据
{
	save = arr;
}*/
void pushup(int x)//向上回溯,回归数据
{
	tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
	//tree[x].max = max(tree[2 * x].max, tree[2 * x + 1].max);
	//tree[x].min = min(tree[2 * x].min, tree[2 * x + 1].min);
}
void pushdown(int x)//利用 lz 向下延展，同时重置 lz
{
	if (tree[x].lz != 0)
	{
		tree[2 * x].newdate(tree[x].lz);
		tree[2 * x + 1].newdate(tree[x].lz);
		tree[x].lz = 0;
	}
}
	//建树,在这棵树的每个节点里面有四个数据，下界总和 sum 下界最大值 max 下界最小值 min 延迟计算值 lazy（lz）
void build(int x, int l, int r)
{
	tree[x].l = l;
	tree[x].r = r;
	tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;//初始化每个节点处的四个值
	if (l == r)//当 l==r 的时候说明已经延展至最底层叶子处，开始赋值，准备回溯
	{
		tree[x].sum = tree[x].max = tree[x].min = save[l];//将 save 中存储中的数据提取到树中，单个数值的总和，最大值以及最小值都是自己
		return;
	}
	int mid = (l + r) / 2;
	build(2 * x, l, mid);//向下构建左树
	build(2 * x + 1, mid + 1, r);//向下构建右树
	pushup(x);//构建到底后向上回溯
}
	//区间 l-r 加 c
void updateADD(int x, int l, int r, ll c)//将其中一个叶子处的数据进行更改
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;// mid 是辅助查找时的一个标记，决定了接下来向左树查找还是右树查找
	if ((l <= L) && (r >= R))//所搜查的对象包含这个节点时，直接在该节点进行数据更新
	{
		tree[x].newdate(c);
		return;
	}
	pushdown(x);//该节点处如果有滞留的 lz 值则将其传递下去
	if (l <= mid)//向左树继续延展
	{
		updateADD(2 * x, l, r, c);
	}
	if (r > mid)//向右树继续延展
	{
		updateADD(2 * x + 1, l, r, c);
	}
	pushup(x);//回溯
}
	//查询区间 l-r 的和
ll querySUM(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;
	ll res = 0;
	if ((l <= L) && (r >= R))//要更新区间包括了该区间
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
	//查询区间 l-r 的最小值
ll queryMIN(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;
	ll res = 0x3f;
	if ((l <= L) && (r >= R))//要更新区间包括了该区间
	{
		return tree[x].min;//直接将总和返回
	}
	pushdown(x);//遇到有 lz 值滞留的节点，将这个 lz 值向下推进下去
	if (l <= mid)
	{
		res = min(res, queryMIN(2 * x, l, r));
	}
	if (r > mid)
	{
		res = min(res, queryMIN(2 * x + 1, l, r));
	}
	pushup(x);//因为可能推进过 lz 值，所以需要回溯
	return res;
}
	//如果要求多个值，可以用全局变量
	//使用前记得将 SUM，MAX,MIN 初始化
ll SUM, MAX, MIN;
void query(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	int mid = (L + R) / 2;
	if ((l <= L) && (r >= R))//要更新区间包括了该区间
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
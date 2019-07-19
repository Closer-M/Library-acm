//深度优先搜索的基本模型
void dfs(int step)
{
	//判断边界 
	for (i = 1; i <= n; i++)  //尝试每一种可能 
	{
		dfs(step + 1)  //继续下一步 
	}
	return;  //返回 
}

/*
初步理解：
深度优先算法有一种不撞南墙不回头的理念在里面
所以说，在这个算法中会历遍几乎所有可能
*/

//https://www.cnblogs.com/OctoptusLian/p/7428362.html
//浅谈深度优先算法
#include<iostream>
#include<stdio.h>
using namespace std;
int a[10] = { 0 }, book[10] = { 0 }, n;
void dfs(int step)  //step表示现在站在第几个盒子面前 
{
	int i;
	if (step == n + 1)
	{
		//输出一种排列（1~n号盒子中的扑克牌编号) 
		for (i = 1; i <= n; i++)
			printf("%d", a[i]);
		printf("\n");
		return;  //返回之前的一步（最近调用dfs函数的地方） 
	}
	//此时站在第step个盒子面前，应该放哪张牌呢
	//按照1、2、3...n的顺序一一尝试 
	for (i = 1; i <= n; i++)
	{
		//判断扑克牌i是否还在手上 
		if (book[i] == 0) //book[i]等于0表示i号扑克牌仍然在手上 
		{
			a[step] = i;  //将i号扑克牌放入到第step个盒子中
			book[i] = 1;  //将book[i]设为1，表示i号扑克牌已经不在手上了

			dfs(step + 1);  //这里通过函数的递归调用来实现（自己调用自己）**********

			book[i] = 0;  //将刚才的扑克牌收回，才能进行下一次尝试（这一步很关键） 
		}
	}
	return;
}

int main()
{
	while (cin >> n)//输入的时候要注意n为1~9整数 
	{
		dfs(1);
	}//首先站在1号小盒子面前 
	system("pause");
	return 0;
}

int main()
{
	scanf("%d", &n);  //输入的时候要注意n为1~9整数 
	dfs(1);  //首先站在1号小盒子面前 
	getchar(); getchar();
	return 0;
}

//举例：

#include<iostream>
#include<stdio.h>
using namespace std;
int a[10] = { 0 }, book[10] = { 0 }, n = 0;
void dfs(int step)
{
	if (step == 10)
	{
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
		{
			cout << a[1] << a[2] << a[3] << "+" << a[4] << a[5] << a[6] << "=" << a[7] << a[8] << a[9] << endl;
		}
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (book[i] == 0)
		{
			book[i] = 1;
			a[step] = i;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}
int main()
{
	dfs(1);
	system("pause");
	return 0;
}
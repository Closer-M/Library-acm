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
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;

int main()
{
	FAST_IO;
	int T; 
	while (cin >> T)
	{
		while (T--)
		{
			char s[20010];
			cin >> s;//输入字符串 s
			int n = strlen(s);
			for (int i = 0; i < n; i++)//将字符串 s 复制一份到 s 后面
			{
				s[n + i] = s[i];
			}
			int i = 0, j = 1, k;//初始化指针 i 和 j 的位置，k 表示比较时向后延长的比较部分的长度
			while (i <= n && j <= n)//两个指针都还在字符串上时
			{
				for (k = 0; k < n&&s[i + k] == s[j + k]; k++);
				if (k == n)//指针 k 已超出原字符串的长度，跳出循环
				{
					break;
				}
				/*
				进行比较，比较是 s[i+k] 和 s[j+k] 的位置的字符大小
				由于求取的是字符串的最小表示
				所以较大的那一方要将自己的指针向后移动到比较处的后方
				*/
				if (s[i + k] > s[j + k])
				{
					i = i + k + 1;
					if (i == j)
					{
						i++;
					}
				}
				else
				{
					j = j + k + 1;
					if (i == j)
					{
						j++;
					}
				}
				
			}
			//比较结束时，较为靠前的指针是答案，输出时要加上 1
			cout << min(i, j) + 1 << endl;
		}
	}
	system("pause");
	return 0;
}
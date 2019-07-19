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
using namespace std;
int *doubleCapacity(const int* list, int size)
{
	int *p = new int[2 * size];
	for (int i = 0; i < size; i++)
	{
		p[i] = list[i];
	}
	return p;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int *p= new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		int *x = doubleCapacity(p, n);
		for (int i = 0; i < n; i++)
		{
			cout << x[i] << endl;
		}
	}
	system("pause");
	return 0;
}


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
int main()
{
	//&:地址运算符号

	//*:解引用运算符号

	int count = 5;
	int* pCount = &count;
	cout << count << endl;// count 是 5 的指
	cout << &count << endl;// &count 是 count 的地址
	cout << pCount << endl;// pCount 也是指 count 的地址
	cout << *pCount << endl;// *pCount 是 pCount 所指向的值
	pCount = &count;
	system("pause");
	return 0;
}


//从函数中返回指针
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
int* reverse(int* list, int size)
{
	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		int temp = list[j];
		list[j] = list[i];
		list[i] = temp;
	}
	return list;
}
void printArray(const int* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
}
int main()
{
	int list[] = { 1,2,3,4,5,6 };
	int *p = reverse(list, 6);
	printArray(p, 6);
	system("pause");
	return 0;
}
//������������Ļ���ģ��
void dfs(int step)
{
	//�жϱ߽� 
	for (i = 1; i <= n; i++)  //����ÿһ�ֿ��� 
	{
		dfs(step + 1)  //������һ�� 
	}
	return;  //���� 
}

/*
������⣺
��������㷨��һ�ֲ�ײ��ǽ����ͷ������������
����˵��������㷨�л����鼸�����п���
*/

//https://www.cnblogs.com/OctoptusLian/p/7428362.html
//ǳ̸��������㷨
#include<iostream>
#include<stdio.h>
using namespace std;
int a[10] = { 0 }, book[10] = { 0 }, n;
void dfs(int step)  //step��ʾ����վ�ڵڼ���������ǰ 
{
	int i;
	if (step == n + 1)
	{
		//���һ�����У�1~n�ź����е��˿��Ʊ��) 
		for (i = 1; i <= n; i++)
			printf("%d", a[i]);
		printf("\n");
		return;  //����֮ǰ��һ�����������dfs�����ĵط��� 
	}
	//��ʱվ�ڵ�step��������ǰ��Ӧ�÷���������
	//����1��2��3...n��˳��һһ���� 
	for (i = 1; i <= n; i++)
	{
		//�ж��˿���i�Ƿ������� 
		if (book[i] == 0) //book[i]����0��ʾi���˿�����Ȼ������ 
		{
			a[step] = i;  //��i���˿��Ʒ��뵽��step��������
			book[i] = 1;  //��book[i]��Ϊ1����ʾi���˿����Ѿ�����������

			dfs(step + 1);  //����ͨ�������ĵݹ������ʵ�֣��Լ������Լ���**********

			book[i] = 0;  //���ղŵ��˿����ջأ����ܽ�����һ�γ��ԣ���һ���ܹؼ��� 
		}
	}
	return;
}

int main()
{
	while (cin >> n)//�����ʱ��Ҫע��nΪ1~9���� 
	{
		dfs(1);
	}//����վ��1��С������ǰ 
	system("pause");
	return 0;
}

int main()
{
	scanf("%d", &n);  //�����ʱ��Ҫע��nΪ1~9���� 
	dfs(1);  //����վ��1��С������ǰ 
	getchar(); getchar();
	return 0;
}

//������

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
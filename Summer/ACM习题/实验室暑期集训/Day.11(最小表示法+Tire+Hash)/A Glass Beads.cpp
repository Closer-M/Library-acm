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
			cin >> s;//�����ַ��� s
			int n = strlen(s);
			for (int i = 0; i < n; i++)//���ַ��� s ����һ�ݵ� s ����
			{
				s[n + i] = s[i];
			}
			int i = 0, j = 1, k;//��ʼ��ָ�� i �� j ��λ�ã�k ��ʾ�Ƚ�ʱ����ӳ��ıȽϲ��ֵĳ���
			while (i <= n && j <= n)//����ָ�붼�����ַ�����ʱ
			{
				for (k = 0; k < n&&s[i + k] == s[j + k]; k++);
				if (k == n)//ָ�� k �ѳ���ԭ�ַ����ĳ��ȣ�����ѭ��
				{
					break;
				}
				/*
				���бȽϣ��Ƚ��� s[i+k] �� s[j+k] ��λ�õ��ַ���С
				������ȡ�����ַ�������С��ʾ
				���Խϴ����һ��Ҫ���Լ���ָ������ƶ����Ƚϴ��ĺ�
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
			//�ȽϽ���ʱ����Ϊ��ǰ��ָ���Ǵ𰸣����ʱҪ���� 1
			cout << min(i, j) + 1 << endl;
		}
	}
	system("pause");
	return 0;
}
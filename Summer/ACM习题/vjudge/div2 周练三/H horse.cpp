#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
using namespace std;
int a[1000000];
int b[1000000];
bool cmp(int a, int b)
{
	return(a > b);
}
int main()
{
	int n, x;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		sort(a, a + n, cmp);
		sort(b, b + n, cmp);
		x = 0;
		int ad = 0, ax = n - 1, bd = 0, bx = n - 1;
		while (ad <= ax)
		{
			if (a[ad] != b[bd])//˫����ǿ��ȣ���ǿ��ͬʱ
			{
				if (a[ad] > b[bd])//�����ɵ�ǿ����Ӯһ��
				{
					x++;
					ad++;
					bd++;
				}
				else//������ĸ�ǿ��������������ĺ�����
				{
					x--;
					ax--;
					bd++;
				}
			}
			else//˫����ǿ��ͬʱ
			{
				if (a[ax] > b[bx])//��ɵ�����ǿ����ʱ����Ӯһ��
				{
					ax--;
					bx--;
					x++;
				}
				else//ֱ������ɵ�����ȥ����������ǿ���ﵽ�������
				{
					if (a[ax] == b[bd])//��ɵ�������������ǿ��ͬʱ���;�
					{
						ax--;
						bd++;
					}
					else if (a[ax] < b[bd])//��ɵ����ݲ���������ǿʱ����һ��
					{
						ax--;
						bd++;
						x--;
					}
				}
			}
		}
		cout << x * 200 << endl;
	}
	system("pause");
	return 0;
}
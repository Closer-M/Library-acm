#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	try// try ��һ������Ĳ������
	{
		if (b == 0)// throw �������׳�һ������ֵ
		{
			throw 4;
		}
		cout << a << "/" << b << "=" << a / b << endl;
	}
	catch (int x)//�Դ������ı�д������ x ��ֵ����ǰ���׳��Ĵ���ֵ
	{
		cout << "Exception:an integer  " << x << "  cannot be divided by zero" << endl;
	}
	cout << "Execytion continues . . ." << endl;
	system("pause");
	return 0;
}

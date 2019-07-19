#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	try// try 是一个错误的捕获过程
	{
		if (b == 0)// throw 语句可以抛出一个错误值
		{
			throw 4;
		}
		cout << a << "/" << b << "=" << a / b << endl;
	}
	catch (int x)//对错误语句的编写，其中 x 的值就是前面抛出的错误值
	{
		cout << "Exception:an integer  " << x << "  cannot be divided by zero" << endl;
	}
	cout << "Execytion continues . . ." << endl;
	system("pause");
	return 0;
}

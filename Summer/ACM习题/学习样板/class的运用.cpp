#include<iostream>//在class中 :: 在将模块中的组成部分移动到大括号外面的时候可以使用  比如说 ： C::C()
#include<string>
#include<cmath>
using namespace std;
class C//class的运用中，目前可以将其内在化为三部分
{
public://初步理解，格式化的存在
	double R;//初步理解，建立变量（数据域）
	C()//第一部分·默认（构建）函数，这部分必须存在，应该是构建函数时防止无输入
	{
		R = 1;
	}
	C(double newR)//第二部分，构建函数，()中的数据是输入的数据，运算时使用
	{
		R = newR;
	}
	double S()//第三部分，函数部分，进行运算然后返回结果
	{
		return R * R;
	}
	double V()//第三部分，函数部分，进行运算然后返回结果
	{
		return R * R*R;
	}
};//总结一下，在初步的运用中，这三部分都是不可以少去的或者合并的

int main()
{
	C c1;//在主函数中 C 的作用，可以将其看作是类似于 int 的作用，进行一种定义
	C c2(5);//在定义的后面可以加括号也可以不加括号，如果加了括号，就必须在里面填入数值，相当于进行一次赋值，如果不填，则属于错误
	c1 = 10;//没有加括号的量，如果有需要，可以进行赋值，如果不赋值的话，将以默认值进行运算
	cout << c1.R << endl;
	cout << c1.S() << endl;
	cout << c2.R << endl;
	cout << c2.S() << endl;
	c2 = 8;//可以进行二次赋值
	cout << endl;
	cout << c2.R << endl;
	cout << c2.S() << endl;
	cout << c2.V() << endl;
	system("pause");
	return 0;
}//总结一下，也就是说，class 的意义可以初步理解为进行一次数据块的定义，作用是创造自己需要的变量，同时可以包括自己定义的函数等等， 所有同名的变量都将以这个 class 中的新规则进行运算。

//现在的获取数据与结果的方式：
// c1.R 得到其中R的数值
// c1.S() 得到这些数据根据其中的运算计算之后得到的结果 即 返回值

#include<iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include<cstdio>
#include<ctime>
using namespace std;
class Time
{
public:
	int hour;
	int minute;
	int second;
	int t;
	Time();
	Time(int tt);
	int h();
	int m();
	int s();
};
Time::Time()
{
	t = time(0);
	hour = (t / 3600 + 8) % 24;
	minute = (t % 3600) / 60;
	second = t % 60;
}
Time::Time(int tt)
{
	t = time(0) + tt;
	second = t % 60;
	minute = t % 3600 / 60;
	hour = (t / 3600 + 8) % 24;
}
int Time::h()
{
	return hour;
}
int Time::m()
{
	return minute;
}
int Time::s()
{
	return second;
}
int h[1000000];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	Time T;
	cout << "当前时间：" << endl;
	cout << T.h() << ":" << T.m() << ":" << T.s() << endl;
	Time Tt(555550);
	cout << "之后时间：" << endl;
	cout << Tt.h() << ":" << Tt.m() << ":" << Tt.s() << endl;
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
#include<stack>
#include<ctime>
#include<fstream>
#include<stdio.h>
using namespace std;
class Rational
{
public:
	Rational();
	Rational(int n, int d, int x);
	long long getn();
	long long getd();
	long long getx();
	Rational operator+(Rational& sRational);
	long long n;
	long long d;
	long long x;
	static long long gcd(int a, int b);
};
Rational::Rational()
{
	x = 0;
	n = 0;
	d = 0;
}
long long Rational::getn()//输出 n 的值
{
	return n;
}
long long Rational::getd()//输出 d 的值
{
	return d;
}
long long Rational::getx()//输出 x 的值
{
	return x;
}
long long Rational::gcd(int a, int b)//返回 a 和 b 的最大公因数
{
	long long n1 = abs(a);
	long long n2 = abs(b);
	long long s;
	if (n2 > n1)
	{
		s = n1;
		n1 = n2;
		n2 = s;
	}
	while (n2 != 0)
	{
		s = n1 % n2;
		n1 = n2;
		n2 = s;
	}
	return n1;
}
Rational::Rational(int n, int d, int x)// n 和 d 被约分
{
	long long f = gcd(n, d);//获取 f 得到 n 和 d 的最大公因数
	this->n = (d > 0 ? 1 : -1)*n / f;
	this->d = abs(d) / f;
	this->x = abs(x);
}
Rational Rational::operator+(Rational& sRational)//重载符号 + 得到约分后的数值
{
	long long a = n * sRational.getd() + d * sRational.getn();//分子相加
	long long b = d * sRational.getd();//通分分母
	long long c = x + sRational.getx();
	if (a > b)
	{
		c = c + a / b;
		a = a % b;
	}
	return Rational(a, b, c);//得到约分后的数值
}
int main()
{
	Rational sum(1, 2, 0);
	for (int i = 2; i < 100; i++)
	{
		Rational a(i, i + 1, 0);
		sum = sum + a;
	}
	cout << sum.getx() << "+" << sum.getn() << "/" << sum.getd() << endl;
	system("pause");
	return 0;
}
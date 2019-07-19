#include<iostream>//��class�� :: �ڽ�ģ���е���ɲ����ƶ��������������ʱ�����ʹ��  ����˵ �� C::C()
#include<string>
#include<cmath>
using namespace std;
class C//class�������У�Ŀǰ���Խ������ڻ�Ϊ������
{
public://������⣬��ʽ���Ĵ���
	double R;//������⣬����������������
	C()//��һ���֡�Ĭ�ϣ��������������ⲿ�ֱ�����ڣ�Ӧ���ǹ�������ʱ��ֹ������
	{
		R = 1;
	}
	C(double newR)//�ڶ����֣�����������()�е���������������ݣ�����ʱʹ��
	{
		R = newR;
	}
	double S()//�������֣��������֣���������Ȼ�󷵻ؽ��
	{
		return R * R;
	}
	double V()//�������֣��������֣���������Ȼ�󷵻ؽ��
	{
		return R * R*R;
	}
};//�ܽ�һ�£��ڳ����������У��������ֶ��ǲ�������ȥ�Ļ��ߺϲ���

int main()
{
	C c1;//���������� C �����ã����Խ��俴���������� int �����ã�����һ�ֶ���
	C c2(5);//�ڶ���ĺ�����Լ�����Ҳ���Բ������ţ�����������ţ��ͱ���������������ֵ���൱�ڽ���һ�θ�ֵ�������������ڴ���
	c1 = 10;//û�м����ŵ������������Ҫ�����Խ��и�ֵ���������ֵ�Ļ�������Ĭ��ֵ��������
	cout << c1.R << endl;
	cout << c1.S() << endl;
	cout << c2.R << endl;
	cout << c2.S() << endl;
	c2 = 8;//���Խ��ж��θ�ֵ
	cout << endl;
	cout << c2.R << endl;
	cout << c2.S() << endl;
	cout << c2.V() << endl;
	system("pause");
	return 0;
}//�ܽ�һ�£�Ҳ����˵��class ��������Գ������Ϊ����һ�����ݿ�Ķ��壬�����Ǵ����Լ���Ҫ�ı�����ͬʱ���԰����Լ�����ĺ����ȵȣ� ����ͬ���ı������������ class �е��¹���������㡣

//���ڵĻ�ȡ���������ķ�ʽ��
// c1.R �õ�����R����ֵ
// c1.S() �õ���Щ���ݸ������е��������֮��õ��Ľ�� �� ����ֵ

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
	cout << "��ǰʱ�䣺" << endl;
	cout << T.h() << ":" << T.m() << ":" << T.s() << endl;
	Time Tt(555550);
	cout << "֮��ʱ�䣺" << endl;
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
long long Rational::getn()//��� n ��ֵ
{
	return n;
}
long long Rational::getd()//��� d ��ֵ
{
	return d;
}
long long Rational::getx()//��� x ��ֵ
{
	return x;
}
long long Rational::gcd(int a, int b)//���� a �� b ���������
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
Rational::Rational(int n, int d, int x)// n �� d ��Լ��
{
	long long f = gcd(n, d);//��ȡ f �õ� n �� d ���������
	this->n = (d > 0 ? 1 : -1)*n / f;
	this->d = abs(d) / f;
	this->x = abs(x);
}
Rational Rational::operator+(Rational& sRational)//���ط��� + �õ�Լ�ֺ����ֵ
{
	long long a = n * sRational.getd() + d * sRational.getn();//�������
	long long b = d * sRational.getd();//ͨ�ַ�ĸ
	long long c = x + sRational.getx();
	if (a > b)
	{
		c = c + a / b;
		a = a % b;
	}
	return Rational(a, b, c);//�õ�Լ�ֺ����ֵ
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
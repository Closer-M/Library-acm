#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
template<typename T>//����һ��ģ��Ķ���
//����������֮ǰ�� class �еĶ����÷���� T �൱��һ���������� ֻ�����������������е���������
T m(T value1, T value2)
{
	if (value1 > value2)
	{
		return value1;
	}
	else
	{
		return value2;
	}
}
template<typename T1, typename T2, typename T3>//�������Ҫ�Ļ�����ͬʱ���ж������
/*Ҫע����ǣ��������Ҫ������嶨���ʱ��ֻ����һ������н��в��ܷ���������

template<typename T>
template<typename T1, typename T2, typename T3>

ǰһ�ζ��������ʱ����ܽ�����һ�ζ��壬��һ�ְ�����ϵ*/
int main()
{
	cout << m(1, 2) << endl;
	cout << m(1.5, 0.3) << endl;
	cout << m('a', 'b') << endl;
	cout << m("NBC", "ABC") << endl;
	int a, b;
	cin >> a >> b;
	cout << m(a, b) << endl;
	string A, B;
	cin >> A >> B;
	cout << m(A, B) << endl;

	cout << m(string("NBC"), string("ABC"));
	//��������� string���� ֮��Ƚϵ����ݾͲ����ַ��� ascii ���� �Ƚϵ����ַ����ڵĵ�ַ

	system("pause");
	return 0;
}
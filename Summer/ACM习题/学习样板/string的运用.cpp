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
int main()
{
	string s("welcome ");//�趨s���ַ�������

	s.append("to ");//��s�ĺ������ to 
	cout << s << endl;

	s.append("123456 ", 2, 6);//��"123456 "�еĵ�3��7���ַ��ӵ�����
	cout << s << endl;

	s.append(2, 'S');//��s�ĺ���������� S
	cout << s << endl;

	s.clear();//��� s �е�����
	cout << s << endl;

	string z("hello ");

	s.assign(z);//ֱ�ӽ� z �����ݸ�ֵ�� s ��
	cout << s << endl;

	s.assign(z, 3);//�� z �е�ǰ3���ַ����Ƶ� s �� (ע����������滻�����ǽ���)
	cout << s << endl;

	s.assign(z, 3, 4);//�� z �еĴӵ�3���ַ���ʼ�ĺ���4���ַ���ֵ�� s �� (ע����������滻�����ǽ���)
	cout << s << endl;

	s.assign(4, 'G');//�� 4��G ��ֵ�� s ��
	cout << s << endl;

	system("pause");
	return 0;
}

// �ַ�����������

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
int main()
{
	string s;
	s.append("My name si mayuhao!!");
	int t = s.find('n');//�����ַ����� �ַ� n ���ڵ�λ��
	cout << t << endl;

	t = s.find('M', 5);//���ַ��� s �еĵ�6���ַ���ʼ���� M �Ҳ��� ����  string::npos
	cout << t << endl;

	t = s.find('i', 5);//���ַ��� s �еĵ�6���ַ���ʼ���� i �ҵ� ���� 9
	cout << t << endl;

	system("pause");
	return 0;
}

//ֱ�ӽ��ַ������͵�����ת������ֵ

#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;
int main()
{
	string str1 = "1234";
	string str2 = "6";
	int n = atoi("123456");	//#include <cstdlib>
	int n1 = atoi(str1.c_str());
	int n2 = atoi(str2.c_str());
	cout << n + n1 << endl;
	cout << n1 + n2 << endl;
	system("pause");
	return 0;
}

//erase(n) ɾ���ַ������±�Ϊ n ���ַ�

substr��2���÷���
���裺string s = "0123456789";

string sub1 = s.substr(5); //ֻ��һ������5��ʾ���±�Ϊ5��ʼһֱ����β��sub1 = "56789"

string sub2 = s.substr(5, 3); //���±�Ϊ5��ʼ��ȡ����Ϊ3λ��sub2 = "567"
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
	string s("welcome ");//设定s的字符串内容

	s.append("to ");//在s的后面接上 to 
	cout << s << endl;

	s.append("123456 ", 2, 6);//将"123456 "中的第3到7个字符接到后面
	cout << s << endl;

	s.append(2, 'S');//在s的后面接上两个 S
	cout << s << endl;

	s.clear();//清除 s 中的内容
	cout << s << endl;

	string z("hello ");

	s.assign(z);//直接将 z 的内容赋值进 s 中
	cout << s << endl;

	s.assign(z, 3);//将 z 中的前3个字符复制到 s 中 (注意这里的是替换，不是接上)
	cout << s << endl;

	s.assign(z, 3, 4);//将 z 中的从第3个字符开始的后面4个字符赋值到 s 中 (注意这里的是替换，不是接上)
	cout << s << endl;

	s.assign(4, 'G');//将 4个G 赋值到 s 中
	cout << s << endl;

	system("pause");
	return 0;
}

// 字符串的搜索：

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
	int t = s.find('n');//返回字符串中 字符 n 所在的位置
	cout << t << endl;

	t = s.find('M', 5);//从字符串 s 中的第6个字符开始搜索 M 找不到 返回  string::npos
	cout << t << endl;

	t = s.find('i', 5);//从字符串 s 中的第6个字符开始搜索 i 找到 返回 9
	cout << t << endl;

	system("pause");
	return 0;
}

//直接将字符串类型的数字转换成数值

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

//erase(n) 删除字符串内下标为 n 的字符

substr有2种用法：
假设：string s = "0123456789";

string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"

string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"
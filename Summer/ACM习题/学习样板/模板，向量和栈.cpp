#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
template<typename T>//进行一次模板的定义
//这里的情况和之前的 class 中的定义用法差不多 T 相当于一种数据类型 只是它包含了其他所有的数据类型
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
template<typename T1, typename T2, typename T3>//如果有需要的话可以同时进行多个定义
/*要注意的是，这个定义要多个定义定义的时候只能在一个语句中进行不能分上下两句

template<typename T>
template<typename T1, typename T2, typename T3>

前一次定义结束的时候才能进行下一次定义，有一种包含关系*/
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
	//在里面加上 string（） 之后比较的内容就不是字符的 ascii 码了 比较的是字符所在的地址

	system("pause");
	return 0;
}
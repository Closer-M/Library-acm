#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<int, string> mapStudent;//目前的应用与学习中，map只有两个变量内容，first和second
	mapStudent.insert(make_pair(1, "student_one"));//insert用于输入，make_pair(frset,second)=pair<type1,type2>(first,second);
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	map<int, string>::iterator  iter;//前面应该属于格式 后面的 iter 是自定义的一个名字，便于后面的使用
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)//将其中内容按顺序全部输出
	{
		cout << iter->first << "  " << iter->second << endl;
	}
	system("pause");
	return 0;
}

int nSize = mapStudent.size();//返回其中的储存的数据的数量

#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	map<int, string>::reverse_iterator  iter;//重点在于这句话与下句话，可以使得输出时反向输出的
	for (iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)//在begin前加r，在end前也加
	{
		cout << iter->first << "   " << iter->second << endl;
	}
	system("pause");
	return 0;
}

#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	int nSize = mapStudent.size();//常规方法下的输出方式
	for (int nIndex = 1; nIndex <= nSize; nIndex++)
	{
		cout << mapStudent[nIndex] << endl;
	}
	system("pause");
	return 0;
}

//清空map中的数据可以用clear()函数，判定map中是否有数据可以用empty()函数，它返回true则说明是空map

//find的使用

#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<string, string> mapStudent;
	mapStudent.insert(pair<string, string>("1", "student_one"));
	mapStudent.insert(pair<string, string>("2", "student_two"));
	mapStudent.insert(pair<string, string>("3", "student_three"));
	map<string, string>::iterator iter;
	iter = mapStudent.find("2");
	if (iter != mapStudent.begin())
	{
		cout << "Find, the value is " << iter->second << endl;
	}
	else
	{
		cout << "Do not Find" << endl;
	}
	system("pause");
	return 0;
}

//lower_bound函数用法，这个函数用来返回要查找关键字的下界(是一个迭代器)
查找第一个大于或等于key的迭代器
//upper_bound函数用法，这个函数用来返回要查找关键字的上界(是一个迭代器)
查找第一个大于key的迭代器
//例如：map中已经插入了1，2，3，4的话

//如果lower_bound(2)的话，返回的2

//而upper - bound（2）的话，返回的就是3

//equal_range函数返回一个pair，pair里面第一个变量是Lower_bound返回的迭代器

//pair里面第二个迭代器是Upper_bound返回的迭代器

//如果这两个迭代器相等的话，则说明map中不出现这个关键字

#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<int, string> mapStudent;
	mapStudent[1] = "student_one";
	mapStudent[3] = "student_three";
	mapStudent[5] = "student_five";
	map<int, string>::iterator  iter;
	iter = mapStudent.lower_bound(2);
	{
		//返回的是下界3的迭代器
		cout << iter->second << endl;
	}
	iter = mapStudent.lower_bound(3);
	{
		//返回的是下界3的迭代器
		cout << iter->second << endl;
	}
	iter = mapStudent.upper_bound(2);
	{
		//返回的是上界3的迭代器
		cout << iter->second << endl;
	}
	iter = mapStudent.upper_bound(3);
	{
		//返回的是上界5的迭代器
		cout << iter->second << endl;
	}

	pair<map<int, string>::iterator, map<int, string>::iterator> mapPair;
	mapPair = mapStudent.equal_range(2);
	if (mapPair.first == mapPair.second)//如果这两个迭代器相等的话，则说明map中不出现这个关键字
	{
		cout << "Do not Find" << endl;
	}
	else
	{
		cout << "Find" << endl;
	}
	mapPair = mapStudent.equal_range(3);
	if (mapPair.first == mapPair.second)
	{
		cout << "Do not Find" << endl;
	}
	else
	{
		cout << "Find" << endl;
	}

	system("pause");
	return 0;
}

//cout << mapStudent.count("student_two") << endl;

//使用count函数的返回值只有 1 和 0 
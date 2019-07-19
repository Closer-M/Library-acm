#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<int, string> mapStudent;//Ŀǰ��Ӧ����ѧϰ�У�mapֻ�������������ݣ�first��second
	mapStudent.insert(make_pair(1, "student_one"));//insert�������룬make_pair(frset,second)=pair<type1,type2>(first,second);
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	map<int, string>::iterator  iter;//ǰ��Ӧ�����ڸ�ʽ ����� iter ���Զ����һ�����֣����ں����ʹ��
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)//���������ݰ�˳��ȫ�����
	{
		cout << iter->first << "  " << iter->second << endl;
	}
	system("pause");
	return 0;
}

int nSize = mapStudent.size();//�������еĴ�������ݵ�����

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
	map<int, string>::reverse_iterator  iter;//�ص�������仰���¾仰������ʹ�����ʱ���������
	for (iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)//��beginǰ��r����endǰҲ��
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
	int nSize = mapStudent.size();//���淽���µ������ʽ
	for (int nIndex = 1; nIndex <= nSize; nIndex++)
	{
		cout << mapStudent[nIndex] << endl;
	}
	system("pause");
	return 0;
}

//���map�е����ݿ�����clear()�������ж�map���Ƿ������ݿ�����empty()������������true��˵���ǿ�map

//find��ʹ��

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

//lower_bound�����÷������������������Ҫ���ҹؼ��ֵ��½�(��һ��������)
���ҵ�һ�����ڻ����key�ĵ�����
//upper_bound�����÷������������������Ҫ���ҹؼ��ֵ��Ͻ�(��һ��������)
���ҵ�һ������key�ĵ�����
//���磺map���Ѿ�������1��2��3��4�Ļ�

//���lower_bound(2)�Ļ������ص�2

//��upper - bound��2���Ļ������صľ���3

//equal_range��������һ��pair��pair�����һ��������Lower_bound���صĵ�����

//pair����ڶ�����������Upper_bound���صĵ�����

//�����������������ȵĻ�����˵��map�в���������ؼ���

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
		//���ص����½�3�ĵ�����
		cout << iter->second << endl;
	}
	iter = mapStudent.lower_bound(3);
	{
		//���ص����½�3�ĵ�����
		cout << iter->second << endl;
	}
	iter = mapStudent.upper_bound(2);
	{
		//���ص����Ͻ�3�ĵ�����
		cout << iter->second << endl;
	}
	iter = mapStudent.upper_bound(3);
	{
		//���ص����Ͻ�5�ĵ�����
		cout << iter->second << endl;
	}

	pair<map<int, string>::iterator, map<int, string>::iterator> mapPair;
	mapPair = mapStudent.equal_range(2);
	if (mapPair.first == mapPair.second)//�����������������ȵĻ�����˵��map�в���������ؼ���
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

//ʹ��count�����ķ���ֵֻ�� 1 �� 0 
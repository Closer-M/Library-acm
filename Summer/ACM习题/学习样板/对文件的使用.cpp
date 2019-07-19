//文本的写入
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//这是所使用的的头文件
using namespace std;
int main()
{
	ofstream output;//创建一个 ofstream 的对象“output”
	output.open("scores.txt");
	//打开名为 scores 的 txt 的文件，如果没有这个名字的文件的话就会创建一个新的文件
	/*
	在这里
	ofstream output("scores.txt");
	等同于
	ofstream output;
	output.open("scores.txt");
	*/
	output << "John" << " " << "T" << " " << "Smith" << " " << 90 << endl;
	// output 后用 << 这里表示的是将内容对文件进行写入
	output << "Eric" << " " << "T" << " " << "Jones" << " " << 85 << endl;
	output.close();
	// close 是将输入流关闭
	cout << "Done" << endl;
	system("pause");
	return 0;
}

//对文件数据的读取
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//这是所使用的的头文件
using namespace std;
int main()
{
	ifstream input("scores.txt");
	string firstName;
	char mi;
	string lastName;
	int score;
	input >> firstName >> mi >> lastName >> score;
	//每一次读取都要和文件中的数据的位置相对应
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;
	input >> firstName >> mi >> lastName >> score;
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;
	input.close();
	cout << "Sone" << endl;
	system("pause");
	return 0;
}

//在读取数据的时候如果这个需要读取的文件是不存在的那么读取就会失败
//所以我们就可以用 fail() 函数对文件进行检查是否存在
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//这是所使用的的头文件
using namespace std;
int main()
{
	ifstream input;
	input.open("scores.txt");
	if (input.fail())
	{
		cout << "File does not esist" << endl;
		cout << "Exit program" << endl;
	}
	system("pause");
	return 0;
}


//读取大量数据
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//这是所使用的的头文件
using namespace std;
int main()
{
	ifstream input;
	input.open("scores.txt");
	double sum = 0;
	double number;
	while (!input.eof())//在文件中有大量数据要全部读取的时候可以用 eof() 进行判断文件是否被读取完
	{
		input >> number;
		if (input.eof())//如果不加这句话在文件的最后多一个空格的时候程序无法自主判断文件是否已经被读取完，将导致最后一个数据被使用两次
		{
			break;
		}
		cout << number << " ";
		sum += number;
	}
	system("pause");
	return 0;
}
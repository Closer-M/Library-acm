//�ı���д��
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//������ʹ�õĵ�ͷ�ļ�
using namespace std;
int main()
{
	ofstream output;//����һ�� ofstream �Ķ���output��
	output.open("scores.txt");
	//����Ϊ scores �� txt ���ļ������û��������ֵ��ļ��Ļ��ͻᴴ��һ���µ��ļ�
	/*
	������
	ofstream output("scores.txt");
	��ͬ��
	ofstream output;
	output.open("scores.txt");
	*/
	output << "John" << " " << "T" << " " << "Smith" << " " << 90 << endl;
	// output ���� << �����ʾ���ǽ����ݶ��ļ�����д��
	output << "Eric" << " " << "T" << " " << "Jones" << " " << 85 << endl;
	output.close();
	// close �ǽ��������ر�
	cout << "Done" << endl;
	system("pause");
	return 0;
}

//���ļ����ݵĶ�ȡ
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//������ʹ�õĵ�ͷ�ļ�
using namespace std;
int main()
{
	ifstream input("scores.txt");
	string firstName;
	char mi;
	string lastName;
	int score;
	input >> firstName >> mi >> lastName >> score;
	//ÿһ�ζ�ȡ��Ҫ���ļ��е����ݵ�λ�����Ӧ
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;
	input >> firstName >> mi >> lastName >> score;
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;
	input.close();
	cout << "Sone" << endl;
	system("pause");
	return 0;
}

//�ڶ�ȡ���ݵ�ʱ����������Ҫ��ȡ���ļ��ǲ����ڵ���ô��ȡ�ͻ�ʧ��
//�������ǾͿ����� fail() �������ļ����м���Ƿ����
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//������ʹ�õĵ�ͷ�ļ�
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


//��ȡ��������
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<fstream>//������ʹ�õĵ�ͷ�ļ�
using namespace std;
int main()
{
	ifstream input;
	input.open("scores.txt");
	double sum = 0;
	double number;
	while (!input.eof())//���ļ����д�������Ҫȫ����ȡ��ʱ������� eof() �����ж��ļ��Ƿ񱻶�ȡ��
	{
		input >> number;
		if (input.eof())//���������仰���ļ�������һ���ո��ʱ������޷������ж��ļ��Ƿ��Ѿ�����ȡ�꣬���������һ�����ݱ�ʹ������
		{
			break;
		}
		cout << number << " ";
		sum += number;
	}
	system("pause");
	return 0;
}
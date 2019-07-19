#include<iostream>
#include<string>
#include<fstream>
#include "windows.h"
using namespace std;

class Image
{
private://第一步习惯性的还是先定义数据
	long m_width;
	long m_height;
	unsigned char * m_pData;//整行的数据前是否家 unsigned 的意义在于这个数据是否有符号，无符号的数据类型可保存的数据是有符号的两倍
public://然后第二步开始编写函数部分
	//首先是对数据的无参定义
	Image()
	{
		m_width = 0;
		m_height = 0;
		m_pData = NULL;//NULL是空的意思，里面存放的应该是‘\0’
	}
	//参考了傅的代码，这里是最重要且基础的部分
	Image(string str)
	{
		ifstream input;
		input.open(str.c_str(), ios::in | ios::binary);//括号的内的内容是尝试使用二进制方式打开文件，但是我在删掉里面的内容是运行并无多大区别，无法定义其在这个程序中的作用

		if (input.fail())//如果这个文件不错在 抛出错误值 1
			throw 1;

		BITMAPFILEHEADER bitmapfileheader;
		input.read(reinterpret_cast<char*> (&bitmapfileheader), sizeof(bitmapfileheader));		// 阅读位图的头部
		if (bitmapfileheader.bfType != 0x4d42)// 0x4d42表示这个文件是否是 bmp类型               //如果它不是* .bmp文件则抛出错误值 2
			throw 2;

		BITMAPINFOHEADER bitmapinfoheader;
		input.read(reinterpret_cast<char*> (&bitmapinfoheader), sizeof(bitmapinfoheader));		//阅读位图信息
		m_width = bitmapinfoheader.biWidth;//得到位图的宽
		m_height = bitmapinfoheader.biHeight;//得到位图的高
		if (bitmapinfoheader.biBitCount != 8)													//如果它不是灰色位图则抛出错误 3
			throw 3;

		RGBQUAD *rgbquad;
		rgbquad = new RGBQUAD[256];																//代表灰度等级的0~255
		input.read(reinterpret_cast<char*> (rgbquad), sizeof(RGBQUAD) * 256); 					//读取位图的颜色
		m_pData = new unsigned char[m_width * m_height];										//链接到位图
		input.read(reinterpret_cast<char*> (m_pData), m_width*m_height);						//读取位图数据
	}
	//返回位图的宽
	long getWidth()
	{
		return m_width;
	}
	//返回位图的高
	long getHeight()
	{
		return m_height;
	}
	//返回位图的平均值
	float Average()
	{
		long sumLevel = 0;
		long pixel = m_width * m_height;//宽*高
		for (int i = 0; i <= pixel; i++)
		{
			sumLevel += m_pData[i];
		}
		float average = 1.0 * sumLevel / pixel;
		return average;
	}
	//返回位图的方差
	float Variance()
	{
		float sumDValue = 0;
		float average = Average();//得到均值
		long pixel = m_width * m_height;//宽*高
		for (int i = 0; i < pixel; i++)
		{
			sumDValue += pow((m_pData[i] - average), 2);
		}
		return 0;
	}
	//重载符号 =
	Image& operator=(const Image &img)
	{
		long pixel = img.m_width * img.m_height;//等到后者的大小
		this->m_width = img.m_width;//得到后者的宽
		this->m_height = img.m_height;//得到后者的高
		this->m_pData = new unsigned char[pixel];//动态开创图的大小数值
		for (int i = 0; i < pixel; i++)
		{
			this->m_pData[i] = img.m_pData[i];
		}
		return *this;
	}
	//设定一个友元函数，在一个类中私有的变量是无法在外部进行访问的，只有用友元函数才能在外面进行访问
	friend Image& operator+(Image &img1, Image &img2);
	//据说小波浪是用来释放内存的，具体情况我也不清楚
	~Image()
	{
		delete[]m_pData;
		printf("%s is released\n", "Image");
	}
};
//重载符号 +
Image& operator+(Image &img1, Image &img2)
{
	if (img1.m_width != img2.m_width || img1.m_height != img2.m_height)//如果相加的两张图片大小不同则返回错误 4
	{
		throw 4;
	}
	else
	{
		long pixel = img1.m_width * img2.m_height;//将图片中的每一个像素相加
		for (int i = 0; i < pixel; i++)
		{
			if (img1.m_pData[i] + img2.m_pData[i] <= 255)
			{
				img1.m_pData[i] = img1.m_pData[i] + img2.m_pData[i];
			}
			else
			{
				img1.m_pData[i] = (img1.m_pData[i] + img2.m_pData[i]) % 256;
			}
		}
	}
	return img1;
}
//主函数暂时没改动
int main()
{
	try
	{
		Image image1("1.bmp");
		Image image2("2.bmp");

		printf("The width of the 1st bitmap is %ld.\n", image1.getWidth());
		printf("The height of the 1st bitmap is %ld.\n", image1.getHeight());
		printf("The average gray of the 1st bitmap is %f.\n", image1.Average());
		printf("The variance gray of the 1st bitmap is %f.\n", image1.Variance());
		printf("\n");

		printf("The width of the 2nd bitmap is %ld.\n", image2.getWidth());
		printf("The height of the 2nd bitmap is %ld.\n", image2.getHeight());
		printf("The average gray of the 2nd bitmap is %f.\n", image2.Average());
		printf("The variance gray of the 2nd bitmap is %f.\n", image2.Variance());
		printf("\n");

		Image image3;
		image3 = image1 + image2;

		printf("The width of the 3rd bitmap is %ld.\n", image3.getWidth());
		printf("The height of the 3rd bitmap is %ld.\n", image3.getHeight());
		printf("The average gray of the 3rd bitmap is %f.\n", image3.Average());
		printf("The variance gray of the 3rd bitmap is %f.\n", image3.Variance());
		printf("\n");
	}

	catch (int errNum)
	{
		switch (errNum)
		{
		case 1:
			printf("Image cannot be opened.\n");
			break;
		case 2:
			printf("Image is not a bitmap.\n");
			break;
		case 3:
			printf("Image is not a gray scale.\n");
			break;
		case 4:
			printf("The width or height of Img1 is not equal to Img2.\n");
			break;
		default:
			printf("Other unknown error.\n");
			break;
		}
	}
	system("pause");
	return 0;
}






//马宇昊修正版
#include<iostream>
#include<string>
#include<fstream>
#include "windows.h"
using namespace std;
class Image
{
private:
	long m_width;
	long m_height;
	unsigned char * m_pdata;
public:
	Image();
	Image(string n);
	long getwidth()
	{
		return m_width;
	}
	long getheight()
	{
		return m_height;
	}
	Image&operator=(Image n)
	{
		long pixel = n.m_width * n.m_height;//等到后者的大小
		this->m_width = n.m_width;//得到后者的宽
		this->m_height = n.m_height;//得到后者的高
		this->m_pdata = new unsigned char[pixel];//动态开创图的大小数值
		for (int i = 0; i < pixel; i++)
		{
			this->m_pdata[i] = n.m_pdata[i];
		}
		return *this;
	}
	friend Image&operator+(Image&img1, Image&img2);
};
Image::Image()
{
	m_width = 0;
	m_height = 0;
	m_pdata = NULL;
}
Image::Image(string n)
{
	ifstream input;
	input.open(n);
	BITMAPFILEHEADER fileheader;//bitmapfileheader
	input.read(reinterpret_cast<char*> (&fileheader), sizeof(fileheader));// 阅读位图的头部
	BITMAPINFOHEADER infoheader;//bitmapinfoheader
	input.read(reinterpret_cast<char*> (&infoheader), sizeof(infoheader));//阅读位图信息
	if (input.fail())
	{
		cout << "无法打开" << n << endl;
		throw 1;
	}
	else if (fileheader.bfType != 0x4d42)// 0x4d42表示这个文件是否是 bmp类型,如果它不是* .bmp文件则抛出错误值 2
	{
		cout << "文件" << n << "不是bmp格式" << endl;
		throw 2;
	}
	else if (infoheader.biBitCount != 8)//如果它不是灰色位图则抛出错误 3
	{
		cout << "文件" << n << "不是灰色位图" << endl;
		throw 3;
	}

	m_width = infoheader.biWidth;//得到位图的宽
	m_height = infoheader.biHeight;//得到位图的高

	RGBQUAD *rgbquad;
	rgbquad = new RGBQUAD[256];																//代表灰度等级的0~255
	input.read(reinterpret_cast<char*> (rgbquad), sizeof(RGBQUAD) * 256); 					//读取位图的颜色
	m_pdata = new unsigned char[m_width * m_height];										//链接到位图
	input.read(reinterpret_cast<char*> (m_pdata), m_width*m_height);
}
Image& operator+(Image &img1, Image &img2)
{
	if (img1.m_width != img2.m_width || img1.m_height != img2.m_height)//如果相加的两张图片大小不同则返回错误 4
	{
		cout << "相加的两个文件大小不同" << endl;
		throw 4;
	}
	else
	{
		long pixel = img1.m_width * img2.m_height;//将图片中的每一个像素相加
		for (int i = 0; i < pixel; i++)
		{
			if (img1.m_pdata[i] + img2.m_pdata[i] <= 255)
			{
				img1.m_pdata[i] = img1.m_pdata[i] + img2.m_pdata[i];
			}
			else
			{
				img1.m_pdata[i] = (img1.m_pdata[i] + img2.m_pdata[i]) % 256;
			}
		}
	}
	return img1;
}
int main()
{
	try
	{
		string map1, map2;
		cout << "在输入文件名时记得加上后缀，否则读取会失败" << endl;
		cout << "选择图片一：";
		cin >> map1;
		cout << "选择图片二：";
		cin >> map2;
		Image a(map1);
		Image b(map2);
		Image c = a + b;
	}
	catch (int x)
	{
		switch (x)
		{
		case 4:
			cout << "图片大小不同，相加有错" << endl;
		default:
			cout << "图片本身问题需重选或者重建图片" << endl;
		}

	}
	system("pause");
	return 0;
}
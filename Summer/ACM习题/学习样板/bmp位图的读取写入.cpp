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
#include<Windows.h>//读取位图时使用的头文件
using namespace std;
unsigned char *pBmpBuf;//读入图像数据的指针

int bmpWidth;//位图的宽

int bmpHeight;//位图的高

RGBQUAD *pColorTable;//颜色表指针

int biBitCount;//图像类型，每像素位数

//读图像的位图数据、宽、高、颜色表及每像素位数等数据进内存，存放在相应的全局变量中   
bool readBmp(char *bmpName)
{
	FILE *fp = fopen(bmpName, "rb");//二进制读方式打开指定的图像文件   

	if (fp == 0)
		return 0;

	//跳过位图文件头结构BITMAPFILEHEADER   

	fseek(fp, sizeof(BITMAPFILEHEADER), 0);

	//定义位图信息头结构变量，读取位图信息头进内存，存放在变量head中   

	BITMAPINFOHEADER head;

	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //获取图像宽、高、每像素所占位数等信息   

	bmpWidth = head.biWidth;

	bmpHeight = head.biHeight;

	biBitCount = head.biBitCount;//定义变量，计算图像每行像素所占的字节数（必须是4的倍数）   

	int lineByte = (bmpWidth * biBitCount / 8 + 3) / 4 * 4;//灰度图像有颜色表，且颜色表表项为256   

	if (biBitCount == 8)
	{

		//申请颜色表所需要的空间，读颜色表进内存   

		pColorTable = new RGBQUAD[256];

		fread(pColorTable, sizeof(RGBQUAD), 256, fp);

	}

	//申请位图数据所需要的空间，读位图数据进内存   

	pBmpBuf = new unsigned char[lineByte * bmpHeight];

	fread(pBmpBuf, 1, lineByte * bmpHeight, fp);

	fclose(fp);//关闭文件   

	return 1;//读取文件成功   
}
//给定一个图像位图数据、宽、高、颜色表指针及每像素所占的位数等信息,将其写到指定文件中   
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable)
{

	//如果位图数据指针为0，则没有数据传入，函数返回   

	if (!imgBuf)
		return 0;

	//颜色表大小，以字节为单位，灰度图像颜色表为1024字节，彩色图像颜色表大小为0   

	int colorTablesize = 0;

	if (biBitCount == 8)
		colorTablesize = 1024;

	//待存储图像数据每行字节数为4的倍数   

	int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;

	//以二进制写的方式打开文件   

	FILE *fp = fopen(bmpName, "wb");

	if (fp == 0)
		return 0;

	//申请位图文件头结构变量，填写文件头信息   

	BITMAPFILEHEADER fileHead;

	fileHead.bfType = 0x4D42;//bmp类型   

	//bfSize是图像文件4个组成部分之和   

	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte * height;

	fileHead.bfReserved1 = 0;

	fileHead.bfReserved2 = 0;

	//bfOffBits是图像文件前3个部分所需空间之和   

	fileHead.bfOffBits = 54 + colorTablesize;

	//写文件头进文件   

	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);

	//申请位图信息头结构变量，填写信息头信息   

	BITMAPINFOHEADER head;

	head.biBitCount = biBitCount;

	head.biClrImportant = 0;

	head.biClrUsed = 0;

	head.biCompression = 0;

	head.biHeight = height;

	head.biPlanes = 1;

	head.biSize = 40;

	head.biSizeImage = lineByte * height;

	head.biWidth = width;

	head.biXPelsPerMeter = 0;

	head.biYPelsPerMeter = 0;

	//写位图信息头进内存   

	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);

	//如果灰度图像，有颜色表，写入文件    

	if (biBitCount == 8)
		fwrite(pColorTable, sizeof(RGBQUAD), 256, fp);

	//写位图数据进文件   

	fwrite(imgBuf, height*lineByte, 1, fp);

	//关闭文件   

	fclose(fp);

	return 1;

}

//----------------------------------------------------------------------------------------   
//以下为像素的读取函数   
void doIt()
{

	//读入指定BMP文件进内存   

	char readPath[] = "nv.BMP";

	readBmp(readPath);

	//输出图像的信息   

	cout << "width=" << bmpWidth << " height=" << bmpHeight << " biBitCount=" << biBitCount << endl;

	//循环变量，图像的坐标   

	//每行字节数   

	int lineByte = (bmpWidth*biBitCount / 8 + 3) / 4 * 4;

	//循环变量，针对彩色图像，遍历每像素的三个分量   

	int m = 0, n = 0, count_xiang_su = 0;

	//将图像左下角1/4部分置成黑色   

	ofstream outfile("图像像素.txt", ios::in | ios::trunc);

	if (biBitCount == 8) //对于灰度图像   
	{
		//------------------------------------------------------------------------------------   
		//以下完成图像的分割成8*8小单元，并把像素值存储到指定文本中。由于BMP图像的像素数据是从   
		//左下角：由左往右，由上往下逐行扫描的   
		int L1 = 0;
		int hang = 63;
		int lie = 0;
		//int L2=0;   
		//int fen_ge=8;   
		for (int fen_ge_hang = 0; fen_ge_hang < 8; fen_ge_hang++)//64*64矩阵行循环   
		{
			for (int fen_ge_lie = 0; fen_ge_lie < 8; fen_ge_lie++)//64*64列矩阵循环   
			{
				//--------------------------------------------   
				for (L1 = hang; L1 > hang - 8; L1--)//8*8矩阵行   
				{
					for (int L2 = lie; L2 < lie + 8; L2++)//8*8矩阵列   
					{
						m = *(pBmpBuf + L1 * lineByte + L2);
						outfile << m << " ";
						count_xiang_su++;
						if (count_xiang_su % 8 == 0)//每8*8矩阵读入文本文件   
						{
							outfile << endl;
						}
					}
				}
				//---------------------------------------------   
				hang = 63 - fen_ge_hang * 8;//64*64矩阵行变换   
				lie += 8;//64*64矩阵列变换   
					//该一行（64）由8个8*8矩阵的行组成   
			}
			hang -= 8;//64*64矩阵的列变换   
			lie = 0;//64*64juzhen   
		}
	}

	//double xiang_su[2048];   
	//ofstream outfile("xiang_su_zhi.txt",ios::in|ios::trunc);   
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	else if (biBitCount == 24)
	{//彩色图像   
		for (int i = 0; i < bmpHeight; i++)
		{
			for (int j = 0; j < bmpWidth; j++)
			{
				for (int k = 0; k < 3; k++)//每像素RGB三个分量分别置0才变成黑色   
				{
					//*(pBmpBuf+i*lineByte+j*3+k)-=40;   
					m = *(pBmpBuf + i * lineByte + j * 3 + k);
					outfile << m << " ";
					count_xiang_su++;
					if (count_xiang_su % 8 == 0)
					{
						outfile << endl;
					}
					//n++;   
				}
				n++;
			}


		}
		cout << "总的像素个素为:" << n << endl;
		cout << "----------------------------------------------------" << endl;
	}

	//将图像数据存盘   

	char writePath[] = "nvcpy.BMP";//图片处理后再存储   

	saveBmp(writePath, pBmpBuf, bmpWidth, bmpHeight, biBitCount, pColorTable);

	//清除缓冲区，pBmpBuf和pColorTable是全局变量，在文件读入时申请的空间   

	delete[]pBmpBuf;

	if (biBitCount == 8)
		delete[]pColorTable;
}

void main()
{
	doIt();
}












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
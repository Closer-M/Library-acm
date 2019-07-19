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
#include<Windows.h>//��ȡλͼʱʹ�õ�ͷ�ļ�
using namespace std;
unsigned char *pBmpBuf;//����ͼ�����ݵ�ָ��

int bmpWidth;//λͼ�Ŀ�

int bmpHeight;//λͼ�ĸ�

RGBQUAD *pColorTable;//��ɫ��ָ��

int biBitCount;//ͼ�����ͣ�ÿ����λ��

//��ͼ���λͼ���ݡ����ߡ���ɫ��ÿ����λ�������ݽ��ڴ棬�������Ӧ��ȫ�ֱ�����   
bool readBmp(char *bmpName)
{
	FILE *fp = fopen(bmpName, "rb");//�����ƶ���ʽ��ָ����ͼ���ļ�   

	if (fp == 0)
		return 0;

	//����λͼ�ļ�ͷ�ṹBITMAPFILEHEADER   

	fseek(fp, sizeof(BITMAPFILEHEADER), 0);

	//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��   

	BITMAPINFOHEADER head;

	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //��ȡͼ����ߡ�ÿ������ռλ������Ϣ   

	bmpWidth = head.biWidth;

	bmpHeight = head.biHeight;

	biBitCount = head.biBitCount;//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����   

	int lineByte = (bmpWidth * biBitCount / 8 + 3) / 4 * 4;//�Ҷ�ͼ������ɫ������ɫ�����Ϊ256   

	if (biBitCount == 8)
	{

		//������ɫ������Ҫ�Ŀռ䣬����ɫ����ڴ�   

		pColorTable = new RGBQUAD[256];

		fread(pColorTable, sizeof(RGBQUAD), 256, fp);

	}

	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�   

	pBmpBuf = new unsigned char[lineByte * bmpHeight];

	fread(pBmpBuf, 1, lineByte * bmpHeight, fp);

	fclose(fp);//�ر��ļ�   

	return 1;//��ȡ�ļ��ɹ�   
}
//����һ��ͼ��λͼ���ݡ����ߡ���ɫ��ָ�뼰ÿ������ռ��λ������Ϣ,����д��ָ���ļ���   
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable)
{

	//���λͼ����ָ��Ϊ0����û�����ݴ��룬��������   

	if (!imgBuf)
		return 0;

	//��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024�ֽڣ���ɫͼ����ɫ���СΪ0   

	int colorTablesize = 0;

	if (biBitCount == 8)
		colorTablesize = 1024;

	//���洢ͼ������ÿ���ֽ���Ϊ4�ı���   

	int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;

	//�Զ�����д�ķ�ʽ���ļ�   

	FILE *fp = fopen(bmpName, "wb");

	if (fp == 0)
		return 0;

	//����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ   

	BITMAPFILEHEADER fileHead;

	fileHead.bfType = 0x4D42;//bmp����   

	//bfSize��ͼ���ļ�4����ɲ���֮��   

	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte * height;

	fileHead.bfReserved1 = 0;

	fileHead.bfReserved2 = 0;

	//bfOffBits��ͼ���ļ�ǰ3����������ռ�֮��   

	fileHead.bfOffBits = 54 + colorTablesize;

	//д�ļ�ͷ���ļ�   

	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);

	//����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ   

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

	//дλͼ��Ϣͷ���ڴ�   

	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);

	//����Ҷ�ͼ������ɫ��д���ļ�    

	if (biBitCount == 8)
		fwrite(pColorTable, sizeof(RGBQUAD), 256, fp);

	//дλͼ���ݽ��ļ�   

	fwrite(imgBuf, height*lineByte, 1, fp);

	//�ر��ļ�   

	fclose(fp);

	return 1;

}

//----------------------------------------------------------------------------------------   
//����Ϊ���صĶ�ȡ����   
void doIt()
{

	//����ָ��BMP�ļ����ڴ�   

	char readPath[] = "nv.BMP";

	readBmp(readPath);

	//���ͼ�����Ϣ   

	cout << "width=" << bmpWidth << " height=" << bmpHeight << " biBitCount=" << biBitCount << endl;

	//ѭ��������ͼ�������   

	//ÿ���ֽ���   

	int lineByte = (bmpWidth*biBitCount / 8 + 3) / 4 * 4;

	//ѭ����������Բ�ɫͼ�񣬱���ÿ���ص���������   

	int m = 0, n = 0, count_xiang_su = 0;

	//��ͼ�����½�1/4�����óɺ�ɫ   

	ofstream outfile("ͼ������.txt", ios::in | ios::trunc);

	if (biBitCount == 8) //���ڻҶ�ͼ��   
	{
		//------------------------------------------------------------------------------------   
		//�������ͼ��ķָ��8*8С��Ԫ����������ֵ�洢��ָ���ı��С�����BMPͼ������������Ǵ�   
		//���½ǣ��������ң�������������ɨ���   
		int L1 = 0;
		int hang = 63;
		int lie = 0;
		//int L2=0;   
		//int fen_ge=8;   
		for (int fen_ge_hang = 0; fen_ge_hang < 8; fen_ge_hang++)//64*64������ѭ��   
		{
			for (int fen_ge_lie = 0; fen_ge_lie < 8; fen_ge_lie++)//64*64�о���ѭ��   
			{
				//--------------------------------------------   
				for (L1 = hang; L1 > hang - 8; L1--)//8*8������   
				{
					for (int L2 = lie; L2 < lie + 8; L2++)//8*8������   
					{
						m = *(pBmpBuf + L1 * lineByte + L2);
						outfile << m << " ";
						count_xiang_su++;
						if (count_xiang_su % 8 == 0)//ÿ8*8��������ı��ļ�   
						{
							outfile << endl;
						}
					}
				}
				//---------------------------------------------   
				hang = 63 - fen_ge_hang * 8;//64*64�����б任   
				lie += 8;//64*64�����б任   
					//��һ�У�64����8��8*8����������   
			}
			hang -= 8;//64*64������б任   
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
	{//��ɫͼ��   
		for (int i = 0; i < bmpHeight; i++)
		{
			for (int j = 0; j < bmpWidth; j++)
			{
				for (int k = 0; k < 3; k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
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
		cout << "�ܵ����ظ���Ϊ:" << n << endl;
		cout << "----------------------------------------------------" << endl;
	}

	//��ͼ�����ݴ���   

	char writePath[] = "nvcpy.BMP";//ͼƬ������ٴ洢   

	saveBmp(writePath, pBmpBuf, bmpWidth, bmpHeight, biBitCount, pColorTable);

	//�����������pBmpBuf��pColorTable��ȫ�ֱ��������ļ�����ʱ����Ŀռ�   

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
private://��һ��ϰ���ԵĻ����ȶ�������
	long m_width;
	long m_height;
	unsigned char * m_pData;//���е�����ǰ�Ƿ�� unsigned ������������������Ƿ��з��ţ��޷��ŵ��������Ϳɱ�����������з��ŵ�����
public://Ȼ��ڶ�����ʼ��д��������
	//�����Ƕ����ݵ��޲ζ���
	Image()
	{
		m_width = 0;
		m_height = 0;
		m_pData = NULL;//NULL�ǿյ���˼�������ŵ�Ӧ���ǡ�\0��
	}
	//�ο��˸��Ĵ��룬����������Ҫ�һ����Ĳ���
	Image(string str)
	{
		ifstream input;
		input.open(str.c_str(), ios::in | ios::binary);//���ŵ��ڵ������ǳ���ʹ�ö����Ʒ�ʽ���ļ�����������ɾ����������������в��޶�������޷�����������������е�����

		if (input.fail())//�������ļ������� �׳�����ֵ 1
			throw 1;

		BITMAPFILEHEADER bitmapfileheader;
		input.read(reinterpret_cast<char*> (&bitmapfileheader), sizeof(bitmapfileheader));		// �Ķ�λͼ��ͷ��
		if (bitmapfileheader.bfType != 0x4d42)// 0x4d42��ʾ����ļ��Ƿ��� bmp����               //���������* .bmp�ļ����׳�����ֵ 2
			throw 2;

		BITMAPINFOHEADER bitmapinfoheader;
		input.read(reinterpret_cast<char*> (&bitmapinfoheader), sizeof(bitmapinfoheader));		//�Ķ�λͼ��Ϣ
		m_width = bitmapinfoheader.biWidth;//�õ�λͼ�Ŀ�
		m_height = bitmapinfoheader.biHeight;//�õ�λͼ�ĸ�
		if (bitmapinfoheader.biBitCount != 8)													//��������ǻ�ɫλͼ���׳����� 3
			throw 3;

		RGBQUAD *rgbquad;
		rgbquad = new RGBQUAD[256];																//����Ҷȵȼ���0~255
		input.read(reinterpret_cast<char*> (rgbquad), sizeof(RGBQUAD) * 256); 					//��ȡλͼ����ɫ
		m_pData = new unsigned char[m_width * m_height];										//���ӵ�λͼ
		input.read(reinterpret_cast<char*> (m_pData), m_width*m_height);						//��ȡλͼ����
	}
	//����λͼ�Ŀ�
	long getWidth()
	{
		return m_width;
	}
	//����λͼ�ĸ�
	long getHeight()
	{
		return m_height;
	}
	//����λͼ��ƽ��ֵ
	float Average()
	{
		long sumLevel = 0;
		long pixel = m_width * m_height;//��*��
		for (int i = 0; i <= pixel; i++)
		{
			sumLevel += m_pData[i];
		}
		float average = 1.0 * sumLevel / pixel;
		return average;
	}
	//����λͼ�ķ���
	float Variance()
	{
		float sumDValue = 0;
		float average = Average();//�õ���ֵ
		long pixel = m_width * m_height;//��*��
		for (int i = 0; i < pixel; i++)
		{
			sumDValue += pow((m_pData[i] - average), 2);
		}
		return 0;
	}
	//���ط��� =
	Image& operator=(const Image &img)
	{
		long pixel = img.m_width * img.m_height;//�ȵ����ߵĴ�С
		this->m_width = img.m_width;//�õ����ߵĿ�
		this->m_height = img.m_height;//�õ����ߵĸ�
		this->m_pData = new unsigned char[pixel];//��̬����ͼ�Ĵ�С��ֵ
		for (int i = 0; i < pixel; i++)
		{
			this->m_pData[i] = img.m_pData[i];
		}
		return *this;
	}
	//�趨һ����Ԫ��������һ������˽�еı������޷����ⲿ���з��ʵģ�ֻ������Ԫ����������������з���
	friend Image& operator+(Image &img1, Image &img2);
	//��˵С�����������ͷ��ڴ�ģ����������Ҳ�����
	~Image()
	{
		delete[]m_pData;
		printf("%s is released\n", "Image");
	}
};
//���ط��� +
Image& operator+(Image &img1, Image &img2)
{
	if (img1.m_width != img2.m_width || img1.m_height != img2.m_height)//�����ӵ�����ͼƬ��С��ͬ�򷵻ش��� 4
	{
		throw 4;
	}
	else
	{
		long pixel = img1.m_width * img2.m_height;//��ͼƬ�е�ÿһ���������
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
//��������ʱû�Ķ�
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
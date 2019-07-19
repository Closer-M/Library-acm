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






//�����������
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
		long pixel = n.m_width * n.m_height;//�ȵ����ߵĴ�С
		this->m_width = n.m_width;//�õ����ߵĿ�
		this->m_height = n.m_height;//�õ����ߵĸ�
		this->m_pdata = new unsigned char[pixel];//��̬����ͼ�Ĵ�С��ֵ
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
	input.read(reinterpret_cast<char*> (&fileheader), sizeof(fileheader));// �Ķ�λͼ��ͷ��
	BITMAPINFOHEADER infoheader;//bitmapinfoheader
	input.read(reinterpret_cast<char*> (&infoheader), sizeof(infoheader));//�Ķ�λͼ��Ϣ
	if (input.fail())
	{
		cout << "�޷���" << n << endl;
		throw 1;
	}
	else if (fileheader.bfType != 0x4d42)// 0x4d42��ʾ����ļ��Ƿ��� bmp����,���������* .bmp�ļ����׳�����ֵ 2
	{
		cout << "�ļ�" << n << "����bmp��ʽ" << endl;
		throw 2;
	}
	else if (infoheader.biBitCount != 8)//��������ǻ�ɫλͼ���׳����� 3
	{
		cout << "�ļ�" << n << "���ǻ�ɫλͼ" << endl;
		throw 3;
	}

	m_width = infoheader.biWidth;//�õ�λͼ�Ŀ�
	m_height = infoheader.biHeight;//�õ�λͼ�ĸ�

	RGBQUAD *rgbquad;
	rgbquad = new RGBQUAD[256];																//����Ҷȵȼ���0~255
	input.read(reinterpret_cast<char*> (rgbquad), sizeof(RGBQUAD) * 256); 					//��ȡλͼ����ɫ
	m_pdata = new unsigned char[m_width * m_height];										//���ӵ�λͼ
	input.read(reinterpret_cast<char*> (m_pdata), m_width*m_height);
}
Image& operator+(Image &img1, Image &img2)
{
	if (img1.m_width != img2.m_width || img1.m_height != img2.m_height)//�����ӵ�����ͼƬ��С��ͬ�򷵻ش��� 4
	{
		cout << "��ӵ������ļ���С��ͬ" << endl;
		throw 4;
	}
	else
	{
		long pixel = img1.m_width * img2.m_height;//��ͼƬ�е�ÿһ���������
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
		cout << "�������ļ���ʱ�ǵü��Ϻ�׺�������ȡ��ʧ��" << endl;
		cout << "ѡ��ͼƬһ��";
		cin >> map1;
		cout << "ѡ��ͼƬ����";
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
			cout << "ͼƬ��С��ͬ������д�" << endl;
		default:
			cout << "ͼƬ������������ѡ�����ؽ�ͼƬ" << endl;
		}

	}
	system("pause");
	return 0;
}
#include <iostream>
#include <windows.h>
#include "Time.h"
using namespace std;

class Time
{
public:
	short h, m, s;
	Time();
	Time(short nh, short nm, short ns);
	void noarg();
	void sumtime();
};
Time::Time()
{
	h = 1;
	m = 1;
	s = 1;
}
Time::Time(short nh, short nm, short ns)
{
	h = nh;
	m = nm;
	s = ns;
}


void Time::noarg() {
	SYSTEMTIME time;
	while (1)
	{
		GetSystemTime(&time);
		system("cls");
		cout << time.wYear << "Äê" << time.wMonth << "ÔÂ" << time.wDay << "ÈÕ" << endl;		cout << time.wHour << ":" << time.wMinute << ":" << time.wSecond << endl;
		Sleep(1000);
	}
}

void Time::sumtime() {
	long long time_last;
	time_last = time(NULL);
	cout << time_last << endl;
}
int main()
{
	Time time1;
	time1.noarg();
	time1.sumtime();
	return 0;
}
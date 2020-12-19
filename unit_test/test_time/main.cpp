
#include <time/time.h>
#include <iostream>

void CoutSystemDate()
{
	cvl::SystemDate systemDate = cvl::Timer::GetSystemDate();
	std::cout << "[ " << systemDate.year << "-" << systemDate.month << "-" << systemDate.day << ' ';
	std::cout << systemDate.hour << ":" << systemDate.minute << ":" << systemDate.second << " ]  ";
}

int main(int argc, char** argv)
{
	cvl::Timer time;

	time.Reset();
	_sleep(1000);
	double duringSecond = time.GetDuringTimeSecond();
	CoutSystemDate();
	std::cout << "duringSecond : " << duringSecond << " second\n";

	time.Reset();
	_sleep(1000);	
	CoutSystemDate();
	double duringMinute = time.GetDuringTimeMinute();
	std::cout << "duringMinute : " << duringMinute << " minute\n";
	
	time.Reset();
	_sleep(1000);
	CoutSystemDate();
	double duringHour = time.GetDuringTimeHour();
	std::cout << "duringHour : " << duringHour << " hour\n";

	return 0;
}
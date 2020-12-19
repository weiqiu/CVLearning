
#include "time.h"

cvl::Timer::Timer()
{
	m_startTime = clock();
}

cvl::Timer::~Timer() {};

cvl::SystemDate cvl::Timer::GetSystemDate()
{
	time_t timep;
	struct tm *p;

	time(&timep);
	p = localtime(&timep);

	SystemDate systemDate;
	systemDate.year = p->tm_year + 1970;
	systemDate.month = p->tm_mon;
	systemDate.day = p->tm_mday;

	systemDate.hour = p->tm_hour;
	systemDate.minute = p->tm_min;
	
	{
		double mTime = static_cast<double>(clock()) / CLOCKS_PER_SEC;
		double miSecond = mTime - static_cast<int>(clock());
		systemDate.second = p->tm_sec + miSecond;
	}
	return systemDate;
}

void cvl::Timer::Reset()
{
	m_startTime = clock();
}

double cvl::Timer::GetDuringTimeSecond()
{
	return static_cast<double>(clock() - m_startTime) / CLOCKS_PER_SEC;
}

double cvl::Timer::GetDuringTimeMinute()
{
	return static_cast<double>(clock() - m_startTime) / CLOCKS_PER_SEC / 60.0;
}

double cvl::Timer::GetDuringTimeHour()
{
	return static_cast<double>(clock() - m_startTime) / CLOCKS_PER_SEC / 60.0 / 60.0;
}

#ifdef WIN32
#include <Windows.h>
#endif

#include <iomanip>
#include <time/time.h>
#include "log.h"

cvl::Log::Log(const Type& type, std::ostream& ost)
	: m_type(type), m_ostream(ost)
{
#ifdef WIN32
	switch (type){
	case LOG_WARN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case LOG_ERROR:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	default:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	}
#endif

	PrintSystemDate();
}

cvl::Log::~Log()
{
#ifdef WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
#endif
}

std::string cvl::Log::End()
{
	return "\n";
}

void cvl::Log::PrintSystemDate()
{
	std::string type;
	switch (m_type) {
	case LOG_WARN:
		type = " WARN";
		break;
	case LOG_ERROR:
		type = "ERROR";
		break;
	default:
		type = " INFO";
		break;
	}

	cvl::SystemDate systemDate = cvl::Timer::GetSystemDate();

	m_ostream.setf(std::ios::fixed);
	m_ostream << "[" << type << ' ' << systemDate.year << "-" << systemDate.month << "-" << systemDate.day << ' ';
	m_ostream << systemDate.hour << ":" << systemDate.minute << ":";
	m_ostream << std::fixed << std::setprecision(6) << systemDate.second << "]  ";
}
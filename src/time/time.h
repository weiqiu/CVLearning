#ifndef CVL_SRC_TIME_H__
#define CVL_SRC_TIME_H__

#ifndef CVL_TIME_LIB_EXPORTS
#define CVL_TIME_LIB_EXPORT __declspec(dllimport)
#else
#define CVL_TIME_LIB_EXPORT __declspec(dllexport)
#endif

#include <ctime>
#include <vector>

namespace cvl
{
	class CVL_TIME_LIB_EXPORT SystemDate
	{
	public:
		int year;
		int month;
		int day;

		int hour;
		int minute;
		double second;
	};

	class CVL_TIME_LIB_EXPORT Timer
	{	
	public:
		Timer();
		~Timer();

		static SystemDate GetSystemDate();

		void Reset();

		double GetDuringTimeSecond();
		double GetDuringTimeMinute();
		double GetDuringTimeHour();

	private:
		clock_t m_startTime;
	};

} // namespace cvl

#ifndef CVL_TIME_LIB_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLTimeLibd.lib") 
#else
#pragma comment(lib, "CVLTimeLib.lib") 
#endif
#endif

#endif //!CVL_SRC_TIME_H__
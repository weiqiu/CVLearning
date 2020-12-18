#ifndef CVL_SRC_LOG_H__
#define CVL_SRC_LOG_H__

#ifndef CVL_LOG_LIB_EXPORTS
#define CVL_LOG_Lib_EXPORT __declspec(dllimport)
#else
#define CVL_LOG_Lib_EXPORT __declspec(dllexport)
#endif

#include <string>

namespace cvl
{
	class CVL_LOG_Lib_EXPORT Log
	{
	public:
		static void LogI(const char* pszFormat, ...);
		static void LogW(const char* pszFormat, ...);
		static void LogE(const char* pszFormat, ...);
	};

} // namespace cvl

#ifndef CVL_LOG_Lib_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLLogLibd.lib") 
#else
#pragma comment(lib, "CVLLogLib.lib") 
#endif
#endif

#endif //!CVL_SRC_LOG_H__
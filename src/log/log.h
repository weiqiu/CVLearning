#ifndef CVL_SRC_LOG_H__
#define CVL_SRC_LOG_H__

#ifndef CVL_LOG_LIB_EXPORTS
#define CVL_LOG_Lib_EXPORT __declspec(dllimport)
#else
#define CVL_LOG_Lib_EXPORT __declspec(dllexport)
#endif

#include <iostream>
#include <string>

namespace cvl
{
	class CVL_LOG_Lib_EXPORT Log
	{
	public:
		enum Type{LOG_INFO, LOG_WARN, LOG_ERROR};

		Log(const Type& type = LOG_INFO, std::ostream& ost = std::cout);
		~Log();

		static std::string End();

		template<typename T>
		Log& operator << (const T& outInfo);

	private:
		void PrintSystemDate();

	private:
		Type m_type;
		std::ostream& m_ostream;
	};

	template<typename T>
	Log& Log::operator << (const T& outInfo)
	{
		m_ostream << outInfo;
		return *this;
	}

} // namespace cvl

#ifndef CVL_LOG_LIB_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLLogLibd.lib") 
#else
#pragma comment(lib, "CVLLogLib.lib") 
#endif
#endif

#endif //!CVL_SRC_LOG_H__
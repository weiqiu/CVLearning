#ifndef CVL_SRC_IO_H__
#define CVL_SRC_IO_H__

#ifndef CVL_IO_Lib_EXPORTS
#define CVL_IO_Lib_EXPORT __declspec(dllimport)
#else
#define CVL_IO_Lib_EXPORT __declspec(dllexport)
#endif

#include <string>
#include <base/image.h>

namespace cvl
{
	class CVL_BASE_LIB_EXPORT ImageIO
	{
	public:

		static bool Load(const std::string& path, Image& img);

		static bool Save(const std::string& path, const Image& img);
	};

} // namespace cvl

#ifndef CVL_IO_Lib_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLIOLibd.lib") 
#else
#pragma comment(lib, "CVLIOLib.lib") 
#endif
#endif

#endif //!CVL_SRC_IO_H__
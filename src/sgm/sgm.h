#ifndef SRC_SGM_CVL_SGM_H__
#define SRC_SGM_CVL_SGM_H__

#ifndef CVL_SGM_LIB_EXPORTS
#define CVL_SGM_LIB_EXPORT __declspec(dllimport)
#else
#define CVL_SGM_LIB_EXPORT __declspec(dllexport)
#endif

#include <base/image.h>
#include <base/disparity_map.h>

namespace cvl
{
	namespace alg
	{
		class CVL_SGM_LIB_EXPORT Sgm
		{
		public:

			static DisparityMap Run(const Image& leftImg, const Image& rightImg);
		};
	}
}

#ifndef CVL_SGM_LIB_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLSGMLibd.lib") 
#else
#pragma comment(lib, "CVLSGMLib.lib") 
#endif
#endif

#endif //!SRC_SGM_CVL_SGM_H__
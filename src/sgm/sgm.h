#ifndef SRC_SGM_CVL_SGM_H__
#define SRC_SGM_CVL_SGM_H__

#ifndef CVL_SGM_EXPORTS
#define CVL_SGM_EXPORT __declspec(dllimport)
#else
#define CVL_SGM_EXPORT __declspec(dllexport)
#endif

#include <image/image.h>

namespace cvl
{
	class CVL_SGM_EXPORT Sgm
	{
	public:

		static Image<float> Run(const Image<unsigned char>& leftImg, const Image<unsigned char>& rightImg);
	};
}

#ifndef CVL_SGM_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "SGMLibd.lib") 
#else
#pragma comment(lib, "SGMLib.lib") 
#endif
#endif

#endif //!SRC_SGM_CVL_SGM_H__
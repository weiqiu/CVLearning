#ifndef SRC_SGM_CVL_SGM_IMPL_H__
#define SRC_SGM_CVL_SGM_IMPL_H__

#include <image/image.h>

namespace cvl
{
	class SgmImpl
	{
	public:

		Image<float> Run(const Image<unsigned char>& leftImg, const Image<unsigned char>& rightImg);

	private:
		Image<int> m_dispMap;
		Image<float> m_depthMap;
	};
}

#endif //!SRC_SGM_CVL_SGM_IMPL_H__
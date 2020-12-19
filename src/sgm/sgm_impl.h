#ifndef SRC_SGM_CVL_SGM_IMPL_H__
#define SRC_SGM_CVL_SGM_IMPL_H__

#include <base/image.h>
#include <base/depth_map.h>

namespace cvl
{
	namespace iner
	{
		class SgmImpl
		{
		public:

			DepthMap Run(const Image& leftImg, const Image& rightImg);

		private:
			BaseMap<int> m_dispMap;
			DepthMap m_depthMap;
		};
	}
}

#endif //!SRC_SGM_CVL_SGM_IMPL_H__
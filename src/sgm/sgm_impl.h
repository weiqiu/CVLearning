#ifndef SRC_SGM_CVL_SGM_IMPL_H__
#define SRC_SGM_CVL_SGM_IMPL_H__

#include <vector>
#include <base/mat.h>
#include <base/image.h>
#include <base/disparity_map.h>

namespace cvl
{
	namespace iner
	{
		class SgmImpl
		{
		public:
			SgmImpl(const Image& leftImg, const Image& rightImg);

			void SetDisparityRange(int minDisparity, int maxDisparity);

			DisparityMap Run();

		private:
			bool AllocMem();

			bool CmpCostVolume();

			bool CostAccumulate();

			bool ConsistCheck();

			bool PostPrecess();

		private:
			BaseMap<float> m_leftFloatImg;
			BaseMap<float> m_rightFloatImg;

			using cost_type = float;
			using CostVolume = std::vector<std::vector<std::vector<cost_type>>>;
			CostVolume m_costVolume;

			DisparityMap m_disparityMap;
			int m_minDisparity;
			int m_maxDisparity;
		};
	}
}

#endif //!SRC_SGM_CVL_SGM_IMPL_H__
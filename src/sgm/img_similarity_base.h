#ifndef CVL_SRC_SGM_IMG_SIMILARITY_BASE_H__
#define CVL_SRC_SGM_IMG_SIMILARITY_BASE_H__

#include <base/image.h>

namespace cvl
{
	class ImgSimilarity
	{
	public:
		using value_type = float;

		ImgSimilarity(const BaseMap<value_type>& leftImg, const BaseMap<value_type>& rightImg)
			:m_leftImg(leftImg), m_rightImg(rightImg) {};
		virtual ~ImgSimilarity() {};

		virtual value_type Run(int leftRow, int leftCol, int rightRow, int rightCol, int halfWinSize = 3) = 0;

	protected:
		const BaseMap<value_type>& m_leftImg;
		const BaseMap<value_type>& m_rightImg;
	};
}

#endif //!CVL_SRC_SGM_IMG_SIMILARITY_BASE_H__
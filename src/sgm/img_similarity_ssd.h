#ifndef CVL_SRC_SGM_IMG_SIMILARITY_SSD_H__
#define CVL_SRC_SGM_IMG_SIMILARITY_SSD_H__

#include <sgm/img_similarity_base.h>

namespace cvl
{
	class ImgSimilaritySSD : public ImgSimilarity
	{
	public:
		using value_type = ImgSimilarity::value_type;

		ImgSimilaritySSD(const BaseMap<value_type>& leftImg, const BaseMap<value_type>& rightImg)
			:ImgSimilarity(leftImg, rightImg) {};
		virtual ~ImgSimilaritySSD() {};

		virtual value_type Run(int leftRow,  int leftCol,
			                   int rightRow, int rightCol, 
			                   int halfWinSize = 3);
	};
}

#endif //!CVL_SRC_SGM_IMG_SIMILARITY_BASE_H__
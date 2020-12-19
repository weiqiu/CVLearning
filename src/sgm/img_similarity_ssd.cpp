
#include "img_similarity_ssd.h"

cvl::ImgSimilaritySSD::value_type
cvl::ImgSimilaritySSD::Run(int leftRow, int leftCol,
	                       int rightRow, int rightCol, int halfWinSize)
{
	if (leftRow < halfWinSize || leftRow >(m_leftImg.GetHeight() - halfWinSize))
		return 0;
	if (leftCol < halfWinSize || leftCol >(m_leftImg.GetWidth() - halfWinSize))
		return 0;

	if (rightRow < halfWinSize || rightRow >(m_rightImg.GetHeight() - halfWinSize))
		return 0;
	if (rightCol < halfWinSize || rightCol >(m_rightImg.GetWidth() - halfWinSize))
		return 0;

	value_type result = 0;
	for (int i = -halfWinSize; i < halfWinSize; i++) {		
		for (int j = -halfWinSize;j < halfWinSize; j++) {
			const int left_row = leftRow + i;
			const int left_col = leftCol + j;

			const int right_row = rightRow + i;
			const int right_col = rightCol + j;

			result += std::abs(m_leftImg.Get(left_row, left_col) - m_rightImg.Get(right_row, right_col));
		}
	}

	return result;
}
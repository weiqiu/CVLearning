#ifndef SRC_IMAGE_CVL_IMAGE_H__
#define SRC_IMAGE_CVL_IMAGE_H__

#include <vector>
#include "base_map.h"

namespace cvl
{
	class GrayImage : public BaseMap<unsigned char>
	{
	public:
		using value_type = unsigned char;

		GrayImage() {};
		GrayImage(int width, int height, int depth, const std::vector<value_type>& data);
		~GrayImage() {};
	};

	GrayImage::GrayImage(int width, int height, int depth, const std::vector<value_type>& data)
		:BaseMap<unsigned char>(width, height, depth, data) {};

	using Image = GrayImage;

} // namespace cvl

#endif //!SRC_IMAGE_CVL_IMAGE_H__
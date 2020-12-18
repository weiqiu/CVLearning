
#include <opencv2/opencv.hpp>
#include "image_io.h"

bool cvl::ImageIO::Load(const std::string& path, Image& img, bool color)
{
	int flag = 1;
	int depth = 3;
	if (!color) {
		flag = 0;
		depth = 1;
	}

	cv::Mat cvImg = cv::imread("path", flag);
	if (cvImg.empty()) {
		return false;
	}

	const int imgWidth = cvImg.cols;
	const int imgHeight = cvImg.rows;
	std::vector<Image::value_type> data(imgWidth * imgHeight * depth);
	return false;
}

bool cvl::ImageIO::Save(const std::string& path, const Image& img)
{
	return false;
}
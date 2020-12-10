#ifndef SRC_IMAGE_CVL_IMAGE_H__
#define SRC_IMAGE_CVL_IMAGE_H__

#include <string>
#include <vector>
#include <image/image.h>
#include <opencv2/opencv.hpp>

namespace cvl
{
	class ImageIO
	{
	pubic:
		static bool Load(Image<uchar>& image, const std::string& path, bool color = false);

		static bool Save(const Image<unsigned char>& image, const std::string& path);
	};

	bool ImageIO::Load(Image<unsigned char>& image, const std::string& path, bool color)
	{		
		cv::Mat cvImage;
		int width = 0;
		int height = 0;
		int depth = 0;

		if (color) {			
			cv::imread(cvImage);
			depth = 3;
		}
		else {			
			cv::imread(cvImage, 0);					
			depth = 1;
		}

		width = cvImage.cols;
		height = cvImage.rows;

		std::vector<unsigned char> data(width * height * depth, 0);
		memccpy(data.data(), cvImage.data, data.size(), sizeof(unsigned char));

		image = Image<uchar>(width, height, depth, data);

		return true;
	}

	bool ImageIO::Save(const Image<unsigned char>& image, const std::string& path)
	{
		cv::Mat cvImage;
		int width = image.GetWidth();
		int height = image.GetHeight();
		int depth = image.GetDepth();
		const auto& data = image.GetData();

		if (depth == 1) {
			cvMat = cv::Mat(width, height, CV_8UC3);			
		}
		else if (depth == 3) {
			cvMat = cv::Mat(width, height, CV_8UC1);
		}
		else {
			return false;
		}

		memccpy(cvImage.data, data.data(), data.size(), sizeof(unsigned char));
		cv::imread(cvImage, path);
		return true;
	}
}

#endif //!SRC_IMAGE_CVL_IMAGE_H__
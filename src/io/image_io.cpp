
#include <opencv2/opencv.hpp>
#include <log/log.h>
#include "image_io.h"

using namespace cvl;

bool io::ImageIO::Load(const std::string& path, Image& img, bool color)
{
	int flag = 1;
	int depth = 3;
	if (!color) {
		flag = 0;
		depth = 1;
	}

	cv::Mat cvImg = cv::imread(path, flag);
	if (cvImg.empty()) {
		cvl::Log(Log::LOG_ERROR) << "open image failed >> " << path << cvl::Log::End();
		return false;
	}

	const int imgWidth = cvImg.cols;
	const int imgHeight = cvImg.rows;
	std::vector<Image::value_type> data(imgWidth * imgHeight * depth);
	size_t size = data.size() * sizeof(Image::value_type);
	memcpy_s(data.data(), size, cvImg.data, size);

	return img.Set(imgWidth, imgHeight, depth, data);
}

bool io::ImageIO::Save(const std::string& path, const Image& img)
{
	cv::Mat cvImg;
	int imgWidth = img.GetWidth();
	int imgHeight = img.GetHeight();
	int imgDepth = img.GetDepth();

	if (imgDepth == 1) {
		cvImg = cv::Mat(imgHeight, imgWidth, CV_8UC1);
	}
	else if (imgDepth == 3) {
		cvImg = cv::Mat(imgHeight, imgWidth, CV_8UC3);
	}
	else {
		cvl::Log(Log::LOG_ERROR) << "save image failed" << path << cvl::Log::End();
		cvl::Log(Log::LOG_ERROR) << "only support image channle(one or three) >> " << imgDepth << cvl::Log::End();
		return false;
	}

	const auto& data = img.GetData();
	size_t size = data.size() * sizeof(Image::value_type);
	memcpy_s(cvImg.data,  size, data.data(), size);

	if (!cv::imwrite(path, cvImg)) {
		cvl::Log(Log::LOG_ERROR) << "save image failed" << path << cvl::Log::End();		
		return false;
	}

	return true;
}
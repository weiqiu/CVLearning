
#include <log/log.h>
#include <io/image_io.h>

int main(int argc, char** argv)
{
	if (argc != 3) {
		cvl::Log(cvl::Log::LOG_ERROR) << "Parameter error! please input image path and save path." << cvl::Log::End();
		return 1;
	}

	{
		cvl::Image colorImg;
		bool loadSuccess = cvl::io::ImageIO::Load(argv[1], colorImg, 1);
		if (loadSuccess) {
			cvl::Log() << "Load Color Image Success." << cvl::Log::End();
		}
		else {
			cvl::Log(cvl::Log::LOG_ERROR) << "Load Color Image Faild!" << cvl::Log::End();
		}

		bool SaveSuccess = cvl::io::ImageIO::Save(std::string(argv[2]) + ".color.jpg", colorImg);
		if (SaveSuccess) {
			cvl::Log() << "Save Color Image Success." << cvl::Log::End();
		}
		else {
			cvl::Log(cvl::Log::LOG_ERROR) << "Save Color Image Faild!" << cvl::Log::End();
		}
	}
	
	{
		cvl::Image grayImg;
		bool loadSuccess = cvl::io::ImageIO::Load(argv[1], grayImg, 0);
		if (loadSuccess) {
			cvl::Log() << "Load Gray Image Success." << cvl::Log::End();
		}
		else {
			cvl::Log(cvl::Log::LOG_ERROR) << "Load Gray Image Faild!" << cvl::Log::End();
		}

		bool SaveSuccess = cvl::io::ImageIO::Save(std::string(argv[2]) + ".gray.jpg", grayImg);
		if (SaveSuccess) {
			cvl::Log() << "Save Gray Image Success." << cvl::Log::End();
		}
		else {
			cvl::Log(cvl::Log::LOG_ERROR) << "Save Color Image Faild!" << cvl::Log::End();
		}
	}

	return 0;
}
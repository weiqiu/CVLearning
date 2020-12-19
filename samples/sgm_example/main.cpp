
#include <base/disparity_map.h>
#include <sgm/sgm.h>
#include <log/log.h>
#include <io/image_io.h>

int main(int argc, char** argv)
{
	if (argc != 4) {
		cvl::Log(cvl::Log::LOG_ERROR) << "Parameter error! please input : " <<
			"left image¡¢right image and disparity path." << cvl::Log::End();
		return 1;
	}

	cvl::Image leftImg;
	cvl::Image rightImg;
	
	cvl::io::ImageIO::Load(argv[1], leftImg, false);
	cvl::io::ImageIO::Load(argv[2], rightImg, false);

	cvl::DisparityMap DisparityMap = cvl::alg::Sgm::Run(leftImg, rightImg);
	
	return 0;
}
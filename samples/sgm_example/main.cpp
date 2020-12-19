
#include <sgm/sgm.h>
#include <io/image_io.h>

int main()
{
	cvl::Image leftImg;
	cvl::Image rightImg;
	


	cvl::DepthMap depthMap = cvl::alg::Sgm::Run(leftImg, rightImg);
	
	return 0;
}
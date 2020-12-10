
#include <sgm/sgm_impl.h>
#include <sgm/sgm.h>

cvl::Image<float> cvl::Sgm::Run(const Image<unsigned char>& leftImg, const Image<unsigned char>& rightImg)
{
	SgmImpl sgm;
	return sgm.Run(leftImg, rightImg);	
}
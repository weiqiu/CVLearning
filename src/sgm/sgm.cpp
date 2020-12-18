
#include <sgm/sgm_impl.h>
#include <sgm/sgm.h>

cvl::DepthMap cvl::Sgm::Run(const Image& leftImg, const Image& rightImg)
{
	SgmImpl sgm;
	return sgm.Run(leftImg, rightImg);	
}
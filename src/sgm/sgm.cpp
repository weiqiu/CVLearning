
#include <sgm/sgm_impl.h>
#include <sgm/sgm.h>

using namespace cvl;

DepthMap alg::Sgm::Run(const Image& leftImg, const Image& rightImg)
{
	iner::SgmImpl sgm;
	return sgm.Run(leftImg, rightImg);	
}
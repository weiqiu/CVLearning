
#include <sgm/sgm_impl.h>
#include <sgm/sgm.h>

using namespace cvl;

DisparityMap alg::Sgm::Run(const Image& leftImg, const Image& rightImg)
{
	iner::SgmImpl sgm(leftImg, rightImg);
	sgm.SetDisparityRange(0, 255);
	
	return sgm.Run();	
}
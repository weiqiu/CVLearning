
#include <sgm/sgm_impl.h>

cvl::Image<float> cvl::SgmImpl::Run(const Image<unsigned char>& leftImg, 
	                                const Image<unsigned char>& rightImg)
{
	return m_depthMap;
}
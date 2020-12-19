
#include <log/log.h>
#include <sgm/img_similarity_ssd.h>
#include <sgm/sgm_impl.h>

cvl::iner::SgmImpl::SgmImpl(const cvl::Image& leftImg, const cvl::Image& rightImg)	
{
	m_leftFloatImg = leftImg.TypeConvert<float>();
	m_rightFloatImg = rightImg.TypeConvert<float>();

	m_minDisparity = 0;
	m_maxDisparity = 0;
}

void cvl::iner::SgmImpl::SetDisparityRange(int minDisparity, int maxDisparity)
{
	m_minDisparity = minDisparity;
	m_maxDisparity = maxDisparity;
}

cvl::DisparityMap cvl::iner::SgmImpl::Run()
{
	cvl::Log(Log::LOG_INFO) << "SGM >> AllocMem() " << cvl::Log::End();
	if (!AllocMem()) {
		cvl::Log(Log::LOG_ERROR) << "SGM Failed >> AllocMem() in " << __FILE__ << " " << __LINE__ << cvl::Log::End();
		return DisparityMap();
	}

	cvl::Log(Log::LOG_INFO) << "SGM >> CmpCostVolume() " << cvl::Log::End();
	if (!CmpCostVolume()) {
		cvl::Log(Log::LOG_ERROR) << "SGM Failed >> CmpCostVolume() in " << __FILE__ << " " << __LINE__ << cvl::Log::End();
		return DisparityMap();
	}

	cvl::Log(Log::LOG_INFO) << "SGM >> CostAccumulate() " << cvl::Log::End();
	if (!CostAccumulate()) {
		cvl::Log(Log::LOG_ERROR) << "SGM Failed >> CostAccumulate() in " << __FILE__ << " " << __LINE__ << cvl::Log::End();
		return DisparityMap();
	}

	cvl::Log(Log::LOG_INFO) << "SGM >> ConsistCheck() " << cvl::Log::End();
	if (!ConsistCheck()) {
		cvl::Log(Log::LOG_ERROR) << "SGM Failed >> ConsistCheck() in " << __FILE__ << " " << __LINE__ << cvl::Log::End();
		return DisparityMap();
	}

	cvl::Log(Log::LOG_INFO) << "SGM >> PostPrecess() " << cvl::Log::End();
	if (!PostPrecess()) {
		cvl::Log(Log::LOG_ERROR) << "SGM Failed >> PostPrecess() in " << __FILE__ << " " << __LINE__ << cvl::Log::End();
		return DisparityMap();
	}

	return m_disparityMap;
}

bool cvl::iner::SgmImpl::AllocMem()
{	
	const int width = m_leftFloatImg.GetWidth();
	const int height = m_leftFloatImg.GetHeight();
	const int disparityRange = m_maxDisparity - m_minDisparity;

	m_costVolume.resize(height);
	for (int row = 0; row < height; row++) {
		m_costVolume[row].resize(width);
		for (int col = 0; col < width; col++) {
			m_costVolume[row][col].resize(disparityRange);
		}
	}

	return true;
}

bool cvl::iner::SgmImpl::CmpCostVolume()
{
	const int width = m_leftFloatImg.GetWidth();
	const int height = m_leftFloatImg.GetHeight();
	const int depth = m_maxDisparity - m_minDisparity;

	ImgSimilarity* imgSimilarity = new ImgSimilaritySSD(m_leftFloatImg, m_rightFloatImg);

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {		
			cvl::Log(Log::LOG_INFO) << row << " " << col << cvl::Log::End();
#pragma omp parallel for
			for (int d = 0; d < depth; d++) {
				m_costVolume[row][col][d] = imgSimilarity->Run(row, col, row, col + d);
			}
		}
	}

	delete imgSimilarity;
	imgSimilarity = nullptr;

	return true;
}

bool cvl::iner::SgmImpl::CostAccumulate()
{
	return false;
}

bool cvl::iner::SgmImpl::ConsistCheck()
{
	return false;
}

bool cvl::iner::SgmImpl::PostPrecess()
{
	return false;
}
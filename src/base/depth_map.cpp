
#include "depth_map.h"

cvl::DepthMap::DepthMap(int width, int height, int depth,
	                    const std::vector<value_type>& data)
	:BaseMap<value_type>(width, height, depth, data)
{
	m_minDepth = -0.1f;
	m_maxDepth = -0.1f;
};

void cvl::DepthMap::GetDepthRange(float& minDepth, float& maxDepth)
{
	minDepth = m_minDepth;
	maxDepth = m_maxDepth;
}
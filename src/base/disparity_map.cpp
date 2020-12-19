
#include "disparity_map.h"

cvl::DisparityMap::DisparityMap(int width, int height, int depth,
	                            const std::vector<value_type>& data)
	:BaseMap<value_type>(width, height, depth, data)
{

};
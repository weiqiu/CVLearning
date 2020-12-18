#ifndef SRC_IMAGE_CVL_DEPTH_MAP_H__
#define SRC_IMAGE_CVL_DEPTH_MAP_H__

#ifndef CVL_BASE_LIB_EXPORTS
#define CVL_BASE_LIB_EXPORT __declspec(dllimport)
#else
#define CVL_BASE_LIB_EXPORT __declspec(dllexport)
#endif

#include <string>
#include <vector>
#include "base_map.h"

namespace cvl
{
	class CVL_BASE_LIB_EXPORT DepthMap : public BaseMap<float>
	{
	public:
		using value_type = float;

		DepthMap() {};
		DepthMap(int width, int height, int depth, const std::vector<value_type>& data);
		~DepthMap() {};

		void GetDepthRange(float& minDepth, float& maxDepth);

	private:
		float m_minDepth;
		float m_maxDepth;
	};

} // namespace cvl

#ifndef CVL_BASE_LIB_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLBaseLibd.lib") 
#else
#pragma comment(lib, "CVLBaseLib.lib") 
#endif
#endif

#endif //!SRC_IMAGE_CVL_DEPTH_MAP_H__
#ifndef SRC_IMAGE_CVL_IMAGE_H__
#define SRC_IMAGE_CVL_IMAGE_H__

#ifndef CVL_BASE_LIB_EXPORTS
#define CVL_BASE_LIB_EXPORT __declspec(dllimport)
#else
#define CVL_BASE_LIB_EXPORT __declspec(dllexport)
#endif

#include <string>
#include <vector>
#include <base/base_map.h>

namespace cvl
{
	class CVL_BASE_LIB_EXPORT Image : public BaseMap<unsigned char>
	{
	public:
		using value_type = unsigned char;

		Image() {};
		Image(int width, int height, int depth, const std::vector<value_type>& data);
		~Image() {};

		void SetName(const std::string& name);

		std::string GetName();

	private:
		std::string m_name;
	};

} // namespace cvl

#ifndef CVL_BASE_LIB_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLBaseLibd.lib") 
#else
#pragma comment(lib, "CVLBaseLib.lib") 
#endif
#endif

#endif //!SRC_IMAGE_CVL_IMAGE_H__
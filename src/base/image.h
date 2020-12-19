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

		template<typename T>
		BaseMap<T> TypeConvert() const;

	private:
		std::string m_name;
	};

	template<typename T>
	cvl::BaseMap<T> cvl::Image::TypeConvert() const
	{
		// cvl::BaseMap<float> floatMap();
		std::vector<T> data(m_width * m_height * m_depth);
		for (int i = 0; i < m_data.size(); i++) {
			data[i] = static_cast<T>(m_data[i]);
		}

		return cvl::BaseMap<T>(m_width, m_height, m_depth, data);
	}

} // namespace cvl

#ifndef CVL_BASE_LIB_EXPORTS
#ifdef _DEBUG
#pragma comment(lib, "CVLBaseLibd.lib") 
#else
#pragma comment(lib, "CVLBaseLib.lib") 
#endif
#endif

#endif //!SRC_IMAGE_CVL_IMAGE_H__
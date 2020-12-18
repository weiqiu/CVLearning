
#include "image.h"

cvl::Image::Image(int width, int height, int depth, 
	              const std::vector<value_type>& data)
	:BaseMap<value_type>(width, height, depth, data)
{

};

void cvl::Image::SetName(const std::string& name)
{
	m_name = name;
}

std::string cvl::Image::GetName()
{
	return m_name;
}
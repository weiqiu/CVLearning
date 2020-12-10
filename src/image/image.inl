
// template impl for image

namespace cvl
{

	template<typename T>
	Image<T>::Image() :m_width(0), m_height(0), m_depth(0) {};

	//template<typename T>
	//Image<T>::Image(const Image<T>& image)
	//{
	//	m_width = image.GetWidth();
	//	m_height = image.GetHeight();
	//	m_depth = image.GetDepth();

	//	m_data = image.GetData();
	//};

	template<typename T>
	Image<T>::Image(int width, int height, int depth, const std::vector<T>& data)
	{
		m_width = width;
		m_height = height;
		m_depth = depth;

		m_data = data;
	}

	template<typename T>
	bool Image<T>::Get(int row, int col, T& value)
	{
		if (!LegalPos(row, col))
			return false;

		T = m_data[row * m_width * m_depth + col * m_depth];

		return true;
	}

	template<typename T>
	bool Image<T>::GetSlice(int row, int col, T* &value)
	{
		if (!LegalPos(row, col))
			return false;

		for (int i = 0; i < m_depth; i++) {
			T[i] = m_data[row * m_width * m_depth + col * m_depth + i];
		}
		
		return true;
	}

	template<typename T>
	bool Image<T>::Set(int row, int col, const T& value)
	{
		if (!LegalPos(row, col))
			return false;

		m_data[row * m_width * m_depth + col * m_depth] = T;

		return true;
	}

	template<typename T>
	bool Image<T>::SetSlice(int row, int col, const T* value)
	{
		if (!LegalPos(row, col))
			return false;

		for (int i = 0; i < m_depth; i++) {
			m_data[row * m_width * m_depth + col * m_depth + i] = T[i];
		}

		return true;
	}

	template<typename T>
	bool Image<T>::LegalPos(int row, int col)
	{
		if (row < 0 || col < 0)
			return false;

		if (row >= m_height || col >= m_width)
			return false;

		return true;
	}

} // namespace cvl
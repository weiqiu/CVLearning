
// template impl for BaseMap

namespace cvl
{

	template<typename T>
	BaseMap<T>::BaseMap() :m_width(0), m_height(0), m_depth(0) {};

	template<typename T>
	BaseMap<T>::BaseMap(int width, int height, int depth, const std::vector<T>& data)
	{
		m_width = width;
		m_height = height;
		m_depth = depth;

		m_data = data;
	}

	template<typename T>
	bool BaseMap<T>::Get(int row, int col, T& value)
	{
		if (!LegalPos(row, col))
			return false;

		T = m_data[row * m_width * m_depth + col * m_depth];

		return true;
	}

	template<typename T>
	bool BaseMap<T>::GetSlice(int row, int col, T* &value)
	{
		if (!LegalPos(row, col))
			return false;

		for (int i = 0; i < m_depth; i++) {
			T[i] = m_data[row * m_width * m_depth + col * m_depth + i];
		}
		
		return true;
	}

	template<typename T>
	bool BaseMap<T>::Set(int row, int col, const T& value)
	{
		if (!LegalPos(row, col))
			return false;

		m_data[row * m_width * m_depth + col * m_depth] = T;

		return true;
	}

	template<typename T>
	bool BaseMap<T>::SetSlice(int row, int col, const T* value)
	{
		if (!LegalPos(row, col))
			return false;

		for (int i = 0; i < m_depth; i++) {
			m_data[row * m_width * m_depth + col * m_depth + i] = T[i];
		}

		return true;
	}

	template<typename T>
	bool BaseMap<T>::LegalPos(int row, int col)
	{
		if (row < 0 || col < 0)
			return false;

		if (row >= m_height || col >= m_width)
			return false;

		return true;
	}

} // namespace cvl
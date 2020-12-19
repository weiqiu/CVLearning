#ifndef SRC_IMAGE_CVL_BASE_MAP_H__
#define SRC_IMAGE_CVL_BASE_MAP_H__

#include <vector>

namespace cvl
{
	template<typename T>
	class BaseMap
	{
	public:
		BaseMap();
		BaseMap(int width, int height, int depth, const std::vector<T>& data);
		~BaseMap() {};

		int GetWidth() { return m_width; };
		int GetHeight() { return m_height; };
		int GetDepth() { return m_depth; };

		int GetWidth() const { return m_width; };
		int GetHeight() const { return m_height; };
		int GetDepth() const { return m_depth; };

		const std::vector<T>& GetData() { return m_data; };
		const std::vector<T>& GetData() const { return m_data; };

		bool Get(int row, int col, T& value);
		bool GetSlice(int row, int col, T* &value);

		bool Get(int row, int col, T& value) const;
		bool GetSlice(int row, int col, T* &value) const;

		bool Set(int row, int col, const T& value);
		bool Set(int width, int height, int depth, const std::vector<T>& data);
		bool SetSlice(int row, int col, const T* value);
		
	private:
		bool LegalPos(int row, int col);

	private:
		int m_width;
		int m_height;
		int m_depth;
		std::vector<T> m_data;
	};

} // namespace cvl

#include "base_map.inl"

#endif //!SRC_IMAGE_CVL_BASE_MAP_H__
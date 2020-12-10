#ifndef SRC_IMAGE_CVL_IMAGE_H__
#define SRC_IMAGE_CVL_IMAGE_H__

#include <vector>

namespace cvl
{
	template<typename T>
	class Image
	{
	public:
		Image();
		//Image(const Image<T>& image);
		Image(int width, int height, int depth, const std::vector<T>& data);
		~Image() {};

		int GetWidth() { return m_width; };
		int GetHeight() { return m_heigth; };
		int GetDepth() { return m_depth; };

		const std::vector<T>& GetData() { return m_data; };

		bool Get(int row, int col, T& value);

		bool GetSlice(int row, int col, T* &value);

		bool Set(int row, int col, const T& value);

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

#include "image.inl"

#endif //!SRC_IMAGE_CVL_IMAGE_H__
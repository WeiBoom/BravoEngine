#pragma once
#include <vector>
#include <glad/glad.h>

struct VertexAttrib {
	unsigned int Type;
	unsigned int Count;
	unsigned int Size;
	unsigned char normalized;
};


class VertexLayout
{
private:
	std::vector<VertexAttrib> Attribs;
public:
	unsigned int VertexStride;

	VertexLayout():VertexStride(0) {}
	~VertexLayout() {}
	
	template<typename T>
	void AddElement(unsigned int count)
	{
		//static_assert(false);
	}

	template<>
	void AddElement<float>(unsigned int count) {
		unsigned int stride = count * sizeof(float);
		Attribs.push_back({ GL_FLOAT, count, stride, GL_FALSE});
		VertexStride += stride;
	}

	template<>
	void AddElement<unsigned int>(unsigned int count) {
		unsigned int stride = count * sizeof(unsigned int);
		Attribs.push_back({ GL_UNSIGNED_INT, count, stride, GL_FALSE });
		VertexStride += stride;
	}

	template<>
	void AddElement<unsigned char>(unsigned int count) {
		unsigned int stride = count * sizeof(unsigned char);
		Attribs.push_back({ GL_UNSIGNED_BYTE, count, stride, GL_TRUE });
		VertexStride += stride;
	}

	void Bind() {
		unsigned int offset = 0;
		for (int i = 0; i < Attribs.size(); i++) {
			const auto& attrib = Attribs[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, attrib.Count, attrib.Type, attrib.normalized, VertexStride, (const void*)offset);
			offset += attrib.Size;
		}
	}

};

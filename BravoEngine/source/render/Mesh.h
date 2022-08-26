#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <memory>

class Mesh
{
private:
	std::unique_ptr<const float*> mVertices;
	size_t mVerticesCount;
	std::unique_ptr<const unsigned int*> mIndices;
	size_t mIndicesCount;
	std::unique_ptr<VertexArray> mVertexArray;
	std::unique_ptr<IndexBuffer> mIndexBuffer;
	

public:
	Mesh(const float* vertices, size_t verticesCount, const unsigned int* indices, size_t indicesSize, VertexLayout layout);
	~Mesh();
	void Bind();
	void UnBind();

	inline size_t GetVerticesCount() { return mVerticesCount; }
	inline size_t GetCount() { return mIndicesCount; }
};


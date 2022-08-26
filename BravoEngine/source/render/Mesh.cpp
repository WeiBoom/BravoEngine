#include "Mesh.h"

Mesh::Mesh(const float* vertices, size_t verticesCount, const unsigned int* indices, size_t indicesSize, VertexLayout layout) : 
	mVerticesCount(verticesCount), mIndicesCount(indicesSize) 
{
	mVertices = std::make_unique<const float*>(vertices);
	mIndices = std::make_unique<const unsigned int*>(indices);
	mVertexArray = std::make_unique<VertexArray>(new VertexBuffer(vertices, mVerticesCount * layout.VertexStride), &layout);
	mIndexBuffer = std::make_unique<IndexBuffer>(indices, mIndicesCount);
}


Mesh::~Mesh() {
}

void Mesh::Bind() {
	if (!mVertexArray || !mIndexBuffer) return;
	mVertexArray->Bind();
	mIndexBuffer->Bind();
}


void Mesh::UnBind() {
	if (!mVertexArray || !mIndexBuffer) return;
	mVertexArray->UnBind();
	mIndexBuffer->UnBind();
}

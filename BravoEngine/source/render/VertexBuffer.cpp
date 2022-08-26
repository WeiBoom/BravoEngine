#include "VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void* data, size_t size) : mID(0) {
	glGenBuffers(1, &mID);
	glBindBuffer(GL_ARRAY_BUFFER, mID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &mID);
}

void VertexBuffer::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, mID);
}

void VertexBuffer::UnBind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

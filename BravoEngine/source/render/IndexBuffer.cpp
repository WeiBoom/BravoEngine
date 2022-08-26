#include "IndexBuffer.h"
#include <glad/glad.h>
#include <iostream>

IndexBuffer::IndexBuffer(const void* data, size_t count) : mID(0), mCount(count) {
	glGenBuffers(1, &mID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
	printf("[~IndexBuffer]id: %d\n", mID);
	glDeleteBuffers(1, &mID);
}

void IndexBuffer::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
}

void IndexBuffer::UnBind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


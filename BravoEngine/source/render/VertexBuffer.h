#pragma once
class VertexBuffer
{
private:
	unsigned int mID;

public:
	VertexBuffer(const void* data, size_t size);
	~VertexBuffer();
	inline unsigned int GetID() { return mID; }

	void Bind();
	void UnBind();
};


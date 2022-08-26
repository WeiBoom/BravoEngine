#pragma once
class IndexBuffer
{
private:
	unsigned int mID;
	size_t mCount;
public:
	IndexBuffer(const void* data, size_t count);
	~IndexBuffer();

	inline unsigned int GetID() { return mID; }
	inline size_t GetCount() { return mCount; }
	void Bind();
	void UnBind();
};


#pragma once
#include "VertexBuffer.h"
#include "VertexLayout.h"
#include <memory>

class VertexArray
{
private:
	unsigned int mID;
	std::unique_ptr<VertexBuffer> vb;

public:
	VertexArray(VertexBuffer* vb, VertexLayout* layout);
	~VertexArray();
	inline unsigned int GetID() { return mID; }
	void Bind();
	void UnBind();

	static VertexArray* CreateInstance(VertexBuffer* vb, VertexLayout* layout);
};


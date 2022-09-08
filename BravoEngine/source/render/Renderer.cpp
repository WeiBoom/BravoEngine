#include "Renderer.h"
#include <iostream>

Renderer::Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat) 
	: mMesh(mesh), mMat(mat) {
}

Renderer::~Renderer() {
}

void Renderer::Render() const{
	if (!mMesh) return;
	mMesh->Bind();
	mMat->ApplyProperty();
	glDrawElements(GL_TRIANGLES, mMesh->GetCount(), GL_UNSIGNED_INT, NULL);
}
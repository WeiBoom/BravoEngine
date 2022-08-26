#include "Renderer.h"
#include <iostream>

Renderer::Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader) 
	: m_Mesh(mesh), m_Shader(shader) {
}

Renderer::~Renderer() {
}


void Renderer::Render() const{
	if (!m_Mesh) return;
	m_Mesh->Bind();
	m_Shader->Bind();
	glDrawElements(GL_TRIANGLES, m_Mesh->GetCount(), GL_UNSIGNED_INT, NULL);
}
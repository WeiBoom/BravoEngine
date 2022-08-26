#pragma once
#include "Mesh.h"
#include "Shader.h"
#include <memory>

class Renderer
{
private:
	std::shared_ptr<Mesh> m_Mesh;
	std::shared_ptr<Shader> m_Shader;
public:
	Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader);
	~Renderer();

	void Render() const;
};


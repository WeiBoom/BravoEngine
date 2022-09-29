#pragma once
#include "Mesh.h"
#include"Material.h"
#include <memory>

class Renderer
{
private:
	std::shared_ptr<Mesh> mMesh;
	std::shared_ptr<Material> mMat;
public:
	Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material);
	~Renderer();

	void Render() const;
};


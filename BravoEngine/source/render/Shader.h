#pragma once
#include <string>;
#include <unordered_map>
#include <glm/glm.hpp>

class Shader
{
public:
	enum class ShaderType{
		None = -1,
		Vertex = 0,
		Fragment = 1
	};

private:
	unsigned int mID;
	std::string mVertexShaderSrc;
	std::string mFragShaderSrc;
	std::unordered_map<std::string, int> mPropertyID;

	std::string* GetSrcCode(const char* shaderName);
	unsigned int CreateShader(unsigned int type, const std::string& src);
	unsigned int CreateProgram(const std::string& vs, const std::string& fs);
public:
	Shader(const char* shaderName);
	~Shader();
	void Bind();
	int GetPropertyID(const std::string& name);
	void SetVec4(const std::string& name, const glm::vec4& vec4);
};


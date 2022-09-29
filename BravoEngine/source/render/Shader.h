#pragma once
#include <string>;
#include <unordered_map>
#include <glm/glm.hpp>
#include "ShaderProperty.h"

class Shader
{
public:
	enum class ShaderType {
		None = -1,
		Vertex = 0,
		Fragment = 1,
		Property = 2
	};

private:
	unsigned int mID;
	std::string mVertexShaderSrc;
	std::string mFragShaderSrc;
	std::unordered_map<std::string, int> mPropertyID;

	std::string* GetSrcCode(const char* shaderName);
	unsigned int CreateShader(unsigned int type, const std::string& src);
	unsigned int CreateProgram(const std::string& vs, const std::string& fs);
	void CollectProperty(std::string& srcCode);

	std::vector<VectorProperty*> mVectorProperty;
	std::vector<ColorProperty*> mColorProperty;
	std::vector<FloatProperty*> mFloatProperty;
	std::vector<TextureProperty*> mTexProperty;

public:
	Shader(const char* shaderName);
	~Shader();
	void Bind();
	int GetPropertyID(const std::string& name);

	// 不会保存在Properties中
	void SetVec4Imp(const std::string& name, const glm::vec4& vec4);
	void SetFloatImp(const std::string& name, const float& val);

	/// Shader::SetXXX 会对所有材质都并更新properties
	void SetVec4(const std::string& name, glm::vec4& vec4);
	void SetColor(const std::string& name, glm::vec4& vec4);
	void SetFloat(const std::string& name, float& val);
	void ApplyProperty();
	
	void GetVectorProperty(std::vector<VectorProperty>& vec);
	void GetColorProperty(std::vector<ColorProperty>& vec);
	void GetFloatProperty(std::vector<FloatProperty>& vec);
	void GetTextureProperty(std::vector<TextureProperty>& vec);
};


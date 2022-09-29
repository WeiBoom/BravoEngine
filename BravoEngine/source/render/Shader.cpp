#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>
#include "../utils/StringUtils.h"

Shader::Shader(const char* shaderName):mID(0), mVertexShaderSrc(""), mFragShaderSrc("")
{
	std::string* srcCode = GetSrcCode(shaderName);
	if (srcCode == nullptr) {
		printf("[Shader]Create %s failed", shaderName);
		return;
	}
	mVertexShaderSrc = srcCode[0];
	mFragShaderSrc = srcCode[1];
	mID = CreateProgram(mVertexShaderSrc, mFragShaderSrc);
}

Shader::~Shader() {
	glDeleteProgram(mID);
}

void Shader::Bind() {
	glUseProgram(mID);
}

int Shader::GetPropertyID(const std::string& name) {
	int propertyID = -1;
	if (mPropertyID.find(name) != mPropertyID.end()) {
		propertyID = mPropertyID[name];
	}
	else {
		propertyID = glGetUniformLocation(mID, name.c_str());
	}
	return propertyID;
}

void Shader::SetVec4(const std::string& name, glm::vec4& vec4) {
	bool hasProperty = false;
	for (VectorProperty* vp : mVectorProperty) {
		if (!vp) continue;
		if (vp->GetName() == name) {
			vp->SetValue(vec4);
		}
		hasProperty = true;
	}
	if (hasProperty) return;
	SetVec4Imp(name, vec4);
}

void Shader::SetColor(const std::string& name, glm::vec4& vec4) {
	bool hasProperty = false;
	for (ColorProperty* vp : mColorProperty) {
		if (!vp) continue;
		if (vp->GetName() == name) {
			vp->SetValue(vec4);
		}
		hasProperty = true;
	}
	if (hasProperty) return;
	SetVec4Imp(name, vec4);
}

void Shader::SetFloat(const std::string& name, float& val) {
	bool hasProperty = false;
	for (FloatProperty* fp : mFloatProperty) {
		if (!fp) continue;
		if (fp->GetName() == name) {
			fp->SetValue(val);
		}
		hasProperty = true;
	}
	if (hasProperty) return;
	SetFloatImp(name, val);
}

void Shader::SetVec4Imp(const std::string& name, const glm::vec4& vec4) {
	Bind();
	int propertyID = GetPropertyID(name);
	glUniform4f(propertyID, vec4.x, vec4.y, vec4.z, vec4.w);
}

void Shader::SetFloatImp(const std::string& name, const float& val) {
	Bind();
	int propertyID = GetPropertyID(name);
	glUniform4f(propertyID, val, 0, 0, 0);
}


void Shader::ApplyProperty() {
	for (VectorProperty* vp : mVectorProperty) {
		if (!vp) continue;
		SetVec4Imp(vp->GetName(), vp->GetValue());
	}

	for (ColorProperty* cp : mColorProperty) {
		if (!cp) continue;
		SetVec4Imp(cp->GetName(), cp->GetValue());
	}

	for (FloatProperty* fp : mFloatProperty) {
		if (!fp) continue;
		SetFloatImp(fp->GetName(), fp->GetValue());
	}
}

void Shader::GetVectorProperty(std::vector<VectorProperty>& vec) {
	for (VectorProperty* vp : mVectorProperty) {
		if (!vp) continue;
		vec.push_back(*vp);
	}
}

void Shader::GetFloatProperty(std::vector<FloatProperty>& vec) {
	for (FloatProperty* fp : mFloatProperty) {
		if (!fp) continue;
		vec.push_back(*fp);
	}
}

void Shader::GetColorProperty(std::vector<ColorProperty>& vec) {
	for (ColorProperty* cp : mColorProperty) {
		if (!cp) continue;
		vec.push_back(*cp);
	}
}

void Shader::GetTextureProperty(std::vector<TextureProperty>& vec) {
	for (TextureProperty* tp : mTexProperty) {
		if (!tp) continue;
		vec.push_back(*tp);
	}
}


#pragma region Private

std::string* Shader::GetSrcCode(const char* shaderName) {
	std::ifstream file(shaderName, std::ios::in);
	std::string line;
	std::stringstream strStream[2];
	Shader::ShaderType type = Shader::ShaderType::None;
	while (std::getline(file, line)) {
		if (line.find("#vertex") != std::string::npos) {
			type = Shader::ShaderType::Vertex;
		}
		else if (line.find("#fragment") != std::string::npos) {
			type = Shader::ShaderType::Fragment;
		}
		else if (line.find("#property") != std::string::npos) {
			type = Shader::ShaderType::Property;
		}
		else {
			switch (type)
			{
			case Shader::ShaderType::Vertex:
			case Shader::ShaderType::Fragment:
				strStream[(int)type] << line << '\n';
				break;
			case Shader::ShaderType::Property:
				CollectProperty(line);
				break;
			default:
				file.close();
				return nullptr;
			}
		}
	}
	file.close();
	return new std::string[2]{ strStream[0].str(), strStream[1].str() };
}



unsigned int Shader::CreateShader(unsigned int type, const std::string& src) {
	unsigned int id = glCreateShader(type);
	const char* srcCode = src.c_str();
	glShaderSource(id, 1, &srcCode, nullptr);
	glCompileShader(id);
	GLint compiled;
	glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		int logSize = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logSize);
		char* msg = (char*)_malloca(logSize * sizeof(char));
		glGetShaderInfoLog(id, 1024, &logSize, msg);
		printf("[CreateShader]%s \n", msg);
	}
	return id;
}

unsigned int Shader::CreateProgram(const std::string& vs, const std::string& fs) {
	unsigned int program = glCreateProgram();
	unsigned int vsID = CreateShader(GL_VERTEX_SHADER, vs);
	unsigned int fsID = CreateShader(GL_FRAGMENT_SHADER, fs);
	glAttachShader(program, vsID);
	glAttachShader(program, fsID);
	glLinkProgram(program);
	int linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked) {
		int logSize = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
		char* msg = (char*)_malloca(logSize * sizeof(char));
		glGetProgramInfoLog(program, 1024, &logSize, msg);
		printf("[CreateProgram]%s \n", msg);
	}
	glDeleteShader(vsID);
	glDeleteShader(fsID);
	return program;
}


void Shader::CollectProperty(std::string& srcCode) {
	// type;name;value
	if (srcCode.size() == 0) return;
	std::vector<std::string> tokens;
	StringUtils::Split(srcCode, tokens, ':');
	if (tokens.size() != 3) return;

	std::string& type = tokens[0];
	std::string& name = tokens[1];
	std::string& val = tokens[2];
	if (type == "Vec4") {
		VectorProperty* vp = new VectorProperty(name, StringUtils::StrToVec4(val));
		mVectorProperty.push_back(vp);
	}
	else if (type == "Color") {
		ColorProperty* cp = new ColorProperty(name, StringUtils::StrToVec4(val));
		mColorProperty.push_back(cp);
	}
	else if (type == "2D") {
		TextureProperty* tp = new TextureProperty(name, val);
		mTexProperty.push_back(tp);
	}
	else if (type == "Float") {
		FloatProperty* fp = new FloatProperty(name, std::stof(val));
		mFloatProperty.push_back(fp);
	}
}
#pragma endregion







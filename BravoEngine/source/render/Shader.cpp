#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>

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

void Shader::SetVec4(const std::string& name, const glm::vec4& vec4) {
	Bind();
	int propertyID = GetPropertyID(name);
	glUniform4f(propertyID, vec4.x, vec4.y, vec4.z, vec4.w);
}

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
		else {
			if (type == Shader::ShaderType::None) {
				file.close();
				return nullptr;
			}
			strStream[(int)type] << line << '\n';
		}
	}
	file.close();
	return new std::string[2]{ strStream[0].str(), strStream[1].str()};
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
		glGetShaderInfoLog (id, 1024, &logSize, msg);
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








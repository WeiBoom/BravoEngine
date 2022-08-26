#pragma once
#include <unordered_map>
#include <glad/glad.h>

class GLDebug
{
private:
	std::unordered_map<int, std::string> mSrc;
	std::unordered_map<int, std::string> mType;
	std::unordered_map<int, std::string> mServerity;

public:
	GLDebug();
	~GLDebug();
	void OutputError(GLenum source, GLenum type, GLuint id, GLenum severity, const GLchar* message);
};


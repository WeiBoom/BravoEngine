#include "GLDebug.h"
#include <iostream>

GLDebug::GLDebug() 
{
	mSrc.insert(std::pair<int, std::string>(GL_DEBUG_SOURCE_API, "GL source"));
	mSrc.insert(std::pair<int, std::string>(GL_DEBUG_SOURCE_SHADER_COMPILER, "Shader error"));
	mSrc.insert(std::pair<int, std::string>(GL_DEBUG_SOURCE_WINDOW_SYSTEM, "Window system error"));
	mSrc.insert(std::pair<int, std::string>(GL_DEBUG_SOURCE_THIRD_PARTY, "Third lib error"));
	mSrc.insert(std::pair<int, std::string>(GL_DEBUG_SOURCE_APPLICATION, "App error"));
	mSrc.insert(std::pair<int, std::string>(GL_DEBUG_SOURCE_OTHER, "Unknown error"));

	mType.insert(std::pair<int, std::string>(GL_DEBUG_TYPE_ERROR, "Type error"));
	mType.insert(std::pair<int, std::string>(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR, "Undefined behavior"));
	mType.insert(std::pair<int, std::string>(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR, "Deprecated behavior"));
	mType.insert(std::pair<int, std::string>(GL_DEBUG_TYPE_OTHER, "Orther type"));

	mServerity.insert(std::pair<int, std::string>(GL_DEBUG_SEVERITY_HIGH, "High"));
	mServerity.insert(std::pair<int, std::string>(GL_DEBUG_SEVERITY_MEDIUM, "Medium"));
	mServerity.insert(std::pair<int, std::string>(GL_DEBUG_SEVERITY_LOW, "Low"));
	mServerity.insert(std::pair<int, std::string>(GL_DEBUG_SEVERITY_NOTIFICATION, "Notification"));
}

GLDebug::~GLDebug() {}


void GLDebug::OutputError(GLenum source, GLenum type, GLuint id, GLenum severity, const GLchar* message) 
{
	//std::cout <<
	//"serverity: " << mServerity[(int)severity] << std::endl <<
	//"src: " << mSrc[(int)source] << std::endl <<
	//"type: " << mType[(int)type] << std::endl <<
	//"id: " << id << std::endl <<
	//"mgs: " << message << std::endl;

	printf("serverity: %s\nsrc: %s\ntype: %s\nid: %i\nmsg: %s\n\n\n\n", mServerity[(int)severity].c_str(), mSrc[(int)source].c_str(), mType[(int)type].c_str(), id, message);

}

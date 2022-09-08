#pragma once
#include <string>
#include <glm/glm.hpp>

enum class PropertyType
{
	VECTOR = 0,
	COLOR = 1,
	FLOAT = 2,
	TEXTURE = 3,
	MAX = 4
};


template<typename T>
class ShaderProperty {
protected:
	PropertyType mType;
	std::string mPropertyName;
	T mValue;
public:

	ShaderProperty(PropertyType type, std::string& name, T value) :
		mType(type), mPropertyName(name), mValue(value){}

	virtual void OnGUI() = 0;
	virtual T GetValue() = 0;
	virtual void SetValue(T& v) = 0;
	const std::string& GetName() 
	{
		return mPropertyName;
	}
};

class VectorProperty : public ShaderProperty<glm::vec4> {
public:
	VectorProperty(std::string& name, glm::vec4 value);
	void OnGUI() override;
	glm::vec4 GetValue() override;
	void SetValue(glm::vec4& v) override;
};


class FloatProperty : public ShaderProperty<float> {
public:
	FloatProperty(std::string& name, float value);
	void OnGUI() override;
	float GetValue() override;
	void SetValue(float& v) override;
};


class ColorProperty : public ShaderProperty<glm::vec4> {
public:
	ColorProperty(std::string& name, glm::vec4 value);
	void OnGUI() override;
	glm::vec4 GetValue() override;
	void SetValue(glm::vec4& v) override;
};

class TextureProperty : public ShaderProperty<std::string> {
public:
	TextureProperty(std::string& name, std::string& texPath);
	void OnGUI() override;
	std::string GetValue() override;
	void SetValue(std::string& v) override;
};

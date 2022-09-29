#include "ShaderProperty.h"

VectorProperty::VectorProperty(std::string& name, glm::vec4 value):
	ShaderProperty<glm::vec4>(PropertyType::VECTOR, name, value) {
}

glm::vec4 VectorProperty::GetValue() {
	return mValue;
}

void VectorProperty::SetValue(glm::vec4& v) {
	mValue = v;
}

void VectorProperty::OnGUI() {

}


FloatProperty::FloatProperty(std::string& name, float value) :
	ShaderProperty<float>(PropertyType::FLOAT, name, value){
}

float FloatProperty::GetValue() {
	return mValue;
}

void FloatProperty::SetValue(float& v) {
	mValue = v;
}

void FloatProperty::OnGUI() {

}


ColorProperty::ColorProperty(std::string& name, glm::vec4 value) :
	ShaderProperty<glm::vec4>(PropertyType::COLOR, name, value) {
}

glm::vec4 ColorProperty::GetValue() {
	return mValue;
}

void ColorProperty::SetValue(glm::vec4& v) {
	mValue = v;
}


void ColorProperty::OnGUI() {

}

TextureProperty::TextureProperty(std::string& name, std::string& value) :
	ShaderProperty<std::string>(PropertyType::TEXTURE, name, value) {
}

std::string TextureProperty::GetValue() {
	return mValue;
}

void TextureProperty::SetValue(std::string& v) {
	mValue = v;
}

void TextureProperty::OnGUI() {

}


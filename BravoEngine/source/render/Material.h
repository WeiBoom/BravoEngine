#include <vector>
#include <memory>
#include "Shader.h"

class Material {

private:
	std::vector<FloatProperty> mFloatProperties;
	std::vector<VectorProperty> mVectorProperties;
	std::vector<ColorProperty> mColorProperties;
	std::vector<TextureProperty> mTextureProperties;

	std::shared_ptr<Shader> mShaderPtr;
public:
	Material(std::shared_ptr<Shader> shader);
	void OnGUI();
	
	// ��Ӱ��shader��Ĭ��ֵ
	void ApplyProperty();
};

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
	
	// 不影响shader的默认值
	void ApplyProperty();
};

#include "Material.h"

Material::Material(std::shared_ptr<Shader> shader):mShaderPtr(shader) {
	mShaderPtr->GetColorProperty(mColorProperties);
	mShaderPtr->GetVectorProperty(mVectorProperties);
	mShaderPtr->GetFloatProperty(mFloatProperties);
	mShaderPtr->GetTextureProperty(mTextureProperties);
}


void Material::OnGUI() {
	for (VectorProperty& vp : mVectorProperties) {
		vp.OnGUI();
	}
	for (ColorProperty& cp : mColorProperties) {
		cp.OnGUI();
	}
	for (FloatProperty& fp : mFloatProperties) {
		fp.OnGUI();
	}
	for (TextureProperty& tp : mTextureProperties) {
		tp.OnGUI();
	}
}

void Material::ApplyProperty() {
	mShaderPtr->ApplyProperty();
	for (VectorProperty& vp : mVectorProperties) {
		mShaderPtr->SetVec4Imp(vp.GetName(), vp.GetValue());
	}
	for (ColorProperty& cp : mColorProperties) {
		mShaderPtr->SetVec4Imp(cp.GetName(),cp.GetValue());
	}
	for (FloatProperty& fp : mFloatProperties) {
		mShaderPtr->SetFloatImp(fp.GetName(), fp.GetValue());
	}
}
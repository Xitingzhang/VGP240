#include "MatrixStack.h"


MatrixStack* MatrixStack::Get()
{
	static MatrixStack sInstance;
	return &sInstance;
}
void MatrixStack::OnNewFrame()
{
	mCombinedTransform = Matrix4::Identity();
	mMatrices.clear();
}
void MatrixStack::PushTranslation(const Vector3& d)
{
	Matrix4 translationMatrix = Matrix4::Translate(d);
	mMatrices.push_back(translationMatrix);
	mCombinedTransform = translationMatrix * mCombinedTransform;
}
void MatrixStack::PushRotationX(float radian)
{
	Matrix4 rotXMatrix = Matrix4::RotationX(radian);
	mMatrices.push_back(rotXMatrix);
	mCombinedTransform = rotXMatrix * mCombinedTransform;
}
void MatrixStack::PushRotationY(float radian)
{
	Matrix4 rotYMatrix = Matrix4::RotationY(radian);
	mMatrices.push_back(rotYMatrix);
	mCombinedTransform = rotYMatrix * mCombinedTransform;
}
void MatrixStack::PushRotationZ(float radian)
{
	Matrix4 rotZMatrix = Matrix4::RotationZ(radian);
	mMatrices.push_back(rotZMatrix);
	mCombinedTransform = rotZMatrix * mCombinedTransform;
}
void MatrixStack::PushScaling(const Vector3& s)
{
	Matrix4 scalingMatrix = Matrix4::Scale(s); 
	mMatrices.push_back(scalingMatrix);
	mCombinedTransform = scalingMatrix * mCombinedTransform;
}
void MatrixStack::PopMatrix()
{
	if (!mMatrices.empty())
	{
		Matrix4 matrix = mMatrices.back(); 
		mMatrices.pop_back();
		mCombinedTransform = MathHelper::Inverse(matrix) * mCombinedTransform; 
	}
		

}
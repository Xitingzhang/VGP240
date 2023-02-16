#pragma once

#include "MathHelper.h"
#include <vector>
class MatrixStack
{

public:
	static MatrixStack* Get();
	void OnNewFrame();
	void PushTranslation(const Vector3& d);
	void PushRotationX(float radian);
	void PushRotationY(float radian);
	void PushRotationZ(float radian);
	void PushScaling(const Vector3& s);
	void PopMatrix();
	const Matrix4& GetTransform() const { return mCombinedTransform; }
private:

	std::vector<Matrix4> mMatrices;
	Matrix4 mCombinedTransform; 
};
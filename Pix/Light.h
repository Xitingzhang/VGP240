#pragma once
#include"MathHelper.h"
#include "XColors.h"

class Light
{

public:
	virtual ~Light() = default;
	virtual X::Color ComputeLightColor(const Vector3& position, const Vector3& normal)const = 0;

	void SetAmbient(const X::Color color);
	void SetDiffuse(const X::Color color);
	void SetSpecular(const X::Color color);


	
private:
	X::Color mAmbient = X::Colors::White;
	X::Color mDiffuse = X::Colors::White;
	X::Color mSpecular = X::Colors::White;
};
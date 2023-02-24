#include "Light.h"

void Light::SetAmbient(const X::Color color)
{
	mAmbient = color;
}
void Light::SetDiffuse(const X::Color color)
{
	mDiffuse = color;
}
void Light::SetSpecular(const X::Color color)
{
	mSpecular = color;
}
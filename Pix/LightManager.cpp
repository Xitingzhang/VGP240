#include "LightManager.h"
#include "DirectionalLight.h"

LightManager* LightManager::Get()
{
	static LightManager sInstancce;
	return &sInstancce;
}
void LightManager::OnNewFrame()
{
	mLights.clear();
}
void LightManager::AddDirectionalLight(const Vector3& direction)
{
	auto light = std::make_unique<DirectionalLight>();
	light->SetDirection(direction);
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	mLights.emplace_back(std::move(light));
}
void LightManager::AddPointLight(const Vector3& position, float constant, float linear, float quadratic)
{

}
void LightManager::AddSpotLight(const Vector3& position, const Vector3& direction, float constant, float linear, float quadratic, float decay)
{

}
void LightManager::SetLightingAmbient(const X::Color& color)
{
	mAmbient = color;
}
void LightManager::SetLightingDiffuse(const X::Color& color)
{
	mAmbient = color;
}
void LightManager::SetLightingSpecular(const X::Color& color)
{
	mAmbient = color;
}
X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{
	if (mLights.empty())
	{
		return X::Colors::White;
	}
	X::Color color;
	for (auto& Light : mLights)
	{
		color += Light->ComputeLightColor(position, normal);
	}
	return color;
}
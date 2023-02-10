#include "Camera.h"
#include <math.h>


Camera* Camera::Get()
{
	static Camera sInstance;
	return &sInstance;
}

void Camera::OnNewFrame()
{
	mPosition = { 0.0f, 0.0f, 0.0f };
	mDirection = { 0.0f, 0.0f, 0.0f };
	mNearPlane = 0.01f;
	mFarPlane = 100.0f;
	mFOV = 1.57f;
}
void Camera::SetPosition(const Vector3 & position)
{
	mPosition = position;
}
void Camera::SetDirection(const Vector3& direction)
{
	mDirection = direction;
}
void Camera::SetNearPlane(float nearPlane)
{
	mNearPlane = nearPlane;
}
void Camera::SetFarPlane(float farPlane)
{
	mFarPlane = farPlane;
}
void Camera::SetFOV(float fov)
{
	mFOV = fov;
}

Matrix4 Camera::GetViewMatrix() const
{

}
Matrix4 Camera::GetProjectionMatrix() const
{

}
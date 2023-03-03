#include "Camera.h"
#include <math.h>
#include "MathHelper.h"

extern float gResolutionX;
extern float gResolutionY;


Camera* Camera::Get()
{
	static Camera sInstance;
	return &sInstance;
}

void Camera::OnNewFrame()
{
	mPosition = { 0.0f, 0.0f, 0.0f };
	mDirection = { 0.0f, 0.0f, 1.0f };
	mNearPlane = 0.01f;
	mFarPlane = 100.0f;
	mFOV = 1.57f;
}
void Camera::SetPosition(const Vector3& position)
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
	const Vector3 look = MathHelper::Normalize(mDirection);
	const Vector3 r = MathHelper::Normalize(MathHelper::Cross({ 0.0f, 1.0f, 0.0f }, look));
	const Vector3 u = MathHelper::Normalize(MathHelper::Cross(look, r));

	const float dx = -MathHelper::Dot(r, mPosition);
	const float dy = -MathHelper::Dot(u, mPosition);
	const float dz = -MathHelper::Dot(look, mPosition);

	return Matrix4(
		r.x, u.x, look.x, 0.0f,
		r.y, u.y, look.y, 0.0f,
		r.z, u.z, look.z, 0.0f,
		dx, dy, dz, 1.0f
	);
}
Matrix4 Camera::GetProjectionMatrix() const
{
	const float a = gResolutionX / gResolutionY;
	const float h = 1 / tanf(mFOV * 0.5f);
	const float w = h / a;

	const float d = mFarPlane / (mFarPlane - mNearPlane);
	return Matrix4(
		w, 0.0f, 0.0f, 0.0f,
		0.0f, h, 0.0f, 0.0f,
		0.0f, 0.0f, d, 1.0f,
		0.0f, 0.0f, -mNearPlane * d, 0.0f
	);
}
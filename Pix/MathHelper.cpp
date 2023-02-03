#include "MathHelper.h"
#include <cmath>

bool MathHelper::CheckEqual(float a, float b)
{
	return abs(a - b) < 0.01f;
}

float MathHelper::MagnitudeSquared(const Vector2& v)
{
	return v.x * v.x + v.y * v.y;
}
float MathHelper::MagnitudeSquared(const Vector3& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

float MathHelper::Magnitude(const Vector2& v)
{
	return sqrt(MagnitudeSquared(v));
}
float MathHelper::Magnitude(const Vector3& v)
{
	return sqrt(MagnitudeSquared(v));
}

Vector2 MathHelper::Normalize(const Vector2& v)
{
	return v / Magnitude(v);
}
Vector3 MathHelper::Normalize(const Vector3& v)
{
	return v / Magnitude(v);
}

float MathHelper::Dot(const Vector2& a, const Vector2& b)
{
	return (a.x * b.x)+ (a.y * b.y);
}

float MathHelper::Dot(const Vector3& a, const Vector3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}


Vector3 MathHelper::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}
Vector3 MathHelper::TransformCoord(const Vector3& v, const Matrix4& m)
{

}
Vector3 MathHelper::TransformNormal(const Vector3& v, const Matrix4& m)
{

}
float MathHelper::Determinant(const Matrix4 m)
{

}
Matrix4 MathHelper::Adjoint(const Matrix4& m) 
{

}
Matrix4 MathHelper::Transpose(const Matrix4& m) 
{
	return Matrix4(
		m._11, m._21, m._31, m._41,
		m._12, m._22, m._32, m._42,
		m._13, m._23, m._33, m._43,
		m._14, m._24, m._34, m._44
		);
}
Matrix4 MathHelper::Inverse(const Matrix4& m) 
{
	const float determinant = Determinant(m);
	const float invDet = 1.0f / determinant;
	return Adjoint(m) * invDet;
}
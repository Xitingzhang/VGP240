#include "Graphics.h"
#include "Camera.h"
#include "Clipper.h"
#include "DepthBuffer.h"
#include "LightManager.h"
#include "MaterialManager.h"
#include "MatrixStack.h"
#include "PrimitivesManager.h"
#include "Viewport.h"

void Graphics::NewFrame()
{
	Camera::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	DepthBuffer::Get()->OnNewFrame();
	LightManager::Get()->OnNewFrame();
	MaterialManager::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	PrimitivesManager::Get()->OnNewFrame();
	Viewport::Get()->OnNewFrame();
}
#include "Graphics.h"
#include "Camera.h"
#include "Clipper.h"
#include "DepthBuffer.h"
#include "MatrixStack.h"
#include "PrimitivesManager.h"
#include "Viewport.h"

void Graphics::NewFrame()
{
	Camera::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	DepthBuffer::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	PrimitivesManager::Get()->OnNewFrame();
	Viewport::Get()->OnNewFrame();
}
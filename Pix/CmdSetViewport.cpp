#include "CmdSetViewport.h"

#include "Viewport.h"

bool CmdSetViewport::Execute(const std::vector<std::string>& params)
{
	// Need at least 4 params for x, y, width, height
	if (params.size() < 4)
		return false;

	float x = stof(params[0]);
	float y = stof(params[1]);
	float width = stof(params[2]);
	float height = stof(params[3]);

	// Draw the pixel
	Viewport::Get()->SetViewport(x, y, width, height);
	return true;
}

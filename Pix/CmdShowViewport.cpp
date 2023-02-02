#include "CmdShowViewport.h"

#include "Viewport.h"

bool CmdShowViewport::Execute(const std::vector<std::string>& params)
{
	// Need at least 2 params for x, y
	if (params.size() < 1)
		return false;

	bool show = params[0] == "true";

	// Draw the pixel
	Viewport::Get()->ShowViewport(show);
	return true;
}

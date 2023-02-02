#include "CmdSetClipping.h"

#include "Clipper.h"

bool CmdSetClipping::Execute(const std::vector<std::string>& params)
{
	// Need at least 2 params for x, y
	if (params.size() < 1)
		return false;

	bool setClipping = params[0] == "true";

	// Draw the pixel
	Clipper::Get()->SetClipping(setClipping);
	return true;
}
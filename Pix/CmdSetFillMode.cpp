#include "CmdSetFillMode.h"
#include "Rasterizer.h"

bool CmdSetFillMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	FillMode fillMode = FillMode::Solid;
	if (params[0] == "solid") { fillMode = FillMode::Solid; }
	else if (params[0] == "wireframe") { fillMode = FillMode::Wireframe; }
	else { return false; }


	Rasterizer::Get()->SetFillMode(fillMode);
	return true;
}

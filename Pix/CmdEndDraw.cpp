#include "CmdEndDraw.h"
#include "PrimitivesManager.h"

bool CmdEndDraw::Execute(const std::vector<std::string>& params)
{
	if (params.size() > 0)
	{
		return false;
	}
	return PrimitivesManager::Get()->EndDraw();
}

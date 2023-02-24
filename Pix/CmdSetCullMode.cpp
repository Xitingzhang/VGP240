#include "CmdSetCullMode.h"
#include "PrimitivesManager.h"

bool CmdSetCullMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;
	CullMode cullMode = CullMode::Back;
	if (params[0] == "back") {
		cullMode = CullMode::Back;
	}
	else if (params[0] == "front") {
		cullMode = CullMode::Front;
	}
	else if (params[0] == "none") {
		cullMode = CullMode::None;
	}
	PrimitivesManager::Get()->SetCullMode(cullMode);
	return true;
}
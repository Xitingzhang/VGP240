#include "CmdPushRotationY.h"
#include "Variablecache.h"
#include "Matrixstack.h"
bool CmdPushRotationY::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;

	auto degree = VariableCache::Get()->GetFloat(params[0]);

	MatrixStack::Get()->PushRotationY(degree * 3.1416f / 180.0f);
	return true;
}
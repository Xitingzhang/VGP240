#include "CmdPushRotationX.h"
#include "MatrixStack.h"
#include "VariableCache.h"

#define PI 3.1415926

bool CmdPushRotationX::Execute(const std::vector<std::string>& params)
{
    if (params.size() != 1) {
        return false;
    }
    float radian;
    if (params[0][0] == '$') {
        radian = VariableCache::Get()->GetFloat(params[0]) * PI / 180;
    }
    else {
        radian = std::stof(params[0]) * PI / 180;
    }
    MatrixStack::Get()->PushRotationX(radian);
    return true;
}
#include "CmdPushScaling.h"
#include "MatrixStack.h"
#include "VariableCache.h"

bool CmdPushScaling::Execute(const std::vector<std::string>& params)
{
    if (params.size() != 3) {
        return false;
    }
    float sx, sy, sz;
    if (params[0][0] == '$') {
        sx = VariableCache::Get()->GetFloat(params[0]);
    }
    else {
        sx = std::stof(params[0]);
    }
    if (params[1][0] == '$') {
        sy = VariableCache::Get()->GetFloat(params[1]);
    }
    else {
        sy = std::stof(params[1]);
    }
    if (params[2][0] == '$') {
        sz = VariableCache::Get()->GetFloat(params[2]);
    }
    else {
        sz = std::stof(params[2]);
    }
    MatrixStack::Get()->PushScaling({ sx, sy, sz });
    return true;
}
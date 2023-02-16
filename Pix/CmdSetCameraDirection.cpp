#include "CmdSetCameraDirection.h"
#include "Camera.h"
#include "VariableCache.h"

bool CmdSetCameraDirection::Execute(const std::vector<std::string>& params)
{
    if (params.size() != 3) {
        return false;
    }
    float x, y, z;
    if (params[0][0] == '$') {
        x = VariableCache::Get()->GetFloat(params[0]);
    }
    else {
        x = std::stof(params[0]);
    }
    if (params[1][0] == '$') {
        y = VariableCache::Get()->GetFloat(params[1]);
    }
    else {
        y = std::stof(params[1]);
    }
    if (params[2][0] == '$') {
        z = VariableCache::Get()->GetFloat(params[2]);
    }
    else {
        z = std::stof(params[2]);
    }
    Camera::Get()->SetDirection({ x, y, z });
    return true;
}
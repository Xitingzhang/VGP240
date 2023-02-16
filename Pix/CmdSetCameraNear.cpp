#include "CmdSetCameraNear.h"
#include "Camera.h"

bool CmdSetCameraNear::Execute(const std::vector<std::string>& params)
{
    if (params.size() != 1) {
        return false;
    }
    float value;
    value = std::stof(params[0]);
    Camera::Get()->SetNearPlane(value);
    return true;
}
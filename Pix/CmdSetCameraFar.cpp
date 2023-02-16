#include "CmdSetCameraFar.h"
#include "Camera.h"

bool CmdSetCameraFar::Execute(const std::vector<std::string>& params)
{
    if (params.size() != 1) {
        return false;
    }
    float value;
    value = std::stof(params[0]);
    Camera::Get()->SetFarPlane(value);
    return true;
}
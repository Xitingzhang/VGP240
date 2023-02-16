#include "CmdSetCameraFov.h"
#include "Camera.h"

bool CmdSetCameraFov::Execute(const std::vector<std::string>& params)
{
    if (params.size() != 1) {
        return false;
    }
    float value;
    value = std::stof(params[0]);
    Camera::Get()->SetFOV(value);
    return true;
}
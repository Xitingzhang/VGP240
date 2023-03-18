#include "CmdMaterial.h"
#include "MaterialManager.h"
#include "VariableCache.h"

bool CmdSetMaterialAmbient::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 3)
        return false;

    auto vc = VariableCache::Get();
    float r = vc->GetFloat(params[0]);
    float g = vc->GetFloat(params[1]);
    float b = vc->GetFloat(params[2]);

    MaterialManager::Get()->SetMaterialAmbient({ r, g, b ,1.0f});
    return true;
}

bool CmdSetMaterialDiffuse::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 3)
        return false;

    auto vc = VariableCache::Get();
    float r = vc->GetFloat(params[0]);
    float g = vc->GetFloat(params[1]);
    float b = vc->GetFloat(params[2]);

    MaterialManager::Get()->SetMaterialDiffuse({ r, g, b ,1.0f });
    return true;
}

bool CmdSetMaterialSpecular::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 3)
        return false;

    auto vc = VariableCache::Get();
    float r = vc->GetFloat(params[0]);
    float g = vc->GetFloat(params[1]);
    float b = vc->GetFloat(params[2]);

    MaterialManager::Get()->SetMaterialSpecular({ r, g, b ,1.0f });
    return true;
}

bool CmdSetMaterialShininess::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
        return false;

    auto vc = VariableCache::Get();
    float shininess = vc->GetFloat(params[0]);
    MaterialManager::Get()->SetMaterialShininess(shininess);
    return true;
}


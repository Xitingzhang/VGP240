#include "CmdVertex.h"
#include "PrimitivesManager.h"

bool CmdVertex::Execute(const std::vector<std::string>& params)
{
	Vertex v;
	v.color.w = 1.0f;
	if(params.size() == 2)
	{
		v.pos.x = stof(params[0]);
		v.pos.y = stof(params[1]);
	}
	else if (params.size() == 3)
	{
		v.pos.x = stof(params[0]);
		v.pos.y = stof(params[1]);
		v.pos.z = stof(params[1]);
	}
	else if (params.size() == 5)
	{
		v.pos.x = stof(params[0]);
		v.pos.y = stof(params[1]);
		v.color.r = stof(params[2]);
		v.color.g = stof(params[3]);
		v.color.b = stof(params[4]);
	}
	else if (params.size() == 6)
	{
		v.pos.x = stof(params[0]);
		v.pos.y = stof(params[1]);
		v.pos.z = stof(params[2]);
		v.color.r = stof(params[3]);
		v.color.g = stof(params[4]);
		v.color.b = stof(params[5]);
	}
	else
	{
		return false;
	}
	

	PrimitivesManager::Get()->AddVertex(v);
	return true;

}
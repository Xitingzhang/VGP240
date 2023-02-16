#pragma once

#include "Command.h"
class CmdBeginDraw : public Command
{
public:
	const char* GetName()
	{
		return "BeginDraw";
	}
	const char* GetDescription()
	{
		return "BeginDraw(topology, applyTransform)begin drawing a primative";
	}

	bool Execute(const std::vector<std::string>& params);
};

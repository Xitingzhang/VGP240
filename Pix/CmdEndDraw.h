#pragma once
#include "Command.h"
class CmdEndDraw : public Command
{
public:
	const char* GetName()
	{
		return "EndDraw";
	}
	const char* GetDescription()
	{
		return "EndDraw() using the vertecies will draw the primitive";
	}

	bool Execute(const std::vector<std::string>& params);
};
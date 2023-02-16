#pragma once
#include "Command.h"

class CmdSetCameraNear :public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraNear";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraNear(value)\n"
			"\n"
			"- Set the near.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

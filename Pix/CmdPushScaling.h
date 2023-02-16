#pragma once
#include "Command.h"

class CmdPushScaling :public Command
{
public:
	const char* GetName() override
	{
		return "PushScaling";
	}

	const char* GetDescription() override
	{
		return
			"PushScaling(sx, sy, sz)\n"
			"\n"
			"- Push a PushScaling matrix.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
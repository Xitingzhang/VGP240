#pragma once
#include "Command.h"

class CmdSetCameraFov :public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFov";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraFov(value)\n"
			"\n"
			"- Set the Fov.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
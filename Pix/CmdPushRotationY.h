#pragma once
#include "Command.h"
class CmdPushRotationY : public Command
{
public:

	const char* GetName() override
	{
		return "PushRotationY";
	}

	const char* GetDescription() override
	{
		return

			"PushRotationY(radians)\n"
			"- Pushes a rotation in the y axis into the matrix stack (rad).";

	}
	bool Execute(const std::vector<std::string>& params) override;

};
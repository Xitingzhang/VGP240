#pragma once
#include "Command.h"
class CmdPushRotationX : public Command
{
public:

	const char* GetName() override
	{
		return "PushRotationX";
	}

	const char* GetDescription() override
	{
		return

			"PushRotationX(radians)\n"
			"- Pushes a rotation in the x axis into the matrix stack (rad).";

	}
	bool Execute(const std::vector<std::string>& params) override;

};

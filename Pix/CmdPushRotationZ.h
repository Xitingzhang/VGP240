#pragma once
#include "Command.h"
class CmdPushRotationZ : public Command
{
public:

	const char* GetName() override
	{
		return "PushRotationZ";
	}

	const char* GetDescription() override
	{
		return

			"PushRotationZ(radians)\n"
			"- Pushes a rotation in the z axis into the matrix stack (rad).";

	}
	bool Execute(const std::vector<std::string>& params) override;

};

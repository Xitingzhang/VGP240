#pragma once

#include "Command.h"

class CmdVertex : public Command
{
public:
	const char* GetName()
	{
		return "Vertex";
	}
	const char* GetDescription()
	{
		return "Vertex(x, y)\n"
			"Vertex(x, y)\n"
			"Vertex(x, y,x)\n"
			"Vertex(x, y,r,g,b)\n"
			"Vertex(x, y,z,r,g,b)\n";
			
	}

	bool Execute(const std::vector<std::string>& params);




};

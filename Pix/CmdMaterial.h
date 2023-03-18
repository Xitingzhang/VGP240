#pragma once

#include "Command.h"

class CmdSetMaterialAmbient :public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialAmbient";
	}

	const char* GetDescription() override
	{
		return
			"SetMaterialAmbient(r, g, b)\n";
			
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialDiffuse :public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"SetMaterialDiffuse(r, g, b)\n";

	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialSpecular :public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialSpecular";
	}

	const char* GetDescription() override
	{
		return
			"SetMaterialSpecular(r, g, b)\n";

	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialShininess :public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialShininess";
	}

	const char* GetDescription() override
	{
		return
			"SetMaterialShininess(shininess)\n";

	}

	bool Execute(const std::vector<std::string>& params) override;
};


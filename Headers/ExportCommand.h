#pragma once
#include "ICommand.h"
#include "System.h"

class ExportCommand : public ICommand
{
public:
	ExportCommand(System& receiver);

	void execute(const std::vector<std::string>& args) override;
};


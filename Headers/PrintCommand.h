#pragma once
#include "ICommand.h"
#include "System.h"

class PrintCommand : public ICommand
{
public:
	PrintCommand(System& receiver);
	void execute(const std::vector<std::string>& args) override;
};


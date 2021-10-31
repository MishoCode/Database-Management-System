#pragma once
#include "ICommand.h"
class DropTableCommand :public ICommand
{
public:
	DropTableCommand(System& receiver);
	void execute(const std::vector<std::string>& args) override;
};


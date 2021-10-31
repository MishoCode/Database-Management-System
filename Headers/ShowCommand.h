#pragma once
#include "ICommand.h"

class ShowCommand : public ICommand
{
public:
	ShowCommand(System& receiver);
	void execute(const std::vector<std::string>& args) override;
};


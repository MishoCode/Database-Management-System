#pragma once
#include "ICommand.h"
#include "System.h"

class InsertCommand : public ICommand
{
public:
	InsertCommand(System& receiver);

	void execute(const std::vector<std::string>& args) override;
};


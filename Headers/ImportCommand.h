#pragma once
#include "ICommand.h"
#include<vector>
#include<string>

class ImportCommand : public ICommand
{
public:
	ImportCommand(System& receiver);
	void execute(const std::vector<std::string>& args) override;
};


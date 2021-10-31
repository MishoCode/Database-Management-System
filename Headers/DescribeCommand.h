#pragma once
#include "ICommand.h"
#include "System.h"

class DescribeCommand : public ICommand
{
public:
	DescribeCommand(System& receiver);
	void execute(const std::vector<std::string>& args) override;
};


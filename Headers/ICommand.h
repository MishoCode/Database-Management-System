#pragma once
#include"System.h"
#include<vector>
#include<string>

class ICommand {
protected:
	System& receiver;
public:
	ICommand(System& receiver);

	virtual void execute(const std::vector<std::string>& args) = 0;
};

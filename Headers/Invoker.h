#pragma once
#include "ICommand.h"
#include "System.h"
#include<vector>
#include<string>
#include<unordered_map>

class Invoker {
private:
	std::unordered_map<std::string, ICommand*> commands;
	System receiver;

	void initializeCommands();
public:
	Invoker(System& receiver);

	void execute(const std::vector<std::string>& tokens);
};

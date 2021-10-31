#include "../Headers/Invoker.h"
#include "../Headers/ImportCommand.h"
#include "../Headers/ShowCommand.h"
#include "../Headers/DescribeCommand.h"
#include "../Headers/PrintCommand.h"
#include "../Headers/ExportCommand.h"
#include "../Headers/InsertCommand.h"
#include "../Headers/DropTableCommand.h"
#include<iostream>

void Invoker::initializeCommands()
{
	commands.insert({ "import", new ImportCommand(receiver) });
	commands.insert({ "showtables", new ShowCommand(receiver) });
	commands.insert({ "describe", new DescribeCommand(receiver) });
	commands.insert({ "print", new PrintCommand(receiver) });
	commands.insert({ "export", new ExportCommand(receiver) });
	commands.insert({ "insert", new InsertCommand(receiver) });
	commands.insert({ "drop", new DropTableCommand(receiver) });
}

Invoker::Invoker(System& receiver)
{
	this->receiver = receiver;
	initializeCommands();
}

void Invoker::execute(const std::vector<std::string>& tokens)
{
	if (commands.find(tokens[0]) == commands.end()) {
		std::cout << "Invalid command!" << std::endl;
	}
	else {
		std::vector<std::string> arguments(tokens.begin() + 1, tokens.end());
		//std::cout << arguments[0] << std::endl;
		commands[tokens[0]]->execute(arguments);
	}
}

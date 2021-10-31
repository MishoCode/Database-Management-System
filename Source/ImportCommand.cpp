#include "../Headers/ImportCommand.h"
#include "../Headers/TableLoader.h"
#include<iostream>

ImportCommand::ImportCommand(System& receiver)
	:ICommand(receiver)
{
}

void ImportCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 1) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		TableLoader tableLoader(args[0]);
		receiver.process(tableLoader);
	}
}

#include "../Headers/DropTableCommand.h"
#include "../Headers/TableRemover.h"

DropTableCommand::DropTableCommand(System& receiver)
	:ICommand(receiver)
{
}

void DropTableCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 1) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		TableRemover tableRemover(args[0]);
		receiver.process(tableRemover);
	}
}

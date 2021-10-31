#include "../Headers/PrintCommand.h"
#include "../Headers/TableContentPrinter.h"

PrintCommand::PrintCommand(System& receiver)
	:ICommand(receiver)
{
}

void PrintCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 1) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		TableContentPrinter rowsPrinter(args[0]);
		receiver.process(rowsPrinter);
	}
}

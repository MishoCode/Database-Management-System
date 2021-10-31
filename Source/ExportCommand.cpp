#include "../Headers/ExportCommand.h"
#include "../Headers/TablePrinter.h"

ExportCommand::ExportCommand(System& receiver)
	:ICommand(receiver)
{
}

void ExportCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 2) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		TablePrinter tablePrinter(args[1], args[0]);
		receiver.process(tablePrinter);
	}
}

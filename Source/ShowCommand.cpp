#include "../Headers/ShowCommand.h"
#include "../Headers/TablesInfoPrinter.h"

ShowCommand::ShowCommand(System& receiver)
	:ICommand(receiver)
{
}

void ShowCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 0) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		TablesInfoPrinter tablesInfoPrinter;
		receiver.process(tablesInfoPrinter);
	}
}

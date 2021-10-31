#include "../Headers/DescribeCommand.h"
#include "../Headers/ColumnsInfoPrinter.h"

DescribeCommand::DescribeCommand(System& receiver)
	:ICommand(receiver)
{
}

void DescribeCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 1) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		ColumnsInfoPrinter columnsInfoPrinter(args[0]);
		receiver.process(columnsInfoPrinter);
	}
}

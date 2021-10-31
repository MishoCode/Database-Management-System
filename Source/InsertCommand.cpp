#include "../Headers/InsertCommand.h"
#include "../Headers/RowInserter.h"
#include "../Headers/Parser.h"
#include "../Headers/NullValue.h"

InsertCommand::InsertCommand(System& receiver)
	:ICommand(receiver)
{
}

void InsertCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() == 0) {
		std::cout << "Invalid number of arguments!" << std::endl;
	}
	else {
		RowInserter rowInserter(args);
		receiver.process(rowInserter);
	}
}

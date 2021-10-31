#include "../Headers/TablesInfoPrinter.h"

TablesInfoPrinter::TablesInfoPrinter()
{}

void TablesInfoPrinter::visit(System& system, Table* t)
{
	std::unordered_map<std::string, Table*> tables = system.getTables();
	if (tables.empty()) {
		std::cout << "No tables found!" << std::endl;
		return;
	}
	for (auto p : tables) {
		std::cout << p.first << std::endl;
	}
}

const std::string* TablesInfoPrinter::getTableName() const
{
	return nullptr;
}


#include "../Headers/TableRemover.h"
#include "../Headers/System.h"

TableRemover::TableRemover(const std::string& tableName)
{
	this->tableName = tableName;
}

void TableRemover::visit(System& system, Table* t)
{
	std::unordered_map<std::string, Table*>& tables = system.getTables();
	tables.erase(tableName);
	std::cout << "The table " << t->getName() << " was removed!" << std::endl;
}

const std::string* TableRemover::getTableName() const
{
	return &tableName;
}

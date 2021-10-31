#include "../Headers/System.h"
#include "../Headers/ColumnsInfoPrinter.h"
#include "../Headers/Parser.h"

void ColumnsInfoPrinter::visit(System& system, Table* t)
{
	std::vector<Column*> columns = t->getColumns();
	for (Column* c : columns) {
		std::cout << Parser::extractName(c->getName()) << " : " << toString(c->getType()) << std::endl;
	}
}

ColumnsInfoPrinter::ColumnsInfoPrinter(const std::string& tableName)
{
	this->tableName = tableName;
}

const std::string* ColumnsInfoPrinter::getTableName() const
{
	return &tableName;
}

#include "../Headers/TableContentPrinter.h"
#include "../Headers/NullValue.h"
#include<iomanip>

void TableContentPrinter::visit(System& system, Table* t)
{
	printTableRows(*t);
}

const std::string* TableContentPrinter::getTableName() const
{
	return &tableName;
}

void TableContentPrinter::printTableRows(Table& table, std::ostream& out)
{
	std::vector<Column*> columns = table.getColumns();

	int i = 0;
	for (int j = 0; j < table.getRowsCount(); j++) {
		for (Column* c : columns) {
			Value* v = c->at(j);
			/*if (v == nullptr) {
				v = new NullValue();
			}*/

			int padding = c->getMaxWidth() - (v->toString().size()) + 1;
			out << v->toString() << std::setw(padding) << '|';
		}
		i++;
		out << std::endl;
	}
}

TableContentPrinter::TableContentPrinter(const std::string& tableName)
{
	this->tableName = tableName;
}

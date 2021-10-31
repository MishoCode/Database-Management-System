#include "../Headers/TablePrinter.h"
#include "../Headers/TableContentPrinter.h"
#include<fstream>
#include<iostream>
#include<iomanip>

int TablePrinter::exportedCount = 0;
bool TablePrinter::exported = false;

std::string TablePrinter::createExportedName(const std::string& tableName)
{
	exportedCount++;
	std::string exportedName = tableName;
	std::string num = std::to_string(exportedCount);
	if (exported) {
		size_t index = exportedName.find_last_of('_');
		exportedName.erase(exportedName.begin() + index + 1, exportedName.end());
		return exportedName += num;
	}

	exported = true;
	return (exportedName += '_') + num;
}

TablePrinter::TablePrinter(const std::string& filename, const std::string& tableName)
{
	this->filename = filename;
	this->tableName = tableName;
}

void TablePrinter::visit(System& system, Table* t)
{
	printTable(*t);
}

const std::string* TablePrinter::getTableName() const
{
	return &tableName;
}

void TablePrinter::printTable(Table& table)
{
	std::ofstream file(filename);
	file << createExportedName(table.getName()) << std::endl;

	std::vector<int> lengths;

	std::vector<Column*> columns = table.getColumns();
	for (Column* c : columns) {
		int maxWidth = c->getMaxWidth();
		lengths.push_back(maxWidth);
		int padding = c->getMaxWidth() - c->getName().size() + 1;
		file << c->getName() << std::setw(padding) << '|';
	}
	file << std::endl;

	for (int i = 0; i < lengths.size(); i++) {
		for (int j = 0; j < lengths[i]; j++) {
			file << '-';
		}
		file << '+';
	}
	file << std::endl;

	TableContentPrinter rowsPrinter(table.getName());
	rowsPrinter.printTableRows(table, file);
	std::cout << "The table " << tableName << " was exported!" << std::endl;

	file.close();
}



#include "../Headers/TableLoader.h"
#include "../Headers/Parser.h"
#include "../Headers/StringUtils.h"
#include<fstream>

TableLoader::TableLoader(const std::string& filename)
{
	this->filename = filename;
}

void TableLoader::loadTable(Table& table)
{
	std::ifstream file(filename);
	std::pair<std::string, std::vector<Column*>> tableHeader = readColumnNames(file);
	std::string tableName = tableHeader.first;
	std::vector<Column*> columns = tableHeader.second;

	std::string value;
	std::string line;
	while (getline(file, line)) {
		std::vector<std::string> tokens = StringUtils::split(line, '|');
		std::vector<Value*> values = Parser::parseValues(tokens);
		for (int i = 0; i < values.size(); i++) {
			if (!columns[i]->add(values[i])) {
				file.close();
				return;
			}
		}
	}

	Table t(columns, table.getName());
	table = t;

	file.close();

	std::cout << t.getRowsCount() << std::endl;
}

void TableLoader::visit(System& system, Table* t)
{
	std::ifstream file(filename);
	if (!file) {
		std::cout << "Invalid file name!" << std::endl;
		return;
	}

	std::string tableName;
	file >> tableName;
	std::unordered_map<std::string, Table*>& tables = system.getTables();
	if (tables.find(tableName) != tables.end()) {
		std::cout << "This table already exists!" << std::endl;
	}
	else {
		Table* t = new Table(tableName);
		this->loadTable(*t);
		tables.insert({ tableName,t });
		std::cout << "The table " << tableName << " was imported!" << std::endl;
	}
	file.close();
}

const std::string* TableLoader::getTableName() const
{
	return nullptr;
}

std::pair<std::string, std::vector<Column*>> TableLoader::readColumnNames(std::istream& in)
{
	std::string tableName;
	in >> tableName;

	in.ignore();

	std::vector<Column*> columns;
	std::string currentName;
	while (getline(in, currentName, '|')) {
		ColumnType type = Parser::extractType(currentName);
		columns.push_back(new Column(currentName,type));
		if (in.peek() == '\n') {
			break;
		}
	}

	std::string line;
	in >> line;

	return std::make_pair(tableName, columns);
}

#include "../Headers/System.h"
#include<iostream>

Table* System::findTable(const std::string& tableName) const
{
	if (tables.find(tableName) == tables.end()) {
		std::cout << "This table does not exist!" << std::endl;
		return nullptr;
	}

	return tables.at(tableName);
}

std::unordered_map<std::string, Table*>& System::getTables()
{
	return tables;
}


void System::process(Visitor& visitor)
{
	Table* t = nullptr;
	if (visitor.getTableName() != nullptr) {
		t = findTable(*visitor.getTableName());
		if (t == nullptr) {
			return;
		}	
	}

	visitor.visit(*this, t);
}



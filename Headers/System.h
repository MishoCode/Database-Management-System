#pragma once
#include "Table.h"
#include<string>
#include<unordered_map>

class System
{
private:
	std::unordered_map<std::string, Table*> tables;
public:
	Table* findTable(const std::string& tableName) const;
	std::unordered_map<std::string, Table*>& getTables();
	void process(Visitor& visitor);
};


#pragma once
#include "Visitor.h"
#include "Table.h"
#include "System.h"
#include<string>

class TableLoader : public Visitor
{
public:
	TableLoader(const std::string& filename);

	void loadTable(Table& t);

	void visit(System& system, Table* t) override;

	const std::string* getTableName() const override;
private:
	std::string filename;

	std::pair<std::string, std::vector<Column*>> readColumnNames(std::istream& in);
};


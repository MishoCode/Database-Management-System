#pragma once
#include "Visitor.h"
#include "System.h"
#include<string>

class TableContentPrinter : public Visitor
{
public:
	void visit(System& system, Table* t) override;

	const std::string* getTableName() const override;

	void printTableRows(Table& table, std::ostream& out = std::cout);

	TableContentPrinter(const std::string& tableName);

private:
	std::string tableName;
};


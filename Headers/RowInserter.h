#pragma once
#include "Value.h"
#include "Visitor.h"
#include "Table.h"
#include "System.h"
#include<vector>

class RowInserter : public Visitor
{
private:
	std::vector<Value*> values;
	std::vector<std::string> args;
	std::string tableName;

	void clearLastRow(std::vector<Column*>& columns, int lastColumn);
public:
	RowInserter(const std::vector<Value*>& values);
	RowInserter(const std::vector<std::string>& args);

	std::vector<Value*> getValues(int maxColumns);

	//void visit(Table& table) override;
	void visit(System& system, Table* t) override;

	const std::string* getTableName() const override;
};


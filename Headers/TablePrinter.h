#pragma once
#include "Visitor.h"
#include "Table.h"
#include "System.h"
#include<iostream>

class TablePrinter : public Visitor
{
private:
	std::string filename;
	std::string tableName;

	static bool exported;
	static int exportedCount;

	std::string createExportedName(const std::string& tableName);
	void printTable(Table& table);
public:
	TablePrinter(const std::string& filename, const std::string& tableName);

	void visit(System& system, Table* t) override;

	const std::string* getTableName() const override;
};


#pragma once
#include "Visitor.h"
#include "System.h"

class ColumnsInfoPrinter : public Visitor
{
public:
	void visit(System& system, Table* t) override;

	ColumnsInfoPrinter(const std::string& tableName);

	const std::string* getTableName() const override;
private:
	std::string tableName;
};


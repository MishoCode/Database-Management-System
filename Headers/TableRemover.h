#pragma once
#include "Visitor.h"
#include<string>

class TableRemover : public Visitor
{
public:
	TableRemover(const std::string& tableName);

	void visit(System& system, Table* t) override;

	const std::string* getTableName() const override;
private:
	std::string tableName;
};


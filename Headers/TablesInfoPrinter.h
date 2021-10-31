#pragma once
#include "Visitor.h"
#include "System.h"

class TablesInfoPrinter : public Visitor
{
public:
	TablesInfoPrinter();

	void visit(System& system, Table* t) override;

	const std::string* getTableName() const override;
};


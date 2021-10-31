#pragma once
#include<string>

class Column;
class Table;
class System;

class Visitor
{
public:
	virtual void visit(System& system, Table* t) = 0;
	virtual const std::string* getTableName() const = 0;
};


#pragma once
#include "ColumnType.h"
#include "Visitor.h"
#include "Value.h"
#include<string>
#include<vector>

class Visitor;

class Column
{
public:
	Column(const std::string& name);
	Column(const std::string& name, const ColumnType& type);
	Column(const std::string& name, const std::vector<Value*>& values);

	std::string getName() const;
	std::vector<Value*>& getValues();
	ColumnType getType() const;
	int getMaxWidth() const;
	int getSize() const;

	Value* at(int i);

	void setType(ColumnType type);
	
	bool add(Value* v);
	void popBack();

private:
	std::string name;
	ColumnType type;
	std::vector<Value*> values;
};



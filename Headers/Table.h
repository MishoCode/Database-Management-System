#pragma once
#include<vector>
#include<string>
#include "Column.h"

class Table
{
public:
	Table(const std::string& name);
	Table(const std::vector<Column*>& columns, const std::string& name);

	//void accept(Visitor* visitor);

	std::vector<Column*>& getColumns();
	std::string getName() const;
	int getRowsCount() const;

	void setRowsCount();
	void setColumns(const std::vector<Column*>& columns);
	void setName(const std::string& name);
	

private:
	std::vector<Column*> columns;
	std::string name;
	int rowsCount;
};


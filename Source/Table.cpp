#include "../Headers/Table.h"

Table::Table(const std::string& name)
{
	this->name = name;
}

Table::Table(const std::vector<Column*>& columns, const std::string& name)
{
	this->columns = columns;
	this->name = name;
	rowsCount = columns.empty() ? 0 : columns.front()->getSize();
}

std::vector<Column*>& Table::getColumns()
{
	return columns;
}

std::string Table::getName() const
{
	return name;
}

void Table::setRowsCount()
{
	rowsCount++;
}

void Table::setColumns(const std::vector<Column*>& columns)
{
	this->columns = columns;
}

void Table::setName(const std::string& name)
{
	this->name = name;
}

int Table::getRowsCount() const
{
	return rowsCount;
}

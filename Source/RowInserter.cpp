#include "../Headers/RowInserter.h"
#include "../Headers/Parser.h"
#include "../Headers/NullValue.h"

void RowInserter::clearLastRow(std::vector<Column*>& columns, int lastColumn)
{
	for (int i = 0; i < lastColumn; i++) {
		columns[i]->popBack();
	}
}

RowInserter::RowInserter(const std::vector<Value*>& values)
{
	this->values = values;
}

RowInserter::RowInserter(const std::vector<std::string>& args) {
	this->args = args;
	if (!args.empty()) {
		tableName = args.front();
	}
}

std::vector<Value*> RowInserter::getValues(int maxColumns)
{
	std::vector<std::string> strValues{ args.begin() + 1,args.end() };
	std::vector<Value*> values;
	for (int i = 0; i < strValues.size(); i++) {
		//std::cout << strValues[i] << std::endl;
		Value* v = Parser::getValue(strValues[i]);
		if (v != nullptr) {
			std::cout << v->toString() << std::endl;
			values.push_back(v);
		}
	}

	int j = strValues.size();
	while (j < maxColumns) {
		values.push_back(new NullValue());
		j++;
	}

	return values;
}

void RowInserter::visit(System& system, Table* t)
{
	values = getValues(t->getColumns().size());
	std::vector<Column*> columns = t->getColumns();
	int i = 0;
	for (Value* v : values) {
		if (!columns[i]->add(v)) {
			clearLastRow(columns, i);
			return;
		}

		i++;
	}

	t->setRowsCount();
}

const std::string* RowInserter::getTableName() const
{
	return &tableName;
}

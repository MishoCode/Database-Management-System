#include "../Headers/Column.h"

Column::Column(const std::string& name)
{
	this->name = name;
}

Column::Column(const std::string& name, const ColumnType& type)
{
	this->name = name;
	this->type = type;
}

Column::Column(const std::string& name, const std::vector<Value*>& values)
{
	this->name = name;
	this->values = values;
}

std::string Column::getName() const
{
	return name;
}

std::vector<Value*>& Column::getValues()
{
	return values;
}

ColumnType Column::getType() const
{
	return type;
}

int Column::getMaxWidth() const
{
	int maxWidth = 0;
	for (Value* v : values) {
		if (v->getWidth() > maxWidth) {
			maxWidth = v->getWidth();
		}
	}

	return name.size() > maxWidth ? name.size() : maxWidth;
}

int Column::getSize() const
{
	return values.size();
}

void Column::setType(ColumnType type)
{
	if (this->type != type && type != ColumnType::NO_TYPE) {
		std::cout << "The column " << this->name << " cannot store data of " << toString(type) << " type!";
		return;
	}
	this->type = type;
}

Value* Column::at(int i)
{
	if (i >= values.size() || i < 0) {
		return nullptr; //throw exception
	}
	return values[i];
}

bool Column::add(Value* v)
{
	if (v->getType() == this->type || v->getType() == ColumnType::NO_TYPE) {
		values.push_back(v);
		return true;
	}
	else {
		std::cout << "All values in the column must be the same type!" << std::endl;
		return false;
	}
}

void Column::popBack()
{
	//throw exception
	values.pop_back();
}


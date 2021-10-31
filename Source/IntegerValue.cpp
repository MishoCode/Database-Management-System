#include "../Headers/IntegerValue.h"

int IntegerValue::getWidth()
{
	return this->toString().size();
}

std::string IntegerValue::toString()
{
	return std::to_string(data);
}


IntegerValue::IntegerValue(int data)
{
	this->data = data;
	this->type = ColumnType::INTEGER;
}


ColumnType IntegerValue::getType()
{
	return this->type;
}

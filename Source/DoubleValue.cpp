#include "../Headers/DoubleValue.h"
#include "../Headers/ColumnType.h"
#include<sstream>

int DoubleValue::getWidth()
{
	return this->toString().size();
}

std::string DoubleValue::toString()
{
	return std::to_string(data);
}

ColumnType DoubleValue::getType()
{
	return this->type;
}

DoubleValue::DoubleValue(double data)
{
	this->data = data;
	this->type = ColumnType::DOUBLE;
}

#include "../Headers/BooleanValue.h"
#include "../Headers/ColumnType.h"

int BooleanValue::getWidth()
{
	return this->toString().size();
}

std::string BooleanValue::toString()
{
	return data ? "true" : "false";
}

ColumnType BooleanValue::getType()
{
	return this->type;
}

BooleanValue::BooleanValue(bool data)
{
	this->type = ColumnType::BOOLEAN;
	this->data = data;
}

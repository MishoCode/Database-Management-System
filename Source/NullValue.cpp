#include "../Headers/NullValue.h"
#include "../Headers/ColumnType.h"

NullValue::NullValue()
{
	this->type = ColumnType::NO_TYPE;
}

int NullValue::getWidth()
{
	return 4;
}

std::string NullValue::toString()
{
	return "NULL";
}


ColumnType NullValue::getType()
{
	return this->type;
}

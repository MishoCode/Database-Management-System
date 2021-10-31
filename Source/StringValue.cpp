#include "../Headers/StringValue.h"
#include "../Headers/ColumnType.h"

int StringValue::getWidth()
{
	return data.size();
}

std::string StringValue::toString()
{
	return data;
}

ColumnType StringValue::getType()
{
	return this->type;
}

StringValue::StringValue(const std::string& data)
{
	this->data = data;
	this->type = ColumnType::STRING;
}

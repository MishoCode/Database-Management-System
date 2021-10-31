#pragma once
#include "Value.h"
class StringValue : public Value
{
public:
	int getWidth() override;
	std::string toString() override;
	ColumnType getType() override;

	StringValue(const std::string& data);
private:
	std::string data;
};


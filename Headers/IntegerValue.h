#pragma once
#include "Value.h"
#include "ColumnType.h"
class IntegerValue : public Value
{
public:
	int getWidth() override;
	std::string toString() override;
	ColumnType getType() override;

	IntegerValue(int data);
private:
	int data;
};


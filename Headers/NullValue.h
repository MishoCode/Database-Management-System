#pragma once
#include "Value.h"
class NullValue : public Value
{
public:
	int getWidth() override;
	std::string toString() override;
	ColumnType getType() override;

	NullValue();
};


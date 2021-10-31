#pragma once
#include "Value.h"
class BooleanValue : public Value
{
public:
	int getWidth() override;
	std::string toString() override;
	ColumnType getType() override;

	BooleanValue(bool data);
private:
	bool data;
};


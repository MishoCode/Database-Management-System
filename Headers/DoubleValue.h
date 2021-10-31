#pragma once
#include "Value.h"

class DoubleValue : public Value
{
public:
	int getWidth() override;
	std::string toString() override;
	ColumnType getType() override;

	DoubleValue(double data);
private:
	double data;
};


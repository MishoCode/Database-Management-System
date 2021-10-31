#pragma once
#include<string>
#include<iostream>

enum class ColumnType;

class Value {
public:
	virtual int getWidth() = 0;
	virtual std::string toString() = 0;
	virtual ColumnType getType() = 0;
protected:
	ColumnType type;
};

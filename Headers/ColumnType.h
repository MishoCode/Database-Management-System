#pragma once
#include<string>

enum class ColumnType
{
	INTEGER, NO_TYPE, DOUBLE, STRING, BOOLEAN
};

static std::string toString(ColumnType type) {
	int number = static_cast<int>(type);
	switch (number) {
	case 0:return "Integer";
	case 1:return "NULL";
	case 2:return "Double";
	case 3:return "String";
	case 4:return "Boolean";
	}
}


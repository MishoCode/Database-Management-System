#pragma once
#include"Value.h"
#include<vector>

class Parser
{
private:
	static bool isInteger(const std::string& str);
	static bool isNull(std::string& str);
	static bool isDouble(std::string& str);
	static bool isString(std::string& str);
	static bool isBoolean(std::string& str);
	static ColumnType convertToColumnType(const std::string& str);
public:
	static Value* getValue(std::string& str);
	static std::vector<Value*> parseValues(std::vector<std::string>& values);
	static ColumnType extractType(const std::string& str);
	static std::string extractName(const std::string& str);
};


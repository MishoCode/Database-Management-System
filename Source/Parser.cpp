#include "../Headers/Parser.h"
#include "../Headers/StringUtils.h"
#include "../Headers/IntegerValue.h"
#include "../Headers/NullValue.h"
#include "../Headers/DoubleValue.h"
#include "../Headers/StringValue.h"
#include "../Headers/BooleanValue.h"
#include<regex>

//#include<algorithm>

bool Parser::isInteger(const std::string& str)
{
	/*std::regex pattern("(\\+|-)?[[:digit:]]+");
	return std::regex_match(str, pattern);*/

	for (char c : str) {
		if (c <= 32) {
			return true;
		}
		if (!isdigit(c)) {
			return false;
		}
	}

	return true;
}

bool Parser::isNull(std::string& str)
{
	str = StringUtils::rtrim(str);
	return str == "NULL";
}

bool Parser::isDouble(std::string& str)
{
	str = StringUtils::rtrim(str);
	if (!std::isdigit(str.front())) {
		return false;
	}

	bool decimalPointFound = false;
	for (char c : str) {
		if (!std::isdigit(c) && !decimalPointFound) {
			if (c == '.') {
				decimalPointFound = true;
				continue;
			}
			else {
				return false;
			}

		}
		else if (!std::isdigit(c) && decimalPointFound) {
			return false;
		}
	}

	if (!decimalPointFound) {
		return false;
	}

	return true;
}

bool Parser::isString(std::string& str)
{
	str = StringUtils::rtrim(str);
	return str.front() == '"' && str.back() == '"';
}

bool Parser::isBoolean(std::string& str)
{
	str = StringUtils::rtrim(str);
	return str == "true" || str == "false";
}

ColumnType Parser::convertToColumnType(const std::string& str)
{
	if (str == "INT") {
		return ColumnType::INTEGER;
	}
	else if (str == "DOUBLE") {
		return ColumnType::DOUBLE;
	}
	else if (str == "STRING") {
		return ColumnType::STRING;
	}
	else if (str == "BOOLEAN") {
		return ColumnType::BOOLEAN;
	}
	
	return ColumnType::NO_TYPE;
}

Value* Parser::getValue(std::string& str)
{
	if (isInteger(str)) {
		return new IntegerValue(stoi(str));
	}
	else if (isNull(str)) {
		return new NullValue();
	}
	else if (isDouble(str)) {
		return new DoubleValue(stod(str));
	}
	else if (isString(str)) {
		return new StringValue(str);
	}
	else if (isBoolean(str)) {
		if (str == "true") {
			return new BooleanValue(true);
		}
		else {
			return new BooleanValue(false);
		}
	}

	return nullptr;
}

std::vector<Value*> Parser::parseValues(std::vector<std::string>& values)
{
	std::vector<Value*> result;
	for (int i = 0; i < values.size(); i++) {
		Value* v = getValue(values[i]);
		if (v != nullptr) {
			result.push_back(v);
		}
	}

	return result;
}

ColumnType Parser::extractType(const std::string& str)
{
	int i = str.find('(');
	if (i == -1) {
		throw std::runtime_error("Invalid table serialization!");
	}

	std::string type;
	for (int j = i+1; j < str.size()-1; j++) {
		type += str[j];
	}

	return convertToColumnType(type);
}

std::string Parser::extractName(const std::string& str)
{
	int i = str.find('(');
	return str.substr(0, i);
}

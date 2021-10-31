#pragma once
#include<vector>
#include<string>

class StringUtils
{
public:
	static std::vector<std::string> split(const std::string& line, char delimiter = ' ');
	static std::string rtrim(std::string& str);
};


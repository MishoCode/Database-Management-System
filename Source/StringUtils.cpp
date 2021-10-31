#include "../Headers/StringUtils.h"
#include<sstream>

std::vector<std::string> StringUtils::split(const std::string& line, char delimiter)
{
	std::vector<std::string> tokens;
	std::istringstream iss(line);
	std::string current;

	while (getline(iss, current, delimiter)) {
		tokens.push_back(current);
	}

	return tokens;
}

std::string StringUtils::rtrim(std::string& str)
{
	const std::string WHITESPACE = " \n\r\t\f\v";
	size_t end = str.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

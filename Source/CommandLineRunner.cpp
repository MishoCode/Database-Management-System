#include "../Headers/CommandLineRunner.h"
#include "../Headers/StringUtils.h"
#include<iostream>
#include<sstream>

void CommandLineRunner::run(System& receiver)
{
	Invoker invoker(receiver);
	std::string line;
	while (getline(std::cin, line)) {
		if (!line.compare("exit")) {
			break;
		}
		std::vector<std::string> tokens = StringUtils::split(line);
		invoker.execute(tokens);
	}
}

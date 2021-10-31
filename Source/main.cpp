#include"../Headers/System.h"
#include "../Headers/CommandLineRunner.h"
#include<iostream>

int main() {

	//This is a test!
	//std::cout << "Hello world!" << std::endl;
	System database;
	CommandLineRunner::run(database);

	return 0;
}
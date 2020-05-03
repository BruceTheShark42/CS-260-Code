#include "GroupQueue.h"
#include "CustomerStack.h"
#include <iostream>
#include <cstring>
#include <limits>
#include "util.h"

/*
 * Read a string with a maximum number of characters
 * Resets std::cin for further use if any errors
 * Must manually delete the return value to avoid memory leaks
 * Yes, this is from project 1
 *
 * Inputs:
 *  message - a message to be shown to the user
 * 
 * Outputs:
 *  a string that contains a maximum of MAX_CHAR characters
 */
char* readString(const char *message) {
	std::cout << message;
	// Stores the user input
	char *str = new char[MAX_CHARS];
	std::cin.getline(str, MAX_CHARS);
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return str;
}

/*
 * Reads a string from std::cin and converts it to an int
 * Yes, this is from project 1
 * 
 * Inputs:
 *  message - a message to be shown to the user
 *  fail - the succeed/fail outcome
 *  chainErrors - if this function should accumulate errors 
 *	 from previous calls to this function or functions like 
 *	 it, such as readFloat
 * 
 * Outputs:
 *  an int that represents the contents of the user's input
 *  zero if any errors occur while trying to convert 
 */
int readInt(const char *message, bool &fail, bool chainErrors = false) {
	// Stores the user input
	char *input = readString(message);
	try {
		// Cannot direcly return this because input must be deleted afterwards
		int val = std::atoi(input);
		delete[] input;
		if (!chainErrors)
			fail = false;
		return val;
	} catch (...) {
		delete[] input;
		fail = true;
		return 0;
	}
}

void printHelp() {
	std::cout << "Commands:\n"
			  << " \"help\" - displays this list of commands\n"
			  << " \"exit\" - exits Resturant Simulator\n";
}

int main() {
	std::cout << "Welcome to Resturant Simulator!\n";
	printHelp();
	
	GroupQueue queue;
	CustomerStack stack(256);
	
	bool running = true;
	while (running) {
		char *input = readString("> ");
		if (!std::strcmp(input, "")) {
			
		} else if (!std::strcmp(input, "help")) {
			printHelp();
		} else if (!std::strcmp(input, "exit")) {
			running = false;
		} else {
			std::cout << "Unknown command!\n";
		}
		delete[] input;
	}
	
	return 0;
}

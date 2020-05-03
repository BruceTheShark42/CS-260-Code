/*
 * main.cpp
 *
 * CS Resturant Simulator
 * 
 * Bruce Cosgrove
 * 4 May 2020
 * CS 260
 * Assignment #2
 * 
 * Inputs:
 *  none
 * 
 * Outputs:
 *  customers.txt - the contact info for any customers who gave theirs
 *  std::cout - response to user input
 */

#include "GroupQueue.h"
#include "CustomerStack.h"
#include <iostream>
#include <cstring>
#include <limits>
#include "util.h"
#include <fstream>

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

/*
 * Writes contact info to a file
 * 
 * Inputs:
 *  file - the file to write to
 *  customer - the contact info
 * 
 * Outputs:
 *  writes the contact info to the file
 */
void saveContactInfo(std::ofstream &file, const Customer &customer) {
	file << customer.getName() << ' ' << customer.getEmail() << '\n';
}

/*
 * Prints a list of all supported commands
 * No succeed/fail potential, so no need for that clutter
 * 
 * Inputs:
 *  none
 * 
 * Outputs:
 *  a list of commands
 */
void printHelp() {
	std::cout << "Commands:\n"
			  << " \"door\" - simulates a group of people walking in and getting in line\n"
			  << " \"seat\" - simulates a group of people being seated\n"
			  << " \"line\" - prints the list of waiting customer groups\n"
			  << " \"cont\" - contact the most recent group of people who left their contact information\n"
			  << " \"help\" - displays this list of commands\n"
			  << " \"exit\" - exits Resturant Simulator\n";
}

/*
 * Where it all begins
 * 
 * Inputs:
 *  none
 * 
 * Outputs:
 *  whether or not the program executed correctly
 */
int main() {
	std::cout << "Welcome to CS Resturant Simulator!\n";
	printHelp();
	
	// The Queue
	GroupQueue queue;
	// The Stack
	CustomerStack stack(256);
	
	// Dictates if the program should continue running
	bool running = true;
	while (running) {
		// The user input
		char *input = readString("\n> ");
		if (!std::strcmp(input, "door")) {
			// The group name
			char *name = readString("Enter the group name: ");
			// If reading the totalPeople failed
			bool fail = false;
			// The number of people in thr group
			int totalPeople = readInt("Enter the number of people in the group: ", fail);
			if (fail) {
				std::cout << "Error reading the number of people in the group.\n";
			} else {
				// If the group has seating requirements
				char *hasSeatingRequirements = readString("Does the group have any seating requirements (yes/no): ");
				// The group's seating requirements
				char *seatingRequirements = nullptr;
				if (!std::strcmp(hasSeatingRequirements, "yes"))
					seatingRequirements = readString("Enter the seating requirements: ");
				// If the group has given contact information
				char *hasContactInfo = readString("Does the group have any contact information to receive promotional materials (yes/no): ");
				// The group's contact information
				char *contactInfoName = nullptr, *contactInfoEmail = nullptr;
				if (!std::strcmp(hasContactInfo, "yes")) {
					contactInfoName = readString("Enter the contact name: ");
					contactInfoEmail = readString("Enter the contact email: ");
				}
				
				queue.enqueue(Group(name, totalPeople, seatingRequirements, contactInfoName, contactInfoEmail));
				
				delete[] hasSeatingRequirements;
				if (seatingRequirements != nullptr)
					delete[] seatingRequirements;
				delete[] hasContactInfo;
				if (contactInfoName != nullptr)
					delete[] contactInfoName;
				if (contactInfoEmail != nullptr)
					delete[] contactInfoEmail;
			}
			delete[] name;
		} else if (!std::strcmp(input, "seat")) {
			if (queue.empty()) {
				std::cout << "There are currently no waiting customers.\n";
			} else {
				// The group to be seated
				Group group;
				queue.dequeue(group);
				if (group.hasContactInfo())
					stack.push(group.getContactInfo());
			}
		} else if (!std::strcmp(input, "line")) {
			if (queue.empty())
				std::cout << "There are currently no waiting customers.\n";
			else
				std::cout << queue;
		} else if (!std::strcmp(input, "cont")) {
			if (stack.empty()) {
				std::cout << "There are currently no customers who foolishly left their contact information.\n";
			} else {
				// The latest customer who gave their contact info
				Customer customer;
				stack.pop(customer);
				// The file to write to
				std::ofstream file("customers.txt", std::ios::out | std::ios::app);
				saveContactInfo(file, customer);
				file.close();
			}
		} else if (!std::strcmp(input, "help")) {
			printHelp();
		} else if (!std::strcmp(input, "exit")) {
			running = false;
		} else {
			std::cout << "\nUnknown command!\n";
		}
		delete[] input;
	}
	
	if (!stack.empty()) {
		// The file to write to
		std::ofstream file("customers.txt", std::ios::out | std::ios::app);
		// The customer to write
		Customer customer;
		while (stack.pop(customer))
			saveContactInfo(file, customer);
		file.close();
	}
	
	return 0;
}

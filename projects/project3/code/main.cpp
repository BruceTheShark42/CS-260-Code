/*
 * main.cpp
 *
 * CS Website Rating Simulator
 * 
 * Bruce Cosgrove
 * 18 May 2020
 * CS 260
 * Assignment #3
 * 
 * Inputs:
 *  websites.txt - the website info
 * 
 * Outputs:
 *  std::cout - response to user input
 */

#include "WebTable.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

#define MAX_CHARS 256

using namespace std;

/*
 * Read a string with a maximum number of characters
 * Resets std::cin for further use if any errors
 * Must manually delete the return value to avoid memory leaks
 * Yes, this is from projects 1 and 2
 *
 * Inputs:
 *  message - a message to be shown to the user
 * 
 * Outputs:
 *  a string that contains a maximum of MAX_CHAR characters
 */
char* readString(const char *message) {
	cout << message;
	// Stores the user input
	char *str = new char[MAX_CHARS];
	cin.getline(str, MAX_CHARS);
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return str;
}

/*
 * Reads a string from std::cin and converts it to an int
 * Yes, this is from projects 1 and 2
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
 * Loads data from a file into a WebTable
 * 
 * Inputs:
 *  path - the path to the file
 *  table - the WebTable to load to
 * 
 * Outputs:
 *  returns if the table could be loaded with the contents of the file
 */
bool loadFile(const char *path, WebTable &table) {
	// The file
	ifstream file(path);
	if (file.is_open()) {
		// The number of topics in the file
		size_t numKeys;
		file >> numKeys;
		for (size_t i = 0; i < numKeys; ++i) {
			// The number of Websites in the topic
			size_t numWebsites;
			file >> numWebsites;
			file.get();
			
			// The topic for adding the Websites to the WebTable
			char *key = new char[MAX_CHARS];
			file.getline(key, MAX_CHARS);
			for (size_t j = 0; j < numWebsites; ++j) {
				// The Website information
				char *url = new char[MAX_CHARS], *summary = new char[MAX_CHARS], *review = new char[MAX_CHARS], rating;
				
				file.getline(url, MAX_CHARS, ' ');
				file.get();
				file.getline(summary, MAX_CHARS, '\"');
				file.get();
				file.get();
				file.getline(review, MAX_CHARS, '\"');
				file.get();
				file >> rating;
				file.get();
				
				table.add(key, Website(url, summary, review, rating - '0'));
				
				delete[] url;
				delete[] summary;
				delete[] review;
			}
			delete[] key;
		}
		
		file.close();
		return true;
	}
	return false;
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
	cout << "Commands:\n"
		 << " \"add\" - add a Website\n"
		 << " \"get\" - get all Websites with a key\n"
		 << " \"set\" - set the review and rating for a Website\n"
		 << " \"cull\" - remove all Websites with a 1 star rating\n"
		 << " \"show\" - display all Websites with a key\n"
		 << " \"all\" - display all Websites\n"
		 << " \"help\" - show this list of commands\n"
		 << " \"exit\" - exit the Website Rating Simulator\n";
}

/*
 * I really should just package this menu thing into its own class
 * So I don't have to worry about it. I'd probably have to pass
 * lambdas as parameters to it though for each option or maybe
 * even raw function pointers. I could use std::function, but
 * only if we're allowed to, that is.
 * Ironically, to do this, I think I would need a HashTable...
 * 
 * Inputs:
 *  none
 * 
 * Outputs:
 *  whether or not the program executed correctly
 */
int main() {
	cout << "Welcome to Website Rating Simulator!\n";
	printHelp();
	
	// The ADT
	WebTable table;
	if (!loadFile("websites.txt", table)) {
		cout << "Couldn't load the file. :(\n";
		return 1;
	}
	
	// If the program should continue
	bool running = true;
	while (running) {
		// The user input
		char *input = readString("\n> ");
		
		if (!strcmp(input, "add")) {
			// All of these are the Website information
			char *key = readString("Enter the topic: ");
			char *url = readString("Enter the URL: ");
			char *summary = readString("Enter the summary: ");
			char *review = readString("Enter the review: ");
			bool fail = false; // Except this guy, it's super obvious that it to see if reading the rating failed, therefore, I shouldn't need these comments for obvious variables, yet here we are... mindlessly typing away at my keyboard because I don't want to comment more, even though I am literally doing just that... but whatever, let's just continue with this... commenting...................
			int rating = readInt("Enter the rating: ", fail);
			
			if (fail) {
				cout << "Invalid rating\n";
			} else {
				table.add(key, Website(url, summary, review, rating));
				cout << "Added the website.\n";
			}
			
			delete[] key;
			delete[] url;
			delete[] summary;
			delete[] review;
		} else if(!strcmp(input, "get")) {
			// The topic
			char *key = readString("Enter the topic: ");
			
			// The number of Websites
			size_t count = 0;
			// The Websites
			Website *sites = table.get(key, count);
			for (size_t i = 0; i < count; ++i)
				cout << sites[i];
			
			delete[] key;
			if (sites != nullptr) delete[] sites;
			
			if (!count)
				cout << "No websites matched the topic.\n";
		} else if(!strcmp(input, "set")) {
			// The Website information
			char *key = readString("Enter the topic: ");
			char *url = readString("Enter the URL: ");
			char *review = readString("Enter the review: ");
			bool fail = false; // Don't get me started again...
			int rating = readInt("Enter the rating: ", fail);
			
			if (fail || rating < 1 || rating > 5) {
				cout << "Invalid rating\n";
			} else {
				// The Website
				Website site;
				site.setURL(url);
				site.setReview(review);
				site.setRating((char)rating);
				if (table.set(key, site)) {
					cout << "Changed the review and rating.\n";
				} else {
					cout << "Unable to change the review and rating.\n";
				}
			}
			
			delete[] key;
			delete[] url;
			delete[] review;
		} else if(!strcmp(input, "cull")) {
			table.cull();
			cout << "All Websites with a 1 star review were removed.\n";
		} else if(!strcmp(input, "show")) {
			// The topic
			char *key = readString("Enter the key: ");
			table.print(cout, key);
			delete[] key;
		} else if(!strcmp(input, "all")) {
			cout << table;
		} else if(!strcmp(input, "help")) {
			printHelp();
		} else if(!strcmp(input, "exit")) {
			running = false;
		} else {
			cout << "Unknown command!\n";
		}
		
		delete[] input;
	}
	
	return 0;
}

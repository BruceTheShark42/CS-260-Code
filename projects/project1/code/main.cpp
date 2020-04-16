/*
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 * 
 * Inputs:
 *  labels.data - my own custom format
 *  std::cin - user input
 * 
 * Outputs:
 *  labels.data - my own custom format
 *  std::cout - response to user input
 */

#include <iostream>
#include <limits>
#include <cstring>
#include "RecordLabel.h"
#include "constants.h"



/*
 * Read a string with a maximum number of characters
 * Resets std::cin for further use if any errors
 * Must manually delete the return value to avoid memory leaks
 *
 * Inputs:
 *  message - a message to be shown to the user
 * 
 * Outputs:
 *  a string that contains a maximum of MAX_CHAR characters
 */
char* readString(const char *message) {
	std::cout << message;
	char *str = new char[MAX_CHARS];
	std::cin.getline(str, MAX_CHARS);
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return str;
}



/*
 * Reads a string from std::cin and converts it to a float
 * 
 * Inputs:
 *  message - a message to be shown to the user
 *  fail - the succeed/fail outcome
 *  chainErrors - if this function should accumulate errors 
 *	 from previous calls to this function or functions like 
 *	 it, such as readInt
 * 
 * Outputs:
 *  a float that represents the contents of the user's input
 *  zero if any errors occur while trying to convert 
 */
float readFloat(const char *message, bool &fail, bool chainErrors = false) {
	char *input = readString(message);
	try {
		// Very weirdly, std::atof returns a double instead of a float
		// I know I don't need to cast from a double to a float, 
		// but I chose to to be more explicit
		float val = (float)std::atof(input);
		delete[] input;
		if (!chainErrors)
			fail = false;
		return val;
	} catch (...) {
		delete[] input;
		fail = true;
		return 0.0f;
	}
}



/*
 * Reads a string from std::cin and converts it to an int
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
	char *input = readString(message);
	try {
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
 * Prints a list of all supported commands
 * No succeed/fail potential, so no need for that clutter
 * 
 * Inputs:
 *  none
 * 
 * Outputs:
 *  a list of commands
 */
void displayHelp() {
	std::cout << "Commands:\n"
			  << " - \"add artist\" - prompts you to add an artist\n"
			  << " - \"add song\" - prompts you to add a song for an artist\n"
			  << " - \"edit views\" - prompts you to edit the number of views for an artist's song\n"
			  << " - \"edit likes\" - prompts you to edit the number of likes for an artist's song\n"
			  << " - \"display\" - displays all songs for a single artist\n"
			  << " - \"display all\" - displays all artists and their songs\n"
			  << " - \"remove\" - remove all unpopular songs\n"
			  << " - \"help\" - show this list of commands\n"
			  << " - \"exit\" - exit CS Record Label Creator\n";
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
	std::cout << "Welcome to CS Record Label Creator!\n";
	displayHelp();
	
	RecordLabel rl;
	char *input;
	while (std::strcmp(input = readString("\n> "), "exit")) {
		if (!std::strcmp(input, "add artist")) {
			char *name = readString("Enter the artist's name: ");
			char *topStory = readString("Enter the artist's top story: ");
			char *description = readString("Enter the artist's description: ");
			std::cout << (rl.addArtist(name, topStory, description) ? "Successfully added" : "Failed to add") << " the artist \"" << name << "\" to the Record Label!\n";
			delete[] name;
			delete[] topStory;
			delete[] description;
		} else if (!std::strcmp(input, "add song")) {
			char *name = readString("Enter the artist's name: ");
			char *title = readString("Enter the title of the song: ");
			bool error = false;
			float length = readFloat("Enter the length of the song: ", error, true);
			int views = readInt("Enter the number of views for the song: ", error, true);
			int likes = readInt("Enter the number of likes for the song: ", error, true);
			std::cout << (!error && rl.addArtistSong(name, title, length, views, likes) ? "Successfully added" : "Failed to add") << "the song \"" << title << "\" to the artist \"" << name << "\" to the Record Label!\n";
			delete[] name;
			delete[] title;
		} else if (!std::strcmp(input, "edit views")) {
			char *name = readString("Enter the artist's name: ");
			char *title = readString("Enter the title of the song: ");
			bool error;
			int views = readInt("Enter the number of views for the song: ", error);
			std::cout << (!error && rl.setArtistSongViews(name, title, views) ? "Successfully" : "Failed to") << " set the views for the song \"" << title << "\" by \"" << name << "\" to the Record Label!\n";
			delete[] name;
			delete[] title;
		} else if (!std::strcmp(input, "edit likes")) {
			char *name = readString("Enter the artist's name: ");
			char *title = readString("Enter the title of the song: ");
			bool error;
			int likes = readInt("Enter the number of likes for the song: ", error);
			std::cout << (!error && rl.setArtistSongLikes(name, title, likes) ? "Successfully" : "Failed to") << " set the likes for the song \"" << title << "\" by \"" << name << "\" to the Record Label!\n";
			delete[] name;
			delete[] title;
		} else if (!std::strcmp(input, "display")) {
			char *name = readString("Enter the artist's name: ");
			if (!rl.displayArtist(std::cout, name))
				std::cout << "That artist does not exist!\n";
			delete[] name;
		} else if (!std::strcmp(input, "display all")) {
			std::cout << rl;
		} else if (!std::strcmp(input, "remove")) {
			bool error;
			int views = readInt("Enter the minimum number of views for a song to be considered popular: ", error);
			std::cout << (error ? "Failed to" : "Successfully") << " set the minimum number of views for the Record Label!\n";
			if (!error)
				rl.removeUnpopularSongs(views);
		} else if (!std::strcmp(input, "help")) {
			displayHelp();
		} else std::cout << "Unknown command!\n";
		delete[] input;
	}
	// Second delete[] required if input is "exit"
	delete[] input;
	return 0;
}

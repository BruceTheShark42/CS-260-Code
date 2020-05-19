/*
 * WebTable.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #3
 * 
 * Used to store a bunch of Websites
 */

#ifndef WEB_TABLE_H
#define WEB_TABLE_H

#include "Website.h"
#include <ostream>

class WebTable {
	struct Node {
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  site - the Website
		 *  next - the next Node
		 * 
		 * Outputs:
		 *  the new Node
		 */
		Node(Website *site = nullptr, Node *next = nullptr);
		
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  prev - the previous Node
		 *  site - the Website
		 * 
		 * Outputs:
		 *  the new Node
		 */
		Node(Node *prev, Website *site = nullptr);
		
		/*
		 * Destructs a Node
		 * 
		 * Inputs:
		 *  none
		 * 
		 * Outputs:
		 *  none
		 */
		~Node();
		
		Website *site;
		Node *next;
	};
public:
	/*
	 * Constructs a new WebTable
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new WebTable
	 */
	WebTable();
	
	/*
	 * Destructs a WebTable
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~WebTable();
public:
	/*
	 * Adds a Website
	 * 
	 * Inputs:
	 *  key - the topic
	 *  site - the Website
	 * 
	 * Outputs:
	 *  if the Website could be added
	 */
	bool add(const char *key, const Website &site);
	
	/*
	 * Gets all the Websites in a given topic
	 * 
	 * Inputs:
	 *  key - the topic
	 *  count - the number of Websites found
	 * 
	 * Outputs:
	 *  count is set to the number of Websites
	 *  returns an array of Websites
	 */
	Website* get(const char *key, size_t &count) const;
	
	/*
	 * Sets a Websites review and rating
	 * 
	 * Inputs:
	 *  key - the topic
	 *  site - the Website data
	 * 
	 * Outputs:
	 *  if the Website could be changed
	 */
	bool set(const char *key, const Website &site);
	
	/*
	 * Removes all Websites with a 1 star rating
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	void cull();
	
	/*
	 * Prints all Websites with a given topic
	 * 
	 * Inputs:
	 *  ostr - the std::ostream to write to
	 *  key - the topic
	 * 
	 * Outputs:
	 *  writes the Websites to ostr
	 */
	void print(std::ostream &ostr, const char *key) const;
	
	friend std::ostream& operator<<(std::ostream &ostr, const WebTable &table);
private:
	/*
	 * Constructs a hash index
	 * 
	 * Inputs:
	 *  key - the topic
	 * 
	 * Outputs:
	 *  the hash index
	 */
	size_t hash(const char *key) const;
	
	/*
	 * Recursively prints a list of Websites with the same topic
	 * 
	 * Inputs:
	 *  ostr - the std::ostream to write to
	 *  node - the Node with the Website to print
	 * 
	 * Outputs:
	 *  writes the Websites to ostr
	 */
	void printRec(std::ostream &ostr, Node *node) const;
private:
	Node **entries;
};

/*
 * Writes a WebTable to a std::ostream
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  table - the WebTable to write
 * 
 * Outputs:
 *  returns ostr
 */
std::ostream& operator<<(std::ostream &ostr, const WebTable &table);

#endif

/*
 * WebTree.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #4
 * 
 * Used to store sorted information about a bunch of Websites
 */

#ifndef WEB_TREE_H
#define WEB_TREE_H

#include "Website.h"
#include <ostream>

class WebTree {
public:
	/*
	 * Constructs a new WebTree
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new WebTree
	 */
	WebTree();
	
	/*
	 * Destructs a WebTree
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~WebTree();
public:
	/*
	 * Inserts a Website into this WebTree
	 * 
	 * Inputs:
	 *  site - the Website to insert
	 * 
	 * Outputs:
	 *  none
	 */
	void insert(const Website &site);
	
	/*
	 * Removes all Websites with a given topic
	 * 
	 * Inputs:
	 *  topic - the topic
	 * 
	 * Outputs:
	 *  none
	 */
	void removeAll(const char *topic);
	
	/*
	 * Removes a single Website with a given keyword
	 * 
	 * Inputs:
	 *  keyword - the keyword
	 * 
	 * Outputs:
	 *  if the Website could be removed
	 */
	bool remove(const char *keyword);
	
	/*
	 * Gets a Website with a keyword
	 * 
	 * Inputs:
	 *  keyword - the keyword
	 *  site - the Website to store to
	 * 
	 * Outputs:
	 *  if the Website was found
	 */
	bool get(const char *keyword, Website &site) const;
private:
	struct Node {
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  site - the Website data
		 * 
		 * Outputs:
		 *  the new Node
		 */
		Node(Website *site);
		
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
		Node *left, *right;
	};
private:
	/*
	 * Recursively deletes the entire Tree
	 * 
	 * Inputs:
	 *  node - the current Node to delete
	 * 
	 * Outputs:
	 *  none
	 */
	void deleteRec(Node *node);
	
	/*
	 * Recursively looks for the spot to insert a Website
	 * 
	 * Inputs:
	 *  site - the Website
	 *  node - the current Node
	 * 
	 * Outputs:
	 *  none
	 */
	void insertRec(const Website &site, Node *node);
	
	/*
	 * Recursively removes all Websites with a given topic
	 * 
	 * Inputs:
	 *  topic - the topic
	 *  node - the current Node to check
	 * 
	 * Outputs:
	 *  none
	 */
	void removeAllRec(const char *topic, Node *&node);
	
	/*
	 * Recursively removes a Website with a given keyword
	 * 
	 * Inputs:
	 *  node - the node to remove
	 *  keyword - the keyword
	 *  removed - if the Website was found
	 * 
	 * Outputs:
	 *  what the parameter node should now be
	 *		now that I think about it, node could just be a *&
	 *		and this function could return removed instead...
	 *		but too late, it works, and I'm not gonna change that.
	 */
	Node* remove(Node *node, const char *keyword, bool &removed);
	
	/*
	 * Removes a single Node
	 * 
	 * Inputs:
	 *  node - the node to remove
	 * 
	 * Outputs:
	 *  node - the new node in it's place
	 */
	void remove(Node *&node);
	
	/*
	 * Looks for the Node with the "minimum" value
	 *		in this case, that means what comes first alphabetically
	 * Inputs:
	 *  node - the node to start looking at
	 * 
	 * Outputs:
	 *  the node with the "minimum" value
	 */
	Node* getMinNode(Node *node) const;
	
	/*
	 * Recursively looks for a Website with a given keyword
	 * 
	 * Inputs:
	 *  keyword - the keyword
	 *  site - the Website to store to
	 *  node - the current Node to check
	 * 
	 * Outputs:
	 *  if a Website has the given keyword
	 */
	bool getRec(const char *keyword, Website &site, Node *node) const;
	
	/*
	 * Recursively prints this WebTree
	 * 
	 * Inputs:
	 *  ostr - the std::ostream to write to
	 *  node - the current Node to print
	 * 
	 * Outputs:
	 *  writes the current Node's Website to ostr
	 */
	void printRec(std::ostream &ostr, Node *node) const;
public:
	friend std::ostream& operator<<(std::ostream &ostr, const WebTree &tree);
private:
	Node *root;
};

/*
 * Prints a WebTree
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  tree - the WebTree ot write
 * 
 * Outputs:
 *  writes tree to ostr
 */
std::ostream& operator<<(std::ostream &ostr, const WebTree &tree);

#endif

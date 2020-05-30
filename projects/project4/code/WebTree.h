#ifndef WEB_TREE_H
#define WEB_TREE_H

#include "Website.h"
#include <ostream>

class WebTree {
public:
	WebTree();
	~WebTree();
public:
	void insert(const Website &site);
	void removeAll(const char *topic);
	bool remove(const char *keyword);
	bool get(const char *keyword, Website &site) const;
private:
	struct Node {
		Node(Website *site);
		~Node();
		
		Website *site;
		Node *left, *right;
	};
private:
	void deleteRec(Node *node);
	void insertRec(const Website &site, Node *node);
	void removeAllRec(const char *topic, Node *&node);
	Node* remove(Node *node, const char *keyword, bool &removed);
	void remove(Node *&node);
	Node* getMinNode(Node *node) const;
	bool getRec(const char *keyword, Website &site, Node *node) const;
	void printRec(std::ostream &ostr, Node *node) const;
public:
	friend std::ostream& operator<<(std::ostream &ostr, const WebTree &tree);
private:
	Node *root;
};

std::ostream& operator<<(std::ostream &ostr, const WebTree &tree);

#endif

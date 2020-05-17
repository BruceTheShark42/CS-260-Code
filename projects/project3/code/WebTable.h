#ifndef WEB_TABLE_H
#define WEB_TABLE_H

#include "Website.h"
#include <ostream>

class WebTable {
	struct Node {
		Node(Website *site = nullptr, Node *node = nullptr);
		Node(Node *prev, Website *site = nullptr);
		~Node();
		
		Website *site;
		Node *next;
	};
public:
	WebTable();
	~WebTable();
public:
	bool add(const char *key, const Website &site);
	Website* get(const char *key, size_t &count) const;
	bool set(const char *key, const Website &site);
	void cull();
	void print(std::ostream &ostr, const char *key) const;
	friend std::ostream& operator<<(std::ostream &ostr, const WebTable &table);
private:
	size_t hash(const char *key) const;
	void printRec(std::ostream &ostr, Node *node) const;
private:
	Node **entries;
};

std::ostream& operator<<(std::ostream &ostr, const WebTable &table);

#endif

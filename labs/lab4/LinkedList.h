#ifndef LINKED_LIST
#define LINKED_LIST

#include <ostream>

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	
	void add(char c);
	bool find(char c) const;
	bool del(char c);
	
	friend std::ostream& operator<<(std::ostream& ostr, LinkedList& list);
private:
	struct Node {
		Node(char data = 0, Node *next = nullptr);
		Node(Node *prev, char data = 0);
		char data;
		Node *next;
	} *head;
	
	void deleteRec(Node *node);
	void addRec(Node *prev, char c);
	bool findRec(Node *node, char c) const;
	bool delRec(Node *prev, char c);
	friend void printRec(std::ostream& ostr, Node *node);
};

#endif

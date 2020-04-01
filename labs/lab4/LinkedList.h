#ifndef LINKED_LIST
#define LINKED_LIST

#include <ostream>

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	
	void add(int c);
	bool find(int c) const;
	bool del(int c);
	int sum() const;
	int sumR() const;
	
	friend std::ostream& operator<<(std::ostream& ostr, LinkedList& list);
private:
	struct Node {
		Node(int data = 0, Node *next = nullptr);
		Node(Node *prev, int data = 0);
		int data;
		Node *next;
	} *head;
	
	void deleteRec(Node *node);
	void addRec(Node *prev, int c);
	bool findRec(Node *node, int c) const;
	bool delRec(Node *prev, int c);
	int sumRRec(Node *node) const;
	friend void printRec(std::ostream& ostr, Node *node);
};

#endif

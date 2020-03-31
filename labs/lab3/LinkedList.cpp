#include "LinkedList.h"

LinkedList::LinkedList() : head(new Node()) {}

LinkedList::~LinkedList() {
	deleteRec(head);
}

void LinkedList::deleteRec(Node *node) {
	if (node != nullptr) {
		deleteRec(node->next);
		delete node;
	}
}

void LinkedList::add(char c) {
	addRec(head, c);
}

void LinkedList::addRec(Node *prev, char c) {
	if (prev->next != nullptr)
		addRec(prev->next, c);
	else
		new Node(prev, c);
}

bool LinkedList::find(char c) const {
	findRec(head->next, c);
}

bool LinkedList::findRec(Node *node, char c) const {
	if (node != nullptr) {
		if (node->data == c)
			return true;
		else
			return findRec(node->next, c);
	}
	return false;
}

bool LinkedList::del(char c) {
	delRec(head, c);
}

bool LinkedList::delRec(Node *prev, char c) {
	Node *node = prev->next;
	if (node != nullptr) {
		if (node->data == c) {
			prev->next = node->next;
			delete node;
			return true;
		}
		return delRec(prev->next, c);
	}
	return false;
}

std::ostream& operator<<(std::ostream& ostr, LinkedList& list) {
	ostr << "[ ";
	printRec(ostr, list.head->next);
	return ostr << "]\n";
}

void printRec(std::ostream& ostr, LinkedList::Node *node) {
	if (node != nullptr) {
		ostr << node->data << ' ';
		printRec(ostr, node->next);
	}
}

// LinkedList::Node
LinkedList::Node::Node(char data, Node *next) : data(data), next(next) {}
LinkedList::Node::Node(Node *prev, char data) : data(data), next(prev->next) { prev->next = this; }

#include "LinkedList.h"

// LinkedList
LinkedList::LinkedList() : head(new Node()) {}

LinkedList::~LinkedList() {
	for (Node *node = head, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

void LinkedList::add(char c) {
	Node *node = head;
	while (node->next != nullptr)
		node = node->next;
	new Node(node, c);
}

bool LinkedList::find(char c) const {
	for (Node *node = head->next; node != nullptr; node = node->next)
		if (node->data == c)
			return true;
	return false;
}

bool LinkedList::del(char c) {
	for (Node *prev = head, *node; prev->next != nullptr; prev = node) {
		node = prev->next;
		if (node->data == c) {
			prev->next = node->next;
			delete node;
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& ostr, LinkedList& list) {
	ostr << "[ ";
	for (LinkedList::Node *node = list.head->next; node != nullptr; node = node->next)
		ostr << node->data << ' ';
	return ostr << "]\n";
}

// LinkedList::Node
LinkedList::Node::Node(char data, Node *next) : data(data), next(next) {}
LinkedList::Node::Node(Node *prev, char data) : data(data), next(prev->next) { prev->next = this; }

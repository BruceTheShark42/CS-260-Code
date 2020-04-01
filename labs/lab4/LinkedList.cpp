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

void LinkedList::add(int c) {
	addRec(head, c);
}

void LinkedList::addRec(Node *prev, int c) {
	if (prev->next != nullptr)
		addRec(prev->next, c);
	else
		new Node(prev, c);
}

bool LinkedList::find(int c) const {
	findRec(head->next, c);
}

bool LinkedList::findRec(Node *node, int c) const {
	if (node != nullptr) {
		if (node->data == c)
			return true;
		else
			return findRec(node->next, c);
	}
	return false;
}

bool LinkedList::del(int c) {
	delRec(head, c);
}

bool LinkedList::delRec(Node *prev, int c) {
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

int LinkedList::sum() const {
	int sum = 0;
	for (Node *node = head->next; node != nullptr; node = node->next)
		sum += node->data;
	return sum;
}

int LinkedList::sumR() const {
	return sumRRec(head->next);
}

int LinkedList::sumRRec(Node *node) const {
	if (node == nullptr)
		return 0;
	return node->data + sumRRec(node->next);
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
LinkedList::Node::Node(int data, Node *next) : data(data), next(next) {}
LinkedList::Node::Node(Node *prev, int data) : data(data), next(prev->next) { prev->next = this; }

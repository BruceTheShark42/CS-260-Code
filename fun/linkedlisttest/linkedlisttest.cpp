#include <cstring>
#include <iostream>

using namespace std;

struct Node {
	Node(const char *text) {
		this->text = new char[strlen(text) + 1];
		strcpy(this->text, text);
	}
	char *text;
	Node *next;
};

Node* createList(int num) {
	Node *node = new Node("This is node at backwards index.\nPlease for the love of all things that are holy, print this node." + (num--));
	node->next = createList(num);
	if (num <= 0) {
		return node;
	}
}

void print(Node *node) {
	if (node != nullptr) {
		cout << node->text << ' ';
		print(node->next);
	}
}

int main() {
	Node *node = createList(4);
	print(node);
	delete node;
}

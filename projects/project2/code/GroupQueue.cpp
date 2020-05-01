#include "GroupQueue.h"

GroupQueue::GroupQueue() :
		head(nullptr), tail(nullptr), groupCount(0) {}

GroupQueue::~GroupQueue() {
	deleteRec(head, 0);
}

void GroupQueue::deleteRec(Node *node, unsigned int nodes) {
	if (node != nullptr && nodes < groupCount) {
		deleteRec(node, nodes + 1);
		delete node;
	}
}

void GroupQueue::enqueue(const Group &group) {
	if (head == nullptr) {
		head = new Node(new Group(group));
		head->next = head;
		head->prev = head;
		tail = head;
	} else {
		tail = new Node(tail, new Group(group));
	}
}

bool GroupQueue::dequeue(Group &group) {
	if (head == nullptr)
		return false;
	group = *head->group;
	if (head == tail) {
		delete head;
		head = nullptr;
	} else {
		tail->next = tail->next->next;
		tail->next->prev = tail;
		delete head;
		head = tail->next;
	}
	return true;
}

bool GroupQueue::peek(Group &group) {
	if (head != nullptr) {
		group = *head->group;
		return true;
	}
	return false;
}

GroupQueue::Node::Node(Group *group) :
		group(group), next(this), prev(this) {}

GroupQueue::Node::Node(Node *prev, Group *group) :
		group(group), next(prev->next), prev(prev) {
	prev->next = this;
	next->prev = this;
}

GroupQueue::Node::~Node() {
	delete group;
}

std::ostream& operator<<(std::ostream &ostr, GroupQueue &queue) {
	return queue.printRec(ostr, queue.head, 0);
}

std::ostream& GroupQueue::printRec(std::ostream &ostr, GroupQueue::Node *node, unsigned int nodes) {
	if (node != nullptr) {
		node->group->print(ostr, nodes + 1);
		return printRec(ostr, node->next, nodes + 1);
	} else {
		return ostr;
	}
}

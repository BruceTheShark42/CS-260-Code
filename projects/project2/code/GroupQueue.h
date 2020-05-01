#ifndef GROUP_QUEUE_H
#define GROUP_QUEUE_H

#include "Group.h"
#include <ostream>

class GroupQueue {
public:
	GroupQueue();
	~GroupQueue();
public:
	void enqueue(const Group &group);
	bool dequeue(Group &group);
	bool peek(Group &group);
	inline bool empty() const { return groupCount == 0; }
	inline unsigned int size() const { return groupCount; }
public:
	friend std::ostream& operator<<(std::ostream &ostr, GroupQueue &queue);
private:
	struct Node {
		Node(Group *group = nullptr);
		Node(Node *prev, Group *group = nullptr);
		~Node();
		
		Group *group;
		Node *next, *prev;
	};
private:
	void deleteRec(Node *node, unsigned int nodes);
	std::ostream &printRec(std::ostream &ostr, Node *node, unsigned int nodes);
private:
	Node *head, *tail;
	unsigned int groupCount;
};

std::ostream& operator<<(std::ostream &ostr, GroupQueue &queue);

#endif

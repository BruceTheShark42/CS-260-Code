/*
 * GroupQueue.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * Used to store a bunch of groups of customers
 */

#ifndef GROUP_QUEUE_H
#define GROUP_QUEUE_H

#include "Group.h"
#include <ostream>

class GroupQueue {
public:
	/*
	 * Constructs a new GroupQueue
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new GroupQueue
	 */
	GroupQueue();
	
	/*
	 * Destructs a GroupQueue
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~GroupQueue();
public:
	/*
	 * Enqueues a Group to the queue
	 * 
	 * Inputs:
	 *  group - the Group to enqueue
	 * 
	 * Outputs:
	 *  none
	 */
	void enqueue(const Group &group);
	
	/*
	 * Dequeues a Group from the queue
	 * 
	 * Inputs:
	 *  group - the Group to store the enqueued Group
	 * 
	 * Outputs:
	 *  if a Group could be dequeued
	 */
	bool dequeue(Group &group);
	
	/*
	 * Peeks at the Group at the front of the queue
	 * 
	 * Inputs:
	 *  group - the Group to store the enqueued Group
	 * 
	 * Outputs:
	 *  if a Group could be peeked at
	 */
	bool peek(Group &group);
public:
	/*
	 * Returns if the queue is empty
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  if the queue is empty
	 */
	inline bool empty() const { return groupCount == 0; }
	
	/*
	 * Returns the size of the queue
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the size of the queue
	 */
	inline unsigned int size() const { return groupCount; }
public:
	/*
	 * Writes a queue to a std::ostream
	 * 
	 * Inputs:
	 *  ostr - the std::ostream to write to
	 *  queue - the queue to write
	 * 
	 * Outputs:
	 *  writes the queue to ostr
	 */
	friend std::ostream& operator<<(std::ostream &ostr, GroupQueue &queue);
private:
	struct Node {
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  group - the group to store
		 * 
		 * Outputs:
		 *  the new Node
		 */
		Node(Group *group = nullptr);
		
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  prev - the previous node
		 *  group - the group to store
		 * 
		 * Outputs:
		 *  the new Node
		 */
		Node(Node *prev, Group *group = nullptr);
		
		/*
		 * Destructs a Node
		 * 
		 * Inputs:
		 *  none
		 * 
		 * Outputs:
		 *  none
		 */
		~Node();
		
		// Stores the group
		Group *group;
		// Store the links to other Nodes
		Node *next, *prev;
	};
private:
	/*
	 * Recursively deletes a queue
	 * 
	 * Inputs:
	 *  node - the Node to delete
	 *  nodes - the index into the queue
	 * 
	 * Outputs:
	 *  none
	 */
	void deleteRec(Node *node, unsigned int nodes);
	
	/*
	 * Writes a Node to a std::ostream
	 * 
	 * Inputs:
	 *  node - the Node to print
	 *  nodes - the index into the queue
	 * 
	 * Outputs:
	 *  writes the Node to ostr
	 *  the std::ostream
	 */
	std::ostream &printRec(std::ostream &ostr, Node *node, unsigned int nodes);
private:
	// The start and end of this queue
	Node *head, *tail;
	// The number of groups in this queue
	unsigned int groupCount;
};

std::ostream& operator<<(std::ostream &ostr, GroupQueue &queue);

#endif

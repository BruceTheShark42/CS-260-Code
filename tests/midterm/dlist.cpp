#include "dlist.h"

//put the implmenetation of the required functions here

int countEven(node *head) {
	return head != nullptr ? (head->data % 2 == 0) + countEven(head->next) : 0;
}

int removeEven(node *&head) {
	if (head != nullptr) {
		if (head->data % 2 == 0) {
			node *oldHead = head, *oldNext = head->next;
			if (head->previous == nullptr) {
				head = head->next;
				if (head != nullptr)
					head->previous = nullptr;
			} else {
				if (head->next != nullptr)
					head->next->previous = head->previous;
				head->previous->next = head->next;
			}
			delete oldHead;
			return 1 + removeEven(oldNext);
		} else {
			return removeEven(head->next);
		}
	}
	return 0;
}

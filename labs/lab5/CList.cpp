#include "CList.h"

int count(node *head) {
	int total = 1;
	for (node *n = head->next; n != head; n = n->next, ++total);
	return total;
}

int countR(node *head) {
	return countRRec(head, head->next);
}

int countRRec(node *head, node *n) {
	return head != n ? 1 + countRRec(head, n->next) : 1;
}

int sum(node *head) {
	int sum = head->data;
	for (node *n = head->next; n != head; sum += n->data, n = n->next);
	return sum;
}

int sumR(node *head) {
	return sumRRec(head, head->next);
}

int sumRRec(node *head, node *n) {
	return head != n ? n->data + sumRRec(head, n->next) : n->data;
}

#include <iostream>
#include "CList.h"

int main() {
    node* head = nullptr;
	
    /* 
	 * Builds a circularly linked list with a random number of nodes
     * containing randomly-chosen numbers.
     */
    build(head);
	
    display(head);	
	
    // PUT YOUR CODE HERE to call the functions assigned,
	// and print out the results. For example,
	//
	//    std::cout << "iterative sum: " << sum(head) << '\n';
	//
	// The code for your functions should be in clist.cpp.
	
	std::cout << "Iterative total: " << count(head) << '\n';
	std::cout << "Recursive total: " << countR(head) << '\n';
	std::cout << "Iterative sum: " << sum(head) << '\n';
	std::cout << "Recursive sum: " << sumR(head) << '\n';
	
    // When called the 2nd time, this also prints the total
	// of the numbers in the nodes.
    display(head);
	
	int nNodesDeleted = 0;
	node *n = head, *next;
	
	while (n != head || nNodesDeleted == 0) {
		next = n->next;
		delete n;
		n = next;
		++nNodesDeleted;
	}
	
	std::cout << "Total nodes deleted: " << nNodesDeleted << '\n';
	//destroy(head);
    return 0;
}

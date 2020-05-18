#include "dlist.h"
using namespace std;

int main() {
	node *head = nullptr;
	build(head);
	display(head);
	
	//PLEASE PUT YOUR CODE HERE to call the function assigned
	
	cout << "countEven(head) = " << countEven(head) << '\n';
	cout << "removeEven(head) = " << removeEven(head) << '\n';
	
	display(head);
	destroy(head);    
	return 0;
}

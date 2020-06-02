#include "table.h"

#include <iostream>

using namespace std;

int main() {
    node *root = nullptr;
    build(root);
    display(root);
	
    /* PLACE YOUR FUNCTION CALLS HERE */
	cout << "sumOfLeafNodes() = " << sumOfLeafNodes(root) << '\n';
	
	cout << "copyEven(): the next tree print is newRoot, followed by root.\n";
	node *newRoot = nullptr;
	copyEven(root, newRoot);
	display(newRoot);
	
    display(root);
	
    destroy(root);
    destroy(newRoot);
    return 0;
}

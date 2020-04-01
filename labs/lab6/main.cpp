#include <iostream>
#include "Table.h"

int main() {
    node *root = nullptr;
    build(root);
    display(root);
	
    /* PLACE YOUR FUNCTION CALLS HERE */
	std::cout << "Count: " << count(root) << '\n';
	std::cout << "Sum: " << sum(root) << '\n';
	std::cout << "Height: " << height(root) << '\n';
	
    display(root);
    destroy(root);
    return 0;
}

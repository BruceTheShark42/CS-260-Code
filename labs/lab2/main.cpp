#include <iostream>
#include "LinkedList.h"

void find(LinkedList& list, char ch) {
	if (list.find(ch))
		std::cout << "Found";
	else
		std::cout << "Couldn't find";
	std::cout << " '" << ch << "'\n";
}

int main() {
	LinkedList list;
	
	list.add('x');
	list.add('y');
	list.add('z');
	std::cout << list;
	find(list, 'y');
	
	list.del('y');
	std::cout << list;
	find(list, 'y');
	
	list.del('x');
	std::cout << list;
	find(list, 'y');
	
	list.del('z');
	std::cout << list;
	find(list, 'y');
	
	return 0;
}

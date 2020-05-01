#include "GroupQueue.h"
#include "CustomerStack.h"
#include <iostream>

int main() {
	GroupQueue queue;
	CustomerStack stack(256);
	
	Group group("The Cosgrove Family", 4);
	queue.enqueue(group);
	std::cout << queue << '\n';
	return 0;
}

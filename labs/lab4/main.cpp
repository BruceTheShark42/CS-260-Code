#include <iostream>
#include "LinkedList.h"

static const int N_RANDS = 9;

int* randomArray(int length);

int main() {
	int* arr = randomArray(N_RANDS);
	LinkedList list;
	
	for (unsigned int i = 0; i < N_RANDS; ++i)
		list.add(arr[i]);
	
	std::cout << "sum() = " << list.sum() << '\n';
	std::cout << "sumR() = " << list.sumR() << '\n';
	
	delete[] arr;
	return 0;
}

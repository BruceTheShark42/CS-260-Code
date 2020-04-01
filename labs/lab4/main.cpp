#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

static const int N_RANDS = 9;

// Made own implementation because I got the following error when attempting to compile:
//	/usr/bin/ld: i386 architecture of input file `randomarray.o' is incompatible with i386:x86-64 output
//	randomarray.o: In function `randomArray(int)':
//	/home/inst/michael.trigoboff/cs260/labs/lab03/randomarray.cpp:9: undefined reference to `operator new[](unsigned int)'
// I took it to mean that randomarray.o is out of date and should be updated.
// Since it's a binary file, I can't exactly "update" it, per se, so I made my own.
int* randomArray(unsigned int length) {
	int *random = new int[length];
	for (unsigned int i = 0; i < length; ++i)
		random[i] = std::rand() % 100;
	return random;
}

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

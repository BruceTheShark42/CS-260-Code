#include "CustomerStack.h"

CustomerStack::CustomerStack(unsigned int size) :
		customers(new Customer*[size]), customerCount(0), maxCustomers(size) {}

CustomerStack::~CustomerStack() {
	for (unsigned int i = 0; i < customerCount; ++i)
		delete customers[i];
	delete[] customers;
}

bool CustomerStack::push(const Customer &customer) {
	if (customerCount < maxCustomers) {
		customers[customerCount++] = new Customer(customer);
		return true;
	}
	return false;
}

bool CustomerStack::pop(Customer &customer) {
	if (customerCount > 0) {
		customer = *customers[--customerCount];
		delete customers[customerCount];
		return true;
	}
	return false;
}

bool CustomerStack::peek(Customer &customer) const {
	if (customerCount > 0) {
		customer = *customers[customerCount - 1];
		return true;
	}
	return false;
}

/*
 * Customer.cpp
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * The implementation of Customer
 */

#include "Customer.h"
#include "util.h"

Customer::Customer() :
		name(nullptr), email(nullptr) {}

Customer::Customer(const char *name, const char *email) {
	set(name, email);
}

Customer::Customer(const Customer &customer) {
	set(customer.name, customer.email);
}

Customer& Customer::operator=(const Customer &customer) {
	if (name != nullptr)
		delete[] name;
	if (email != nullptr)
		delete[] email;
	set(customer.name, customer.email);
	
	return *this;
}

void Customer::set(const char *name, const char *email) {
	copyString(this->name, name);
	copyString(this->email, email);
}

Customer::~Customer() {
	delete[] name;
	delete[] email;
}

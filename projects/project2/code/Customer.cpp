#include "Customer.h"
#include "util.h"
#include <sstream>

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
}

void Customer::set(const char *name, const char *email) {
	copyString(this->name, name);
	copyString(this->email, email);
}

Customer::~Customer() {
	delete[] name;
	delete[] email;
}

const char* Customer::get() const {
	std::stringstream ss;
	ss << name << " " << email;
	return ss.str().c_str();
}

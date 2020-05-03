#ifndef CUSTOMER_STACK_H
#define CUSTOMER_STACK_H

#include "Customer.h"
#include <ostream>

class CustomerStack {
public:
	CustomerStack(unsigned int size);
	~CustomerStack();
public:
	bool push(const Customer &customer);
	bool pop(Customer &customer);
	bool peek(Customer &customer) const;
public:
	inline bool empty() const { return customerCount == 0; }
	inline unsigned int size() const { return customerCount; }
	inline unsigned int capacity() const { return maxCustomers; }
public:
	friend std::ostream& operator<<(std::ostream &ostr, const CustomerStack &stack);
private:
	Customer **customers;
	unsigned int customerCount, maxCustomers;
};

std::ostream& operator<<(std::ostream &ostr, const CustomerStack &stack);

#endif

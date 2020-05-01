#ifndef CUSTOMER_STACK_H
#define CUSTOMER_STACK_H

#include "Customer.h"

class CustomerStack {
public:
	CustomerStack(unsigned int size);
	~CustomerStack();
public:
	bool push(const Customer &customer);
	bool pop(Customer &customer);
	bool peek(Customer &customer) const;
	inline bool empty() const { return customerCount == 0; }
	inline unsigned int size() const { return customerCount; }
	inline unsigned int capacity() const { return maxCustomers; }
private:
	Customer **customers;
	unsigned int customerCount, maxCustomers;
};

#endif

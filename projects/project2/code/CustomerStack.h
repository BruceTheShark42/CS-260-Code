/*
 * CustomerStack.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * Used to store a bunch of customers
 */

#ifndef CUSTOMER_STACK_H
#define CUSTOMER_STACK_H

#include "Customer.h"
#include <ostream>

class CustomerStack {
public:
	/*
	 * Constructs a new CustomerStack
	 * 
	 * Inputs:
	 *  size - the maximum size of the stack
	 * 
	 * Outputs:
	 *  the new CustomerStack
	 */
	CustomerStack(unsigned int size);
	
	/*
	 * Destructs a CustomerStack
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~CustomerStack();
public:
	/*
	 * Pushes a Customer onto the stack
	 * 
	 * Inputs:
	 *  customer - the Customer to push
	 * 
	 * Outputs:
	 *  if the Customer could be pushed to the stack
	 */
	bool push(const Customer &customer);
	
	/*
	 * Pops a Customer from the stack
	 * 
	 * Inputs:
	 *  customer - the Customer to store the popped Customer
	 * 
	 * Outputs:
	 *  if the Customer could be popped from the stack
	 */
	bool pop(Customer &customer);
	
	/*
	 * Peeks at the top Customer on the stack
	 * 
	 * Inputs:
	 *  customer - the Customer to store the peeked at Customer
	 * 
	 * Outputs:
	 *  if the Customer could be peeked at
	 */
	bool peek(Customer &customer) const;
public:
	/*
	 * Returns if the stack is empty
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  if the stack is empty
	 */
	inline bool empty() const { return customerCount == 0; }
	
	/*
	 * Returns the size of the stack
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the size of the stack
	 */
	inline unsigned int size() const { return customerCount; }
	
	/*
	 * Returns the capacity of the stack
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the capacity of the stack
	 */
	inline unsigned int capacity() const { return maxCustomers; }
public:
	friend std::ostream& operator<<(std::ostream &ostr, const CustomerStack &stack);
private:
	// Stores the customers
	Customer **customers;
	// Stores the number of customers and the maximum amount of customers
	unsigned int customerCount, maxCustomers;
};

/*
 * Writes a stack to a std::ostream
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  stack - the stack to write
 * 
 * Outputs:
 *  writes the stack to ostr
 */
std::ostream& operator<<(std::ostream &ostr, const CustomerStack &stack);

#endif

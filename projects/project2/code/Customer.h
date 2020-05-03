/*
 * Customer.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * Used to store data about a customer
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
	/*
	 * Constructs a new Customer
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new Customer
	 */
	Customer();
	
	/*
	 * Constructs a new Customer
	 * 
	 * Inputs:
	 *  name - the name of the Customer
	 *  email - the email of the Customer
	 * 
	 * Outputs:
	 *  the new Customer
	 */
	Customer(const char *name, const char *email);
	
	/*
	 * Constructs a new Customer
	 * 
	 * Inputs:
	 *  customer - a Custoemr to copy
	 * 
	 * Outputs:
	 *  the new Customer
	 */
	Customer(const Customer &customer);
	
	/*
	 * Copies a Customer
	 * 
	 * Inputs:
	 *  customer - the Customer to copy
	 * 
	 * Outputs:
	 *  the new Customer
	 */
	Customer& operator=(const Customer &customer);
	
	/*
	 * Destructs a Customer
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~Customer();
public:
	/*
	 * Returns the name of the Customer
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the name
	 */
	inline const char* getName() const { return name; }
	
	/*
	 * Returns the email of the Customer
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the email
	 */
	inline const char* getEmail() const { return email; }
private:
	/*
	 * Sets the name and email of the Customer
	 * 
	 * Inputs:
	 *  name - the name of the Customer
	 *  email - the email of the Customer
	 * 
	 * Outputs:
	 *  none
	 */
	inline void set(const char *name, const char *email);
private:
	// Stores the name and email of this customer
	char *name = nullptr, *email = nullptr;
};

#endif

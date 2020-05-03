/*
 * Group.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * Used to store data about a group of customers
 */

#ifndef GROUP_H
#define GROUP_H

#include "Customer.h"
#include <ostream>

class Group {
public:
	/*
	 * Constructs a new Group
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new Group
	 */
	Group();
	
	/*
	 * Constructs a new Group
	 * 
	 * Inputs:
	 *  name - the name of the group
	 *  totalPeople - the number of people in the group
	 *  seatingRequirements - the seatingr requirements for the group
	 *  contactName - the contact name
	 *  email - the contact email
	 * 
	 * Outputs:
	 *  the new Group
	 */
	Group(const char *name, unsigned int totalPeople, const char *seatingRequirements, const char *contactName, const char *email);
	
	/*
	 * Constructs a new Group
	 * 
	 * Inputs:
	 *  group - the Group to copy
	 * 
	 * Outputs:
	 *  the new Group
	 */
	Group(const Group &group);
	
	/*
	 * Copies a Group
	 * 
	 * Inputs:
	 *  group - the Group to copy
	 * 
	 * Outputs:
	 *  this Group
	 */
	Group& operator=(const Group &group);
	
	/*
	 * Constructs a new Group
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new Group
	 */
	~Group();
public:
	/*
	 * Returns the name of the Group
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the name
	 */
	inline const char* getName() const { return name; }
	
	/*
	 * Returns the number of people in the Group
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the number of people in the group
	 */
	inline unsigned int getTotalPeople() const { return totalPeople; }
	
	/*
	 * Returns if the Group has any seating requirements
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the if the Group has any seating requirements
	 */
	inline bool hasSeatingRequirements() const { return seatingRequirements != nullptr; }
	
	/*
	 * Returns the seating requirements for the group
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the the seating requirements for the group
	 */
	inline const char* getSeatingRequirements() const { return seatingRequirements; }
	
	/*
	 * Returns if the Group has any contact info
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the if the Group has any contact info
	 */
	inline bool hasContactInfo() const { return contactInfo != nullptr; }
	
	/*
	 * Returns the contact info for the group
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the contact info for the group
	 */
	inline Customer& getContactInfo() const { return *contactInfo; }
private:
	// Stores the name of the group
	char *name;
	// Stores the number of people in the group
	unsigned int totalPeople;
	// Stores the seating requirements for the group
	char *seatingRequirements = nullptr;
	// Stores the contact information for the group
	Customer *contactInfo = nullptr;
};

#endif

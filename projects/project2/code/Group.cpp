/*
 * Group.cpp
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * The implementation of Group
 */

#include "Group.h"
#include "util.h"

// Used for retreiving information from a GroupQueue
Group::Group() :
		name(nullptr) {}

Group::Group(const char *name, unsigned int totalPeople, const char *seatingRequirements, const char *contactName, const char *email) :
		totalPeople(totalPeople), seatingRequirements(nullptr), contactInfo(nullptr) {
	copyString(this->name, name);
	if (contactName != nullptr && email != nullptr)
		contactInfo = new Customer(contactName, email);
	if (seatingRequirements != nullptr)
		copyString(this->seatingRequirements, seatingRequirements);
}

Group::Group(const Group &group) :
		totalPeople(group.totalPeople), seatingRequirements(nullptr) {
	copyString(this->name, group.name);
	contactInfo = group.hasContactInfo() ? new Customer(*group.contactInfo) : nullptr;
	if (group.hasSeatingRequirements())
		copyString(seatingRequirements, group.seatingRequirements);
}

Group& Group::operator=(const Group &group) {
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	if (hasSeatingRequirements()) {
		delete[] seatingRequirements;
		seatingRequirements = nullptr;
	}
	if (hasContactInfo()) {
		delete contactInfo;
		contactInfo = nullptr;
	}
	
	if (group.name != nullptr)
		copyString(name, group.name);
	totalPeople = group.totalPeople;
	if (group.hasSeatingRequirements())
		copyString(seatingRequirements, group.seatingRequirements);
	if (group.hasContactInfo())
		contactInfo = new Customer(*group.contactInfo);
	
	return *this;
}

Group::~Group() {
	if (name != nullptr)
		delete[] name;
	if (hasSeatingRequirements())
		delete[] seatingRequirements;
	if (hasContactInfo())
		delete contactInfo;
}

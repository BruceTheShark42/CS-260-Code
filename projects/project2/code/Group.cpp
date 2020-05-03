#include "Group.h"
#include "util.h"

// Used for retreiving information from a GroupQueue
Group::Group() :
		name(nullptr) {}

Group::Group(const char *name, unsigned int totalPeople) :
		totalPeople(totalPeople), seatingRequirements(nullptr), contactInfo(nullptr){
	copyString(this->name, name);
}

Group::Group(const char *name, unsigned int totalPeople, const char *seatingRequirements) :
		Group(name, totalPeople) {
	copyString(this->seatingRequirements, seatingRequirements);
}

Group::Group(const char *name, unsigned int totalPeople, const char *contactName, const char *email) :
		Group(name, totalPeople) {
	contactInfo = new Customer(contactName, email);
}

Group::Group(const char *name, unsigned int totalPeople, const char *seatingRequirements, const char *contactName, const char *email) :
		Group(name, totalPeople, contactName, email) {
	copyString(this->seatingRequirements, seatingRequirements);
}

Group::Group(const Group &group) :
		Group(group.name, group.totalPeople) {
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
}

Group::~Group() {
	if (name != nullptr)
		delete[] name;
	if (hasSeatingRequirements())
		delete[] seatingRequirements;
	if (hasContactInfo())
		delete contactInfo;
}

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
	copyString(seatingRequirements, group.seatingRequirements);
}

Group& Group::operator=(const Group &group) {
	if (name != nullptr)
		delete[] name;
	if (hasSeatingRequirements())
		delete[] seatingRequirements;
	if (hasContactInfo())
		delete contactInfo;
	
	copyString(name, group.name);
	totalPeople = group.totalPeople;
	copyString(seatingRequirements, group.seatingRequirements);
	contactInfo = group.contactInfo;
}

Group::~Group() {
	delete[] name;
	if (hasSeatingRequirements())
		delete[] seatingRequirements;
	if (hasContactInfo())
		delete contactInfo;
}

std::ostream& Group::print(std::ostream &ostr, unsigned int lineNumber) {
	return ostr << "Group \"" << name
				<< "\"\n - Place in Line: " << lineNumber
				<< "\n - Total People: " << totalPeople
				<< "\n - Seating Requirements: " << (hasSeatingRequirements() ? seatingRequirements : "none")
				<< "\n - Contact Info: " << (hasContactInfo() ? contactInfo->get() : "not given") << '\n';
}

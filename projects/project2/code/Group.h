#ifndef GROUP_H
#define GROUP_H

#include "Customer.h"
#include <ostream>

class Group {
public:
	Group();
	Group(const char *name, unsigned int totalPeople);
	Group(const char *name, unsigned int totalPeople, const char *seatingRequirements);
	Group(const char *name, unsigned int totalPeople, const char *contactName, const char *email);
	Group(const char *name, unsigned int totalPeople, const char *seatingRequirements, const char *contactName, const char *email);
	Group(const Group &group);
	Group& operator=(const Group &group);
	~Group();
public:
	inline const char* getName() const { return name; }
	inline unsigned int getTotalPeople() const { return totalPeople; }
	inline bool hasSeatingRequirements() const { return seatingRequirements != nullptr; }
	inline const char* getSeatingRequirements() const { return seatingRequirements; }
	inline bool hasContactInfo() const { return contactInfo != nullptr; }
	inline Customer& getContactInfo() const { return *contactInfo; }
private:
	char *name;
	unsigned int totalPeople;
	char *seatingRequirements = nullptr;
	Customer *contactInfo = nullptr;
};

#endif

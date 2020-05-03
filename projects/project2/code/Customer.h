#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
	Customer(const char *name, const char *email);
	Customer(const Customer &customer);
	Customer& operator=(const Customer &customer);
	~Customer();
public:
	inline const char* getName() const { return name; }
	inline const char* getEmail() const { return email; }
private:
	inline void set(const char *name, const char *email);
private:
	char *name = nullptr, *email = nullptr;
};

#endif

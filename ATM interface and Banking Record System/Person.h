#pragma once
#include <iostream>
#include "DateOfBirth.h"
#include "Name.h"

class Person
{
	std::string egn;
	Name name;
	DateOfBirth dateOfBirth;
	size_t mobileNumber;
	std::string adress;

public:
	virtual ~Person() = default;

	virtual const char* getEgn() const=0;
	virtual const Name& getName() const=0;
	virtual const DateOfBirth& getDateOfBirth() const=0;
	virtual const size_t getMobileNumber() const=0;
	virtual const char* getAdress() const=0;

	void setEgn(const char*);
	void setName(const char*, const char*, const char*);
	void setName(const Name&);
	void setDateOfBirth(const size_t, const size_t, const size_t);
	void setDateOfBirth(const DateOfBirth&);
	void setMobileNumber(const size_t);
	void setAdress(const char*);
};
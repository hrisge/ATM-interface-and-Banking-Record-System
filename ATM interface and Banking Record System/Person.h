#pragma once
#include <iostream>
#include "DateOfBirth.h"
#include "Name.h"

class Person
{
	size_t egn;
	Name name;
	DateOfBirth dateOfBirth;
	size_t mobileNumber;
	char* adress;

	void copyFrom(const Person&);
	void free();

public:
	Person();
	Person(size_t, const char*, const char*, const char*, size_t, size_t, size_t, size_t, const char*);
	Person(size_t, const Name&, const DateOfBirth&, size_t, const char*);
	Person(const Person&);
	//Person(Person&&);
	Person& operator=(const Person&);
	//Person& operator=(Person&&);
	virtual ~Person();

	virtual const size_t getEgn() const=0;
	virtual const Name& getName() const=0;
	virtual const DateOfBirth& getDateOfBirth() const=0;
	virtual const size_t getMobileNumber() const=0;
	virtual const char* getAdress() const=0;

	void setEgn(const size_t);
	void setName(const char*, const char*, const char*);
	void setName(const Name&);
	void setDateOfBirth(const size_t, const size_t, const size_t);
	void setDateOfBirth(const DateOfBirth&);
	void setMobileNumber(const size_t);
	void setAdress(const char*);
};
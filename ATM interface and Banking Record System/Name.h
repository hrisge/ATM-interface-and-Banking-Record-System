#pragma once
#include <iostream>

class Name
{
	char* firstName;
	char* midName;
	char* lastName;

	void copyFrom(const Name&);
	void free();

public:
	Name();
	Name(const char*, const char*, const char*);
	Name(const Name&);
	Name& operator=(const Name&);
	virtual ~Name();

	void setFirstName(const char*);
	void setMidName(const char*);
	void setLastName(const char*);

	virtual const char* getFirstName() const = 0;
	virtual const char* getMidName() const = 0;
	virtual const char* getLastName() const = 0;
};
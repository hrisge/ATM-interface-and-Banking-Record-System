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

	const char* getFirstName() const;
	const char* getMidName() const;
	const char* getLastName() const;
};
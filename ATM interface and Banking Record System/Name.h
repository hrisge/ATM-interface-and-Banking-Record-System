#pragma once
#include "Functions.h"
#include <iostream>
#include <string>

class Name
{
	std::string firstName;
	std::string midName;
	std::string lastName;

public:

	void setFirstName(const char*);
	void setFirstName(const std::string);
	void setMidName(const char*);
	void setMidName(const std::string);
	void setLastName(const char*);
	void setLastName(const std::string);

	const std::string& getFirstName() const;
	const std::string& getMidName() const;
	const std::string& getLastName() const;
};
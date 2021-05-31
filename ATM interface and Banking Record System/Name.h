#pragma once
#include <iostream>
#include <string>

class Name
{
	std::string firstName;
	std::string midName;
	std::string lastName;

public:

	void setFirstName(const char*);
	void setMidName(const char*);
	void setLastName(const char*);

	const std::string getFirstName() const;
	const std::string getMidName() const;
	const std::string getLastName() const;
};
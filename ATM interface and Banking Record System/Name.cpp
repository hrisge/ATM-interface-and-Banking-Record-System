#include "Name.h"
#pragma warning(disable: 4996)

void Name::setFirstName(const char* firstName)
{
	this->firstName = firstName;
}
void Name::setMidName(const char* midName)
{
	this->midName = midName;
}
void Name::setLastName(const char* lastName)
{
	this->lastName = lastName;
}

const std::string Name::getFirstName() const
{
	return firstName;
}

const std::string Name::getMidName() const
{
	return midName;
}

const std::string Name::getLastName() const
{
	return lastName;
}
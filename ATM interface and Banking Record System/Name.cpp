#include "Name.h"
#pragma warning(disable: 4996)

void Name::setFirstName(const char* firstName)
{
	this->firstName = convertToString(firstName);
}
void Name::setFirstName(const std::string firstName)
{
	this->firstName = firstName;
}
void Name::setMidName(const char* midName)
{
	this->midName = convertToString(midName);
}
void Name::setMidName(const std::string midName)
{
	this->midName = midName;
}
void Name::setLastName(const char* lastName)
{
	this->lastName = convertToString(lastName);
}
void Name::setLastName(const std::string lastName)
{
	this->lastName = lastName;
}

const std::string& Name::getFirstName() const
{
	return firstName;
}
const std::string& Name::getMidName() const
{
	return midName;
}
const std::string& Name::getLastName() const
{
	return lastName;
}
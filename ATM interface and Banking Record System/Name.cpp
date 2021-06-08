#include "Name.h"
#pragma warning(disable: 4996)

void Name::setFirstName(const char* firstName)
{
	convertToString(firstName, this->firstName);
}
void Name::setFirstName(const std::string firstName)
{
	this->firstName = firstName;
}
void Name::setMidName(const char* midName)
{
	convertToString(midName, this->midName);
}
void Name::setMidName(const std::string midName)
{
	this->midName = midName;
}
void Name::setLastName(const char* lastName)
{
	convertToString(lastName, this->lastName);
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

Name::Name(const char* firstName, const char* midName, const char* lastName)
{
	setFirstName(firstName);
	setMidName(midName);
	setLastName(lastName);
}
Name::Name(const std::string& firstName, const std::string& midName, const std::string& lastName)
{
	setFirstName(firstName);
	setMidName(midName);
	setLastName(lastName);
}
Name::Name()
{
	setFirstName(nullptr);
	setMidName(nullptr);
	setLastName(nullptr);
}
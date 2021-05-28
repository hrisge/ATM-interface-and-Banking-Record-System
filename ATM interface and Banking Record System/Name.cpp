#include "Name.h"

Name::Name() : firstName(nullptr), midName(nullptr), lastName(nullptr)
{

}
Name::Name(const char* firstName, const char* midName, const char* lastName)
{
	this->setFirstName(firstName);
	this->setMidName(midName);
	this->setLastName(lastName);
}
Name::Name(const Name& other)
{
	this->copyFrom(other);
}
Name::~Name()
{
	free();
}
Name& Name::operator=(const Name& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void Name::setFirstName(const char* firstName)
{
	delete[] this->firstName;
	this->firstName = new char[strlen(firstName) + 1];
	strcpy(this->firstName, firstName);
}
void Name::setMidName(const char* midName)
{
	delete[] this->midName;
	this->midName = new char[strlen(midName) + 1];
	strcpy(this->midName, midName);
}
void Name::setLastName(const char* lastName)
{
	delete[] this->lastName;
	this->lastName = new char[strlen(lastName) + 1];
	strcpy(this->lastName, lastName);
}

void Name::copyFrom(const Name& other)
{
	this->setFirstName(other.firstName);
	this->setMidName(other.midName);
	this->setLastName(other.lastName);
}
void Name::free()
{
	delete[] firstName;
	delete[] midName;
	delete[] lastName;
}
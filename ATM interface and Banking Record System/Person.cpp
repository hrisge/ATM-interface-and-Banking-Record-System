#include "Person.h"

Person::Person()
{
	this->setEgn(0);
	this->setName(nullptr, nullptr, nullptr);
	this->setDateOfBirth(0, 0, 0);
	this->setMobileNumber(0);
	this->setAdress(nullptr);
}
Person::Person(size_t egn, const Name& name, const DateOfBirth& dateOfBirth, size_t mobileNumber, const char* adress)
{
	this->setEgn(egn);
	this->setName(name);
	this->setDateOfBirth(dateOfBirth);
	this->setMobileNumber(mobileNumber);
	this->setAdress(adress);
}
Person::Person(size_t egn, const char* firstName, const char* midName, const char* lastName,
	size_t dayOfBirth, size_t monthOfBirth, size_t yearOfBirth, size_t mobileNumber, const char* adress)
{
	this->setEgn(egn);
	this->setName(firstName, midName, lastName);
	this->setDateOfBirth(dayOfBirth, monthOfBirth, yearOfBirth);
	this->setMobileNumber(mobileNumber);
	this->setAdress(adress);
}
Person::Person(const Person& other)
{
	copyFrom(other);
}
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Person::~Person()
{
	free();
}

void Person::free()
{
	delete[] adress;
}
void Person::copyFrom(const Person& other)
{
	free();
	this->adress = new char[strlen(other.adress) + 1];
	strcpy(adress, other.getAdress());
	this->setEgn(other.egn);
	this->setName(other.name);
	this->setMobileNumber(other.mobileNumber);
	this->setAdress(other.adress);
}

void Person::setEgn(const size_t egn)
{
	this->egn = egn;
}
void Person::setName(const Name& other)
{
	this->name = name;
}
void Person::setName(const char* firstName, const char* midName, const char* lastName)
{
	this->name.setFirstName(firstName);
	this->name.setMidName(midName);
	this->name.setLastName(lastName);
}
void Person::setDateOfBirth(const DateOfBirth& other)
{
	this->dateOfBirth = other;
}
void Person::setDateOfBirth(const size_t dayOfbirth, const size_t monthOfBirth, const size_t yearOfBirth)
{
	this->dateOfBirth.setDay(dayOfbirth);
	this->dateOfBirth.setMonth(monthOfBirth);
	this->dateOfBirth.setYear(yearOfBirth);
}
void Person::setMobileNumber(const size_t mobileNumber)
{
	this->mobileNumber = mobileNumber;
}
void Person::setAdress(const char* adress)
{
	free();
	this->adress = new char[strlen(adress) + 1];
	strcpy(this->adress, adress);
}
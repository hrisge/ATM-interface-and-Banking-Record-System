#include "Person.h"
#pragma warning(disable: 4996)

void Person::setEgn(const char* egn)
{
	size_t len = strlen(egn);
	if (len != 10)
		throw std::exception("Invalid egn. Too few or much characters");
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			if(egn[i] < '0' || egn[i] > '9')
				throw std::exception("Invalid egn. Unrecognised symbols");
		}
		this->egn.insert(0, egn);
	}
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
	this->adress.insert(0, adress);
}
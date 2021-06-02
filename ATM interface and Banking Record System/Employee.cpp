#include "Employee.h"

Employee::Employee() : Person()
{

}
Employee::Employee(const char* username, const char* password, const char* egn, const char* firstName, const char* midName, const char* lastName, const size_t dayOfBirth, const size_t monthOfBirth,
	const size_t yearOfBirth, const size_t mobileNumber, const char* adress) : Person(username, password, egn, firstName, midName, lastName, dayOfBirth, monthOfBirth,
		yearOfBirth, mobileNumber, adress)
{

}
Employee::Employee(const std::string& username, const std::string& password, const std::string& egn, const std::string& firstName, const std::string& midName, const std::string lastName, const size_t dayOfBirth,
	const size_t monthOfBirth, const size_t yearOfBirth, const size_t mobileNumber, std::string& adress) : Person(username, password, egn, firstName, midName, lastName, dayOfBirth, monthOfBirth,
		yearOfBirth, mobileNumber, adress)
{

}
Employee::Employee(const Account& account, const char* egn, const Name& name, const DateOfBirth& dateOfBirth, const size_t mobile, const char* adress) :
	Person(account, egn, name, dateOfBirth, mobile, adress)
{

}
Employee::Employee(const Account& account, const std::string& egn, const Name& name, const DateOfBirth& dateOfBirth, const size_t mobile, const std::string& adress) :
	Person(account, egn, name, dateOfBirth, mobile, adress)
{

}
Employee::Employee(const Employee& other) : Person(other)
{

}
Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		copyFrom(other);
	}
	return *this;
}

void Employee::copyFrom(const Employee& other)
{
	this->setAccount(other.getAccount());
	this->setEgn(other.getEgn());
	this->setName(other.getName());
	this->setDateOfBirth(other.getDateOfBirth());
	this->setMobileNumber(other.getMobileNumber());
	this->setAdress(other.getAdress());
}

const Employee& Employee::getEmployee() const
{
	return *this;
}

//void Employee::printPersonToFile(const char* fileName) const
//{
//	std::fstream file(fileName, std::ios::app);
//	if (!file.is_open())
//		throw std::exception("Unable to open file");
//	
//}

void Employee::nothing() const
{

}
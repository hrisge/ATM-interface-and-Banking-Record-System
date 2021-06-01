#include "Admin.h"

Admin::Admin() : Person()
{

}
Admin::Admin(const char* username, const char* password, const char* egn, const char* firstName, const char* midName, const char* lastName, const size_t dayOfBirth, const size_t monthOfBirth,
	const size_t yearOfBirth, const size_t mobileNumber, const char* adress) : Person(username, password, egn, firstName, midName, lastName, dayOfBirth, monthOfBirth, 
		yearOfBirth, mobileNumber, adress)
{

}
Admin::Admin(const std::string& username, const std::string& password, const std::string& egn, const std::string& firstName, const std::string& midName, const std::string lastName, const size_t dayOfBirth,
	const size_t monthOfBirth, const size_t yearOfBirth, const size_t mobileNumber, std::string& adress) : Person(username, password, egn, firstName, midName, lastName, dayOfBirth, monthOfBirth,
		yearOfBirth, mobileNumber, adress)
{

}
Admin::Admin(const Account& account, const char* egn, const Name& name, const DateOfBirth& dateOfBirth, const size_t mobile, const char* adress) :
	Person(account, egn, name, dateOfBirth, mobile, adress)
{

}
Admin::Admin(const Admin& other) : Person(other)
{

}

const Admin& Admin::getAdmin() const
{
	return *this;
}

void Admin::printAdminToFile(const char* fileName)
{
	std::fstream file(fileName, std::ios::app);
	if (!file.is_open())
		throw std::exception("Unable to open file");
	file << getAccount().getUsername() << "," << getAccount().getPassword() << "," << getEgn() << "," << getName().getFirstName() << "," <<
		getName().getMidName() << "," << getName().getLastName() << "," << getDateOfBirth().getDay() << "," << getDateOfBirth().getMonth() << "," <<
		getDateOfBirth().getYear() << "," << getMobileNumber() << "," << getAdress() << "\n";
	file.close();
}

void Admin::nothing() const
{

}
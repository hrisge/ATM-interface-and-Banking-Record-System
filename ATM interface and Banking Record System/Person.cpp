#include "Person.h"
#pragma warning(disable: 4996)

void Person::setAccount(const char* username, const char* password)
{
	account.setUsername(username);
	account.setPassword(username);
}
void Person::setAccount(const std::string& username, const std::string& password)
{
	account.setUsername(username);
	account.setPassword(username);
}
void Person::setAccount(const Account& other)
{
	this->account = other;
}
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
void Person::setEgn(const std::string& egn)
{
	size_t len = egn.size();
	if (len != 10)
		throw std::exception("Invalid egn. Too few or much characters");
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			if (egn[i] < '0' || egn[i] > '9')
				throw std::exception("Invalid egn. Unrecognised symbols");
		}
		this->egn = egn;
	}
}
void Person::setName(const Name& other)
{
	this->name = other;
}
void Person::setName(const char* firstName, const char* midName, const char* lastName)
{
	name.setFirstName(firstName);
	name.setMidName(midName);
	name.setLastName(lastName);
}
void Person::setName(const std::string& firstName, const std::string& midName, const std::string& lastName)
{
	name.setFirstName(firstName);
	name.setMidName(midName);
	name.setLastName(lastName);
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
void Person::setAdress(const std::string& adress)
{
	this->adress = adress;
}

const Account& Person::getAccount() const
{
	return account;
}
const std::string& Person::getEgn() const
{
	return egn;
}
const Name& Person::getName() const
{
	return name;
}
const DateOfBirth& Person::getDateOfBirth() const
{
	return dateOfBirth;
}
const size_t Person::getMobileNumber() const
{
	return mobileNumber;
}
const std::string& Person::getAdress() const
{
	return adress;
}

Person::Person() : account(" ", " "), egn("1000000000"), name(" ", " ", " "), dateOfBirth(1, 1, 1900), mobileNumber(0), adress(" ")
{
	//setAccount(nullptr, nullptr);
	//setEgn("1000000000");
	//setName(nullptr, nullptr, nullptr);
	//setDateOfBirth(1, 1, 1900);
	//setMobileNumber(0);
	//setAdress(nullptr);
}
Person::Person(const char* username, const char* password, const char* egn, const char* firstName, const char* midName, const char* lastName,
	const size_t dayOfBirth, const size_t monthOfBirth, const size_t yearOfBirth, const size_t mobileNumber, const char* adress)
{
	setAccount(username, password);
	setEgn(egn);
	setName(firstName, midName, lastName);
	setDateOfBirth(dayOfBirth, monthOfBirth, yearOfBirth);
	setMobileNumber(mobileNumber);
	setAdress(adress);
}
Person::Person(const std::string& username, const std::string& password, const std::string& egn, const std::string& firstName, 
	const std::string& midName, const std::string& lastName, const size_t dayOfBirth, const size_t monthOfBirth, const size_t yearOfBirth,
	const size_t mobileNumber, const std::string& adress)
{
	setAccount(username, password);
	setEgn(egn);
	setName(firstName, midName, lastName);
	setDateOfBirth(dayOfBirth, monthOfBirth, yearOfBirth);
	setMobileNumber(mobileNumber);
	setAdress(adress);
}
Person::Person(const Account& account, const char* egn, const Name& name, const DateOfBirth& dateOfBirth, const size_t mobile, const char* adress)
{
	setAccount(account);
	setEgn(egn);
	setName(name);
	setDateOfBirth(dateOfBirth);
	setMobileNumber(mobile);
	setAdress(adress);
}
Person::Person(const Account& account, const std::string& egn, const Name& name, const DateOfBirth& dateOfBirth, const size_t mobile, const std::string& adress)
{
	setAccount(account);
	setEgn(egn);
	setName(name);
	setDateOfBirth(dateOfBirth);
	setMobileNumber(mobile);
	setAdress(adress);
}
Person::Person(const Person& other)
{
	setAccount(other.getAccount());
	setEgn(other.getEgn());
	setName(other.getName());
	setDateOfBirth(other.getDateOfBirth());
	setMobileNumber(other.getMobileNumber());
	setAdress(other.getAdress());
}

void Person::printPersonToAFile(const char* fileName)
{
	std::fstream file(fileName, std::ios::app);
	file << getAccount().getUsername() << "," << getAccount().getPassword() << "," << getEgn() << "," << getName().getFirstName() << "," <<
		getName().getMidName() << "," << getName().getLastName() << "," << getDateOfBirth().getDay() << "," << getDateOfBirth().getMonth() << "," <<
		getDateOfBirth().getYear() << "," << getMobileNumber() << "," << getAdress()<<"\n";
	file.close();
}

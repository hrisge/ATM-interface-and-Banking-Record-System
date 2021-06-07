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

//void Admin::printAdminToFile(const char* fileName)
//{
//	std::fstream file(fileName, std::ios::app);
//	file << getAccount().getUsername() << "," << getAccount().getPassword() << "," << getEgn() << "," << getName().getFirstName() << "," <<
//		getName().getMidName() << "," << getName().getLastName() << "," << getDateOfBirth().getDay() << "," << getDateOfBirth().getMonth() << "," <<
//		getDateOfBirth().getYear() << "," << getMobileNumber() << "," << getAdress() << "\n";
//	file.close()
//}

void Admin::nothing() const
{

}

void Admin::addAnEmployee(const std::vector<Employee*>& employees, bool& isValid, Employee& newEmployee)
{
	system("cls");
	std::cout << "$ createNewEmployee \n"<<"$ Input username: \n";
	std::string username;
	std::string password;
	std::getline(std::cin, username);
	
	std::cout << "$ Input password: \n";
	std::getline(std::cin, password);

	std::string egn;
	std::cout << "$ Input EGN: \n";
	std::getline(std::cin, egn);

	size_t numberOfClients = employees.size();
	for (size_t i = 0; i < numberOfClients; i++)
	{
		isValid = employees[i]->getEgn() == egn;
		if (isValid)
		{
			std::cout << "[ Employee with this EGN exists! ] \n";
			//Employee a;
			return;
		}
	}

	isValid = 0;

	std::string firstName;
	std::cout << "$ Input first name: \n";
	std::getline(std::cin, firstName);

	std::string midName;
	std::cout << "$ Input middle name: \n";
	std::getline(std::cin, midName);

	std::string lastName;
	std::cout << "$ Input last name:  \n";
	std::getline(std::cin, lastName);

	size_t dayOfBirth, monthOfBirth, yearOfBirth;
	std::cout << "$ Input date of birth: \n";
	std::cin >> dayOfBirth;
	std::cin >> monthOfBirth;
	std::cin >> yearOfBirth;

	size_t mobileNumber;
	std::cout << "$ Input phone number: \n";
	std::cin >> mobileNumber;

	std::string adress;
	std::cout << "$ Input address : \n";
	std::cin.ignore();
	std::getline(std::cin, adress);

	Account account(username, password);
	Name fullName(firstName, midName, lastName);
	DateOfBirth dateOfbirth(dayOfBirth, monthOfBirth, yearOfBirth);

	newEmployee.setAccount(account);
	newEmployee.setEgn(egn);
	newEmployee.setName(fullName);
	newEmployee.setDateOfBirth(dateOfbirth);
	newEmployee.setMobileNumber(mobileNumber);
	newEmployee.setAdress(adress);


}
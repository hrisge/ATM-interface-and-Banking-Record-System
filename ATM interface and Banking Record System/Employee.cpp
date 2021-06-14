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

void Employee::nothing() const
{

}

void Employee::createAClientAccount(std::vector<Client*>& clients, Client& newClient)
{
	system("cls");
	std::cout << "$ createNewClient \n" << "$ Input username: \n";
	std::string username;
	std::string password;
	std::getline(std::cin, username);

	std::cout << "$ Input password: \n";
	std::getline(std::cin, password);

	std::string egn;
	std::cout << "$ Input EGN: \n";
	std::getline(std::cin, egn);

	size_t numberOfClients = clients.size();
	for (size_t i = 0; i < numberOfClients; i++)
	{
		bool isValid = clients[i]->getEgn() == egn;
		if (isValid)
		{
			std::cout << "[ Employee with this EGN exists! ] \n";
			std::cout << "[ Try another EGN ] \n";
			return;
		}
	}

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

	newClient.setAccount(account);
	newClient.setEgn(egn);
	newClient.setName(fullName);
	newClient.setDateOfBirth(dateOfbirth);
	newClient.setMobileNumber(mobileNumber);
	newClient.setAdress(adress);
	newClient.addABankAccount();

	std::cout << "[ Client account successfully created! ] \n";
}
void Employee::createANewBankAccount(Client* client)
{
	client->addABankAccount();
}
void Employee::addANewCardToABankAccount(BankAccount* accountToAdd, const std::string& egnOfClient)
{
	accountToAdd->addANewCard(egnOfClient);
}
void Employee::closeABankAccount(Client* client, size_t bankAccountIndToClose)
{
	client->closeABankAccount(bankAccountIndToClose);
}
void Employee::closeACardToABankAccount(BankAccount* bankAccount, size_t cardIndToClose)
{
	bankAccount->closeACard(cardIndToClose);
}
void Employee::reportOfAllClients(const std::vector<Client*>& clients)
{
	size_t numberOfClients = clients.size();
	for (size_t i = 0; i < numberOfClients; i++)
	{
		size_t numberOfAccounts = clients[i]->getNumberOfAccounts();
		size_t totalNumberOfCards = 0;
		for (size_t j = 0; j < numberOfAccounts; j++)
		{
			totalNumberOfCards += clients[i]->getBankAccounts()[j]->getNumberOfCards();
		}
		std::cout << "EGN: " << clients[i]->getEgn() << " Number of Bank Accounts: " << numberOfAccounts << " All cards count: " 
			<< totalNumberOfCards << "\n";
	}
}
void Employee::personalReportForAClient(const Client* client)
{
	system("CLS");
	std::cout << "$ individualReport " << client->getEgn() << "\n" << "-------Client------- \n";
	std::cout << "EGN: " << client->getEgn() << "\n";
	std::cout << "Name: " << client->getName().getFirstName() << " " << client->getName().getMidName() << " " << client->getName().getLastName()
		<< "\n";
	std::cout << "BirthDate: " << client->getDateOfBirth().getDay() << " " << client->getDateOfBirth().getMonth() << " " << 
		client->getDateOfBirth().getYear() << "\n";
	std::cout << "Phone number: " << client->getMobileNumber() << "\n";
	std::cout << "Adress: " << client->getAdress() << "\n";
	std::cout << "Number of Accounts: " << client->getNumberOfAccounts() << "\n";
	for (size_t i = 0; i < client->getNumberOfAccounts(); i++)
	{
		std::cout << "----Account" << i + 1 << "----- \n";
		std::cout << "Acc number: " << client->getBankAccounts()[i]->getName() << "\n";
		std::cout << "Balance: " << client->getBankAccounts()[i]->getAmmountOfFunds() << "\n";
		std::cout << "Number of Cards: " << client->getBankAccounts()[i]->getNumberOfCards() << "\n";
		for (size_t j = 0; j < client->getBankAccounts()[i]->getNumberOfCards(); j++)
		{
			std::cout << "----Card" << j + 1 << "----- \n";
			std::cout << "Card number: " << client->getBankAccounts()[i]->getCardsCollection()[j]->getName() << "\n";
			std::cout << "PIN: " << client->getBankAccounts()[i]->getCardsCollection()[j]->getPIN() << "\n";
		}
	}
}
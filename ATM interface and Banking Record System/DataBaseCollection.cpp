#include "DataBaseCollection.h"

DataBaseCollection::DataBaseCollection()
{
	loadDataBase("admins.txt", 1);
	loadDataBase("empolyees.txt", 2);
	loadDataBase("clients.txt", 3);
}
DataBaseCollection::~DataBaseCollection()
{
	saveDataBase("admins.txt", 1);
	saveDataBase("empolyees.txt", 2);
	saveDataBase("clients.txt", 3);

	free();
}

void DataBaseCollection::free()
{
	size_t numberOfAdmins = admins.size();
	size_t numberOfEmployees = employees.size();
	size_t numberOfClients = clients.size();

	for (size_t i = 0; i < numberOfAdmins; i++)
		delete admins[i];
	for (size_t i = 0; i < numberOfEmployees; i++)
		delete employees[i];
	for (size_t i = 0; i < numberOfClients; i++)
		delete clients[i];
}

void DataBaseCollection::loadDataBase(const char* fileName, size_t accountType) 
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::exception("Unable to open file");
	size_t count = countLines(fileName);
	for (size_t i = 0; i < count - 1; i++) 
	{
		char usernameBuff[MAX_NAME_LEN];
		file.get(usernameBuff, MAX_NAME_LEN, ',');
		file.seekg(1, 1);

		char passwordBuff[MAX_NAME_LEN];
		file.get(passwordBuff, MAX_NAME_LEN, ',');
		file.seekg(1, 1);

		Account account(usernameBuff, passwordBuff);

		char egnBuff[MAX_EGN_LEN+1];
		file.get(egnBuff, MAX_EGN_LEN+1, ',');
		file.seekg(1, 1);

		char firstNameBuff[MAX_NAME_LEN];
		file.get(firstNameBuff, MAX_NAME_LEN, ',');
		file.seekg(1, 1);

		char midNameBuff[MAX_NAME_LEN];
		file.get(midNameBuff, MAX_NAME_LEN, ',');
		file.seekg(1, 1);

		char lastNameBuff[MAX_NAME_LEN];
		file.get(lastNameBuff, MAX_NAME_LEN, ',');
		file.seekg(1, 1);

		Name name(firstNameBuff, midNameBuff, lastNameBuff);

		char dayBuff[DATE_MAX_LEN];
		file.get(dayBuff, DATE_MAX_LEN, ',');
		file.seekg(1, 1);

		char monthBuff[DATE_MAX_LEN];
		file.get(monthBuff, DATE_MAX_LEN, ',');
		file.seekg(1, 1);

		char yearBuff[DATE_MAX_LEN];
		file.get(yearBuff, DATE_MAX_LEN, ',');
		file.seekg(1, 1);

		size_t day, month, year;

		day = atoi(dayBuff);
		month = atoi(monthBuff);
		year = atoi(yearBuff);

		DateOfBirth dateOfBirth(day, month, year);

		char mobileNumberBuff[MAX_PHONE_LEN];
		file.get(mobileNumberBuff, MAX_PHONE_LEN, ',');
		file.seekg(1, 1);
		size_t mobileNumber = atoi(mobileNumberBuff);

		char addressBuff[MAX_ADRESS_LEN];
		if (accountType == 3)
		{
			file.get(addressBuff, MAX_ADRESS_LEN, ',');
			file.seekg(1, 1);
		}
		else
		{
			file.get(addressBuff, MAX_ADRESS_LEN, '\n');
			file.seekg(2, 1);
		}


		switch (accountType)
		{
		case 1: admins.push_back(new Admin(account, egnBuff, name, dateOfBirth, mobileNumber, addressBuff)); break;
		case 2: employees.push_back(new Employee(account, egnBuff, name, dateOfBirth, mobileNumber, addressBuff)); break;
		case 3: clients.push_back(new Client(account, egnBuff, name, dateOfBirth, mobileNumber, addressBuff)); break;
		default:
			break;
		}

		if (accountType == 3)
		{
			clients.back()->loadBankAccounts();
			size_t numberOfBankAccounts = clients.back()->getNumberOfAccounts();
			for (size_t j = 0; j < numberOfBankAccounts; j++)
			{
				std::string cardsFileName;
				cardsFileName = cardsFileName + clients.back()->getEgn() + "00" + clients.back()->getBankAccounts()[j]->getFromBankAccountNameTheLastFourDigitsOfEgn();

				clients.back()->getBankAccounts()[j]->setCardsCollections(convertToChar(cardsFileName));
			}
		}
	}
	file.close();
}
void DataBaseCollection::saveDataBase(const char* fileName, size_t accountType)
{
	switch (accountType)
	{
	case 1: printAdminsToAFile(fileName, admins) ; break;
	case 2: printEmployeesToAFile(fileName, employees); break;
	case 3: printClientsToAFile(fileName, clients); break;
	default:
		break;
	}
}

void DataBaseCollection::printAdminsToAFile(const char* fileName, std::vector<Admin*>& admins)
{
	eraseFileInformation(fileName);
	size_t numberOfAdmins = admins.size();
	for (size_t i = 0; i < numberOfAdmins; i++)
	{
		admins[i]->printPersonToAFile(fileName);
	}
}

void DataBaseCollection::printEmployeesToAFile(const char* fileName, std::vector<Employee*>& employees)
{
	eraseFileInformation(fileName);
	size_t numberOfEmployees = employees.size();
	for (size_t i = 0; i < numberOfEmployees; i++)
	{
		employees[i]->printPersonToAFile(fileName);
	}
}

void DataBaseCollection::printClientsToAFile(const char* fileName, std::vector<Client*>& clients)
{
	eraseFileInformation(fileName);
	size_t numberOfClients = clients.size();
	for (size_t i = 0; i < numberOfClients; i++)
	{
		clients[i]->printPersonToAFile(fileName);
		size_t numberOfBankAccounts = clients[i]->getNumberOfAccounts();
		for (size_t j = 0; j < numberOfBankAccounts; j++)
		{
			clients[i]->getBankAccounts()[j]->printBankAccountToFile(convertToChar(clients[i]->getEgn()));
			size_t numberOfBankCardsToAccount = clients[i]->getBankAccounts()[j]->getNumberOfCards();

			std::string cardsFileName;
			cardsFileName = cardsFileName + clients[i]->getEgn() + "00" + clients[i]->getBankAccounts()[j]->getFromBankAccountNameTheLastFourDigitsOfEgn();
			eraseFileInformation(convertToChar(cardsFileName));

			for (size_t k = 0; k < numberOfBankCardsToAccount; k++)
			{
				clients[i]->getBankAccounts()[j]->getCardsCollection()[k]->printCardToFile(convertToChar(cardsFileName));
			}
		}
	}

}

void DataBaseCollection::addAnEmployee(const std::string& adminEgn)
{
	size_t adminIndex = searchAdminByEgn(adminEgn);
	bool isValid = 1;
	Employee newOne;
	while (isValid)
	{
		admins[adminIndex]->addAnEmployee(employees, isValid, newOne);
	}
	std::cout << "[ Employee account successfully created! ] \n";
	employees.push_back(new Employee(newOne));
}

void DataBaseCollection::addAClient(const std::string& employeeEgn)
{
	size_t employeeIndex = searchEmployeeByEgn(employeeEgn);
	bool isValid = 1;
	Client newOne;
	while (isValid)
	{
		employees[employeeIndex]->createAClientAccount(clients, isValid, newOne);
	}
	std::cout << "[ Client account successfully created! ] \n";
	clients.push_back(new Client(newOne));
}

int DataBaseCollection::searchAdminByEgn(const std::string& adminEgn)
{
	size_t numberOfAdmins = admins.size();
	for (size_t i = 0; i < numberOfAdmins; i++)
	{
		if (admins[i]->getEgn() == adminEgn)
			return i;
	}
	std::cout << "No admin with such egn was found \n";
	return -1;
}

int DataBaseCollection::searchEmployeeByEgn(const std::string& employeeEgn)
{
	size_t numberOfEmployees = employees.size();
	for (size_t i = 0; i < numberOfEmployees; i++)
	{
		if (employees[i]->getEgn() == employeeEgn)
			return i;
	}
	std::cout << "No employee with such egn was found \n";
	return -1;
}

int DataBaseCollection::searchClientByEgn(const std::string& clientEgn)
{
	size_t numberOfClients = clients.size();
	for (size_t i = 0; i < numberOfClients; i++)
	{
		if (clients[i]->getEgn() == clientEgn)
			return i;
	}
	std::cout << "No client with such egn was found \n";
	return -1;
}

void DataBaseCollection::deleteAnEmployee(const std::string& adminEgn)
{
	size_t adminIndex = searchAdminByEgn(adminEgn);
	std::cout << "$ Input EGN to delete: \n";
	std::string egnToDelete;
	std::getline(std::cin, egnToDelete);
	int employeeIndexToDelete = searchEmployeeByEgn(egnToDelete);
	if (employeeIndexToDelete == -1)
	{
		std::cout << "[ No such employee exists! ] \n";
		return;
	}
	employees.erase(employees.begin() + employeeIndexToDelete);
}

void DataBaseCollection::deleteAClient(const std::string& employeeEgn)
{
	size_t employeeIndex = searchEmployeeByEgn(employeeEgn);
	std::cout << "$ Input EGN to delete: \n";
	std::string egnToDelete;
	std::getline(std::cin, egnToDelete);
	int clientIndexToDelete = searchClientByEgn(egnToDelete);
	if (clientIndexToDelete == -1)
	{
		std::cout << "[ No such client exists! ] \n";
		return;
	}
	clients.erase(clients.begin() + clientIndexToDelete);
}

void DataBaseCollection::addANewBankAccount(const std::string& employeeEgn)
{
	size_t employeeIndex = searchEmployeeByEgn(employeeEgn);
	std::string egnOfClient;
	std::cout << "$ Input EGN of client: \n";
	std::getline(std::cin, egnOfClient);
	int clientIndex = searchClientByEgn(egnOfClient);
	if (clientIndex == -1)
	{
		std::cout << "[ No such client exists! ] \n";
		return;
	}

	bool hasBeenCreated = 0;
	getEmployees()[employeeIndex]->createANewBankAccount(clients[clientIndex], hasBeenCreated);

}

const const std::vector<Admin*>& DataBaseCollection::getAdmins() const
{
	return admins;
}
const std::vector<Employee*>& DataBaseCollection::getEmployees() const
{
	return employees;
}
const std::vector<Client*>& DataBaseCollection::getClients() const
{
	return clients;
}
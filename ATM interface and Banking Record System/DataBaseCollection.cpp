#include "DataBaseCollection.h"

DataBaseCollection::DataBaseCollection()
{
	loadDataBase("admins.txt", 1);
	loadDataBase("empolyees.txt", 2);
	//loadDataBase();
}
DataBaseCollection::~DataBaseCollection()
{
	saveDataBase("admins1.txt", 1);
	saveDataBase("empolyees.txt", 2);
	//saveDataBase();
}

void DataBaseCollection::loadDataBase(const char* fileName, size_t accountType) 
{
	std::ifstream file(fileName);
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
		file.get(addressBuff, 64, '\n');
		file.seekg(2, 1);

		switch (accountType)
		{
		case 1: admins.push_back(new Admin(account, egnBuff, name, dateOfBirth, mobileNumber, addressBuff)); break;
		case 2: employees.push_back(new Employee(account, egnBuff, name, dateOfBirth, mobileNumber, addressBuff)); break;
		case 3: //clients.push_back(new Cient(username, password, EGN, name, date, phone, address)); break;
		default:
			break;
		}
	}
	file.close();
}
void DataBaseCollection::saveDataBase(const char* fileName, size_t accountType)
{
	switch (accountType)
	{
	case 1: printAdminsToAFile(fileName, admins) ; break;
	//case 2: ; break;
	//case 3: //clients.push_back(new Cient(username, password, EGN, name, date, phone, address)); break;
	default:
		break;
	}
}

void DataBaseCollection::printAdminsToAFile(const char* fileName, std::vector<Admin*>& admins)
{
	std::fstream file(fileName, std::ios::out | std::ios::trunc);
	if (!file.is_open())
		throw std::exception("Unable to open file");
	file.close();
	size_t numberOfAdmins = admins.size();
	for (size_t i = 0; i < numberOfAdmins; i++)
	{
		admins[i]->printAdminToFile(fileName);
	}
}
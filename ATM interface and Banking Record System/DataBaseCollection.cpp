#include "DataBaseCollection.h"

DataBaseCollection::DataBaseCollection()
{
	loadDataBase("admins.csv", 1);
	loadDataBase("employees.csv", 2);
	//loadDataBase();
}

void DataBaseCollection::loadDataBase(const char* fileName, size_t sw) 
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

		char dateBuff[DATE_MAX_LEN];
		file.get(dateBuff, DATE_MAX_LEN, ',');
		file.seekg(1, 1);

		size_t day, month, year;

		for (size_t i = 0; i < 3; i++) {
			char arr[10000];
			copyNextWordfromAnArr(arr, dateBuff);
			switch (i) 
			{
			case 0: day = atoi(arr); break;
			case 1: month = atoi(arr); break;
			case 2: year = atoi(arr); break;
			default: break;
			}
		}
		
		DateOfBirth dateOfBirth(day, month, year);

		char mobileNumberBuff[MAX_PHONE_LEN];
		file.get(mobileNumberBuff, MAX_PHONE_LEN, ',');
		file.seekg(1, 1);
		size_t mobileNumber = atoi(mobileNumberBuff);

		char addressBuff[MAX_ADRESS_LEN];
		file.get(addressBuff, 64, '\n');
		file.seekg(2, 1);

		switch (sw)
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

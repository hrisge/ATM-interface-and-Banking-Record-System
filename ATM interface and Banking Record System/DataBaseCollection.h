#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"

const size_t MAX_NAME_LEN = 128;
const size_t MAX_EGN_LEN = 10;
const size_t DATE_MAX_LEN = 16;
const size_t MAX_PHONE_LEN = 16;
const size_t MAX_ADRESS_LEN = 256;
const size_t LAST_FOUR_DIGITS_LEN = 4;
const size_t MAX_BANK_CARDS_FILENAME = 32;
const size_t MAX_NUMBER_OF_CHARS_FOR_BANKACCOUNT = 4;
const size_t MAX_FILENAME_SIZE = 64;


class DataBaseCollection
{
	std::vector<Admin*> admins;
	std::vector<Employee*> employees;
	std::vector<Client*> clients;

	void free();

	int searchAdminByEgn(const std::string&);
	int searchEmployeeByEgn(const std::string&);
	int searchClientByEgn(const std::string&);

	void loadDataBase(const char*, size_t);
	void saveDataBase(const char*, size_t);

	void printAdminsToAFile(const char*, std::vector<Admin*>&);
	void printEmployeesToAFile(const char*, std::vector<Employee*>&);
	void printClientsToAFile(const char*, std::vector<Client*>&);


public:
	DataBaseCollection();
	DataBaseCollection(const DataBaseCollection&) = delete;
	DataBaseCollection& operator=(const DataBaseCollection&) = delete;
	~DataBaseCollection();

	void addAnEmployee(const std::string&);
	void deleteAnEmployee(const std::string&);

	void addAClient(const std::string&);
	void deleteAClient(const std::string&);
	void addANewBankAccount(const std::string&);
	void addANewBankCard(const std::string&);
	void closeABankAccount(const std::string&);
	void closeABankCard(const std::string&);
	void reportOfClients(const std::string&);
	void reportAClient(const std::string&);

	void inputMoney(const std::string&);
	void withdrawMoney(const std::string&);
	void checkBalance(const std::string&);

	const std::vector<Admin*>& getAdmins() const;
	const std::vector<Employee*>& getEmployees() const;
	const std::vector<Client*>& getClients() const;




	
};

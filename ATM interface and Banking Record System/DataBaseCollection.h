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


class DataBaseCollection
{
	std::vector<Admin*> admins;
	std::vector<Employee*> employees;
	//std::vector<Client*> clients

	void free();

	int searchAdminByEgn(const std::string&);
	int searchEmployeeByEgn(const std::string&);

	void loadDataBase(const char*, size_t);
	void saveDataBase(const char*, size_t);

	void printAdminsToAFile(const char*, std::vector<Admin*>&);
	void printEmployeesToAFile(const char*, std::vector<Employee*>&);
	//void printClientsToAFile(const char*, std::vector<Client*>&);

	const Admin& getAdminFromFile();
	const Employee& getEmployeeFromFile();
	//const Client& getClientFromFile();

public:
	DataBaseCollection();
	DataBaseCollection(const DataBaseCollection&) = delete;
	DataBaseCollection& operator=(const DataBaseCollection&) = delete;
	~DataBaseCollection();

	void addAnEmployee(const std::string&);
	void deleteAnEmployee(const std::string&);

	const std::vector<Admin*>& getAdmins() const;
	const std::vector<Employee*>& getEmployees() const;




	
};

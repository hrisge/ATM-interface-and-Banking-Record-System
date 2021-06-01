#pragma once
#include <iostream>
#include <string>
#include "Person.h"

struct Employee : public Person
{
	Employee();
	Employee(const char*, const char*, const char*, const char*, const char*, const char*, const size_t, const size_t, const size_t, const size_t,
		const char*);
	Employee(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string,
		const size_t, const size_t, const size_t, const size_t, std::string&);
	Employee(const Account&, const char*, const Name&, const DateOfBirth&, const size_t, const char*);
	Employee(const Employee&);

	const Employee& getEmployee() const;

	void printEmployeeToFile(const char*);

	void createAnClientAccount();
	void deleteAnClientAccount();
	void createANewBankAccount();
	void addANewCardToABankAccount();
	void closeABankAccount();
	void closeACardToABankAccount();
	void reportOfAllClients();
	void personalReportForAClient();

	void nothing() const override;
};
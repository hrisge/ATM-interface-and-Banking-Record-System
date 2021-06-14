#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"

struct Employee : public Person
{
	Employee();
	Employee(const char*, const char*, const char*, const char*, const char*, const char*, const size_t, const size_t, const size_t, const size_t,
		const char*);
	Employee(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string,
		const size_t, const size_t, const size_t, const size_t, std::string&);
	Employee(const Account&, const char*, const Name&, const DateOfBirth&, const size_t, const char*);
	Employee(const Account&, const std::string&, const Name&, const DateOfBirth&, const size_t, const std::string&);
	Employee(const Employee&);
	Employee& operator=(const Employee&);

	const Employee& getEmployee() const;

	void createAClientAccount(std::vector<Client*>&, Client&);
	void createANewBankAccount(Client*);
	void addANewCardToABankAccount(BankAccount*, const std::string&);
	void closeABankAccount(Client*, size_t);
	void closeACardToABankAccount(BankAccount*, size_t);
	void reportOfAllClients(const std::vector<Client*>&);
	void personalReportForAClient(const Client*);

	void nothing() const override;
private:
	void copyFrom(const Employee&);
};
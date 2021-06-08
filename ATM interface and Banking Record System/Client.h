#pragma once
#include "BankAccount.h"
#include "Functions.h"
#include "Person.h"
#include <fstream>
#include <iostream>

const size_t EGN_SIZE = 10;
const size_t MAX_BANKACCOUNT_NAME_SIZE = 16;
const size_t MAX_FILENAME = 64;

class Client : public Person
{
	std::vector<BankAccount*> bankAccounts;
	size_t numberOfBankAccounts;

	bool checkDeposit(const std::string&);

public:
	Client() = default;
	Client(const char*, const char*, const char*, const char*, const char*, const char*, const size_t, const size_t, const size_t, const size_t,
		const char*);
	Client(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string,
		const size_t, const size_t, const size_t, const size_t, std::string&);
	Client(const Account&, const char*, const Name&, const DateOfBirth&, const size_t, const char*);

	const Client& getClient() const;
	const std::vector<BankAccount*>& getBankAccounts() const;
	const size_t getNumberOfAccounts() const;
	
	int checkAccountName(const std::string&);

	void addABankAccount();
	void loadBankAccounts();
	void closeABankAccount(size_t);
	void closeACard(size_t, size_t);

	void nothing() const override;

};
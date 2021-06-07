#include "Client.h"

void Client::nothing() const
{

}

void Client::loadBankAccounts() 
{
	char* egnArr;
	egnArr = convertToChar(getEgn());
	size_t sizeOfFile = countLines(egnArr);
	std::ifstream file(egnArr);
	for (size_t i = 0; i < sizeOfFile - 1; i++)
	{
		char bankAccountNameBuff[MAX_BANKACCOUNT_NAME_SIZE];
		file.get(bankAccountNameBuff, MAX_BANKACCOUNT_NAME_SIZE, ',');
		file.seekg(1, 1);

		char fundsBuff[MAX_BANKACCOUNT_NAME_SIZE];
		file.get(fundsBuff, MAX_BANKACCOUNT_NAME_SIZE, ',');
		file.seekg(1, 1);

		char numberOfCardsBuff[MAX_BANKACCOUNT_NAME_SIZE];
		file.get(numberOfCardsBuff, MAX_BANKACCOUNT_NAME_SIZE, '\n');
		file.seekg(2, 1);

		this->numberOfBankAccounts++;
		std::string newBankAccountName = convertToString(bankAccountNameBuff);
		std::string newBankAccountFunds = convertToString(fundsBuff);
		size_t newNumberOfCards = atoi(numberOfCardsBuff);
		bankAccounts.push_back(new BankAccount(newBankAccountName, newBankAccountFunds, newNumberOfCards));
		
	}
	delete[] egnArr;
}


const Client& Client::getClient() const
{
	return *this;
}
const std::vector<BankAccount*>& Client::getBankAccounts() const
{
	return bankAccounts;
}
const size_t Client::getNumberOfAccounts() const
{
	return numberOfBankAccounts;
}

void Client::addABankAccount()
{
	if (getEgn() == "1000000000")
	{
		std::cout << "[ This user is unable ] \n";
		return;
	}
	system("CLS");
	std::string lastFourDigits;
	for (size_t i = 6; i < 10; i++)
		lastFourDigits.push_back(getEgn()[i]);
	std::cout << "$ Funds to deposit:" << "\n";
	std::string fundsDeposited;
	std::getline(std::cin, fundsDeposited);
	while (!checkDeposit(fundsDeposited))
	{
		std::cout << "[ You have entered invalid symbols try again ] \n";
		std::getline(std::cin, fundsDeposited);
	}
	std::string nameOfAccount;
	nameOfAccount.insert(0, "00MYBANK");
	nameOfAccount.append(lastFourDigits);
	std::string numberOfAccountsStr = convertSize_tToString(getNumberOfAccounts());
	nameOfAccount.append(numberOfAccountsStr);
	bankAccounts.push_back(new BankAccount(nameOfAccount, fundsDeposited, 0));
	std::cout << "[ Successfully created new bank account ] \n";
	numberOfBankAccounts++;
}

bool Client::checkDeposit(const std::string& deposit)
{
	size_t size = deposit.size();
	bool res;
	for (size_t i = 0; i < size - 1; i++)
	{
		res = (deposit[i] > '0' && deposit[i] < '9');
	}
	return res;
}

Client::Client(const char* username, const char* password, const char* egn, const char* firstName, const char* midName, const char* lastName,
	const size_t dayOfBirth, const size_t monthOfBirth, const size_t yearOfBirth, const size_t mobileNumber, const char* adress) : 
	Person(username, password, egn, firstName, midName, lastName, dayOfBirth, monthOfBirth, yearOfBirth, mobileNumber, adress)
{

}
Client::Client(const std::string& username, const std::string& password, const std::string& egn, const std::string& firstName, 
	const std::string& midName, const std::string lastName, const size_t dayOfBirth, const size_t monthOfBirth, const size_t yearOfBirth, 
	const size_t mobileNumber, std::string& adress) : Person(username, password, egn, firstName, midName, lastName, dayOfBirth, monthOfBirth, 
		yearOfBirth, mobileNumber, adress)
{

}
Client::Client(const Account& account, const char* egn, const Name& name, const DateOfBirth& dateOfBirth, const size_t mobile, const char* adress) :
	Person(account, egn, name, dateOfBirth, mobile, adress)
{

}

#include "Account.h"

Account::Account()
{
	setUsername(nullptr);
	setPassword(nullptr);
}
Account::Account(const char* username, const char* password)
{
	setUsername(username);
	setPassword(password);
}
Account::Account(const std::string& username, const std::string& password)
{
	setUsername(username);
	setPassword(password);
}

void Account::setUsername(const char* username)
{
	this->username = convertToString(username);
}
void Account::setUsername(const std::string& username)
{
	this->username = username;
}
void Account::setPassword(const char* password)
{
	this->password = convertToString(password);
}
void Account::setPassword(const std::string& password)
{
	this->password = password;
}

const std::string& Account::getUsername() const
{
	return username;
}
const std::string& Account::getPassword() const
{
	return password;
}
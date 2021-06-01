#pragma once
#include "Functions.h"
#include <iostream>
#include <string>


class Account
{
	std::string username;
	std::string password;

public:

	void setUsername(const std::string&);
	void setUsername(const char*);
	void setPassword(const std::string&);
	void setPassword(const char*);

	const std::string& getUsername() const;
	const std::string& getPassword() const;
};
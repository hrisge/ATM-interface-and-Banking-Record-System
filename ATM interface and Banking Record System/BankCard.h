#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"


class BankCard
{
	std::string name;
	size_t PIN;

public:
	BankCard();
	BankCard(const std::string&, const std::string&);
	BankCard(const std::string&);
	~BankCard() = default;

	const std::string& getName() const;
	const size_t getPIN() const;

	void setName(const std::string&, const std::string&);
	void setName(const std::string&);
	void setPIN();
	void setPIN(const std::string&);

	void printCardToFile(const char*);
};

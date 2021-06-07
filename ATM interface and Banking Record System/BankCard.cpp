#include "BankCard.h"

const std::string& BankCard::getName() const
{
	return name;
}
const size_t BankCard::getPIN() const
{
	return PIN;
}

void BankCard::setName(const std::string& lastFourDigitsOfClientsEgn, const std::string& numberOfCards)
{
	name.insert(0, "00");
	name.append(lastFourDigitsOfClientsEgn);
	name.append(numberOfCards);
}
void BankCard::setName(const std::string& name)
{
	this->name = name;
}
void BankCard::setPIN()
{
	srand(time(NULL));
	PIN = rand() % 9000 + 1000;
}
void BankCard::setPIN(const std::string& PIN)
{
	this->PIN = atoi(convertToChar(PIN));
}

void BankCard::printCardToFile(const char* fileName)
{
	std::fstream file(fileName, std::ios::app);

	file << getName() << "," << getPIN() << "\n";
	file.close();
}

BankCard::BankCard()
{
	std::string name = " ";
	std::string PIN = " ";
	setName(name);
	setPIN(PIN);
}
BankCard::BankCard(const std::string& name, const std::string& PIN)
{
	setName(name);
	setPIN(PIN);
}
BankCard::BankCard(const std::string& name)
{
	setName(name);
	setPIN();
}
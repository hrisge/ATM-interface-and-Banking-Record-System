#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "BankCard.h"
#include "Functions.h"

const size_t MAX_CARD_NAME = 8;

class BankAccount
{
	std::string name;
	std::string ammountOfFunds;
	std::vector<BankCard*> cardsCollection;
	size_t numberOfCards;

public:

	void addANewCard(const std::string&);

	const std::string& getName() const;
	const std::string& getAmmountOfFunds() const;
	const std::vector<BankCard*>& getCardsCollection() const;
	const size_t getNumberOfCards() const;

	void setName(const std::string&, const std::string&);
	void setName(const std::string&);
	void setAmmountOfFunds(const std::string&);
	void setCardsCollections(const std::string&);
	void setNumberOfCards(const int);

	int checkCardName(const std::string&);
	void closeACard(size_t);
	void deleteCardsCollection();

	void getFromBankAccountNameTheLastFourDigitsOfEgn(std::string&);

	void printBankAccountToFile(const std::string&);

	BankAccount(const std::string&, const std::string&, const std::string&);
	BankAccount(const std::string&, const std::string&, size_t);
};

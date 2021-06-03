#include "BankAccount.h"

void BankAccount::setName(const std::string& lastFourDigitsOfClientsEgn, const std::string& numberOfAccounts)
{
	name.insert(0, "00MYBANK");
	name.append(lastFourDigitsOfClientsEgn);
	name.append(numberOfAccounts);
}
void BankAccount::setAmmountOfFunds(const std::string& ammountOfFunds)
{
	this->ammountOfFunds = ammountOfFunds;
}
void BankAccount::setCardsCollections(const char* fileName)
{
	size_t numberOfCards = countLines(fileName);
	std::ifstream file(fileName);
	for (size_t i = 0; i < numberOfCards-1; i++)
	{
		char cardNameBuff[MAX_CARD_NAME];
		file.get(cardNameBuff, MAX_CARD_NAME, ',');
		file.seekg(1, 1);

		char cardPINBuff[MAX_CARD_NAME];
		file.get(cardNameBuff, MAX_CARD_NAME, ',');
		file.seekg(1, 1);

		std::string cardName, cardPIN;
		cardName = convertToString(cardNameBuff);
		cardPIN = convertToString(cardPINBuff);

		cardsCollection.push_back(new BankCard(cardName, cardPIN));
		setNumberOfCards(1);
	}
}
void BankAccount::setNumberOfCards(int i)
{
	numberOfCards = numberOfCards + i;
}

const std::string& BankAccount::getName() const
{
	return name;
}
const std::string& BankAccount::getAmmountOfFunds() const
{
	return ammountOfFunds;
}
const std::vector<BankCard*>& BankAccount::getCardsCollection() const
{
	return cardsCollection;
}
const size_t BankAccount::getNumberOfCards() const
{
	return numberOfCards;
}

void BankAccount::addANewCard(const std::string& lastFourDigitsOfEgn)
{
	std::string cardName;
	cardName.insert(0, "00");
	cardName.append(lastFourDigitsOfEgn);
	std::string numberOfCards = convertSize_tToString(this->numberOfCards);
	cardName.append(numberOfCards);
	cardsCollection.push_back(new BankCard(cardName));
}

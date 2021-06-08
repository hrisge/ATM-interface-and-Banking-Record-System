#include "BankAccount.h"

void BankAccount::setName(const std::string& lastFourDigitsOfClientsEgn, const std::string& numberOfAccounts)
{
	name.insert(0, "00MYBANK");
	name.append(lastFourDigitsOfClientsEgn);
	name.append(numberOfAccounts);
}
void BankAccount::setName(const std::string& name)
{
	this->name = name;
}
void BankAccount::setAmmountOfFunds(const std::string& ammountOfFunds)
{
	this->ammountOfFunds = ammountOfFunds;
}
void BankAccount::setCardsCollections(const char* fileName)
{
	size_t numberOfCards = countLines(fileName);
	if (numberOfCards == -1)
		return;
	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::exception("Unable to open file");
	for (size_t i = 0; i < numberOfCards-1; i++)
	{
		char cardNameBuff[MAX_CARD_NAME];
		file.get(cardNameBuff, MAX_CARD_NAME, ',');
		file.seekg(1, 1);

		char cardPINBuff[MAX_CARD_NAME];
		file.get(cardNameBuff, MAX_CARD_NAME, '\n');
		file.seekg(2, 1);

		std::string cardName, cardPIN;
		convertToString(cardNameBuff, cardName);
		convertToString(cardPINBuff, cardPIN);

		cardsCollection.push_back(new BankCard(cardName, cardPIN));
		setNumberOfCards(1);
	}
	file.close();
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

void BankAccount::addANewCard(const std::string& egn)
{
	system("CLS");
	std::string lastFourDigits;
	for (size_t i = 6; i < 10; i++)
		lastFourDigits.push_back(egn[i]);
	std::string cardName;
	cardName.insert(0, "00");
	cardName.append(lastFourDigits);
	std::string numberOfCards = convertSize_tToString(this->numberOfCards);
	cardName.append(numberOfCards);
	cardsCollection.push_back(new BankCard(cardName));
	std::cout << "[ Successfully added  new card to this bank account ] \n";
	setNumberOfCards(1);
}

int BankAccount::checkCardName(const std::string& cardToCheckName)
{
	for (size_t i = 0; i < getNumberOfCards(); i++)
	{
		if (cardToCheckName == getCardsCollection()[i]->getName())
			return i;
	}
	return -1;
}
void BankAccount::closeACard(size_t cardIndexToClose)
{
	cardsCollection.erase(cardsCollection.begin() + cardIndexToClose);
	std::cout << "[ Successfully deleted card! ] \n";
}

BankAccount::BankAccount(const std::string& bankAccountName, const std::string& newBankAccountFunds, size_t numberOfCards)
{
	setName(bankAccountName);
	setAmmountOfFunds(newBankAccountFunds);
	setNumberOfCards(numberOfCards);
}
BankAccount::BankAccount(const std::string& lastFourDigitsOfEgn, const std::string& numberOfAccounts, const std::string& ammountOfFunds)
{
	numberOfCards = 0;
	setName(lastFourDigitsOfEgn, numberOfAccounts);
	setAmmountOfFunds(ammountOfFunds);

}

void BankAccount::getFromBankAccountNameTheLastFourDigitsOfEgn(std::string& lastFourDigits)
{
	for (size_t i = 8; i < 12; i++)
	{
		lastFourDigits.push_back(this->getName()[i]);
	}

}

void BankAccount::printBankAccountToFile(const char* fileName) 
{
	std::ofstream file(fileName, std::ios::ate | std::ios::trunc);
	if (!file.is_open())
		throw std::exception("Unable to open file");
	file << getName() << "," << getAmmountOfFunds() << "," << getNumberOfCards() << "\n";
	file.close();
}


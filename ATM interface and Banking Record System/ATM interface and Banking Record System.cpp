#include <iostream>
#include "Admin.h"
#include "BankAccount.h"
#include "Client.h"

#include "DataBaseCollection.h"

int main()
{
    DataBaseCollection collection;
    //std::string egn = "0146049340dsv";
    //a.deleteAnEmployee(egn);
    
    /*convertToChar(egn);*/


    std::string randomEgn = collection.getEmployees()[0]->getEgn();
    //collection.addAClient(randomEgn);
    //collection.addANewBankAccount(randomEgn); //proveri dali uvelichava indeksite w imenata
    collection.addANewBankCard(randomEgn); //ne zapiswa wuw faila

}
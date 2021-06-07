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


    Client a("gosho", "mastikaledena", "0295738573", "georgi", "subev", "PASHATA", 6, 10, 1999, 0345724, "liulin");
    a.addABankAccount();
    a.getBankAccounts()[0]->addANewCard(a.getEgn());

}
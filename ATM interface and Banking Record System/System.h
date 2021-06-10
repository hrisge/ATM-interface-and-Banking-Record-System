#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DataBaseCollection.h"

void system();

const std::string& logInAsAdmin(const std::vector<Admin*>&);
const std::string& logInAsEmployee(const std::vector<Employee*>&);
const std::string& logInAsClient(const std::vector<Client*>&);

size_t logInCommand();

bool commandForAdmin(bool, std::string&);
bool commandForEmployees(bool, std::string&);
bool commandForClients(bool, std::string&);

void LogInHelpCommand();
void adminHelpCommand();
void employeeHelpCommand();
void clientHelpCommand();

void createNewEmployee(DataBaseCollection&, const std::string&);
void deleteAnEmployee(DataBaseCollection&, const std::string&);

void createNewClient(DataBaseCollection&, const std::string&);
void deleteClient(DataBaseCollection&, const std::string&);
void createNewBankAccount(DataBaseCollection&, const std::string&);
void addANewCard(DataBaseCollection&, const std::string&);
void deleteABankAccount(DataBaseCollection&, const std::string&);
void deleteCard(DataBaseCollection&, const std::string&);
void reportAllClients(DataBaseCollection&, const std::string&);
void reportAClient(DataBaseCollection&, const std::string&);

void deposit(DataBaseCollection&, const std::string&);
void withdraw(DataBaseCollection&, const std::string&);
void checkBalance(DataBaseCollection&, const std::string&);
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DataBaseCollection.h"

void system();

void logInAsAdmin(const std::vector<Admin*>&, bool&, std::string&);
void logInAsEmployee(const std::vector<Employee*>&, bool&, std::string&);
void logInAsClient(const std::vector<Client*>&, bool&, std::string&);

size_t logInCommand();

bool commandForAdmin(std::string&);
bool commandForEmployees(std::string&);
bool commandForClients(std::string&);

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
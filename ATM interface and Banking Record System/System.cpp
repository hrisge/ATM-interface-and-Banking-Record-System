#include "System.h"

void logInAsAdmin(const std::vector<Admin*>& admins, bool& loggedIn, std::string& egnOfLoggedIn)
{		
	system("CLS");
	while (!loggedIn)
	{
		std::cout << "[ Log in as an Admin ] \n";
		std::string username;
		std::string password;

		std::cout << "$ Insert username : ";
		getline(std::cin, username);
		std::cout << "$ Insert password : ";
		getline(std::cin, password);

		size_t numberOfAdmins = admins.size();
		for (size_t i = 0; i < numberOfAdmins; i++)
		{
			if (username == admins[i]->getAccount().getUsername())
			{
				if (password == admins[i]->getAccount().getPassword())
				{
					std::cout << "[ You have logged in successfully ] \n";
					loggedIn = true;
					egnOfLoggedIn = admins[i]->getEgn();
					return;
				}
				else
				{
					std::cout << "[ You have entered invalid password ] \n";
					loggedIn = false;
					egnOfLoggedIn = "1000000000";
					return;
				}
			}
		}
		std::cout << "[ You have entered invalid username. Try again! ] \n";
		loggedIn = false;
		egnOfLoggedIn = "1000000000";
		return;
	}
}
void logInAsEmployee(const std::vector<Employee*>& employees, bool& loggedIn, std::string& egnOfLoggedIn)
{
	system("CLS");
	while (!loggedIn)
	{
		std::cout << "[ Log in as an Employee] \n";
		std::string username;
		std::string password;

		std::cout << "$ Insert username : ";
		getline(std::cin, username);
		std::cout << "$ Insert password : ";
		getline(std::cin, password);

		size_t numberOfAdmins = employees.size();
		for (size_t i = 0; i < numberOfAdmins; i++)
		{
			if (username == employees[i]->getAccount().getUsername())
			{
				if (password == employees[i]->getAccount().getPassword())
				{
					std::cout << "[ You have logged in successfully ] \n";
					loggedIn = true;
					egnOfLoggedIn = employees[i]->getEgn();
					return;
				}
				else
				{
					std::cout << "[ You have entered invalid password ] \n";
					loggedIn = false;
					egnOfLoggedIn = "1000000000";
					return;
				}
			}
		}
		std::cout << "[ You have entered invalid username ] \n";
		loggedIn = false;
		egnOfLoggedIn = "1000000000";
		return;
	}
}
void logInAsClient(const std::vector<Client*>& clients, bool& loggedIn, std::string& egnOfLoggedIn)
{
	system("CLS");
	while (!loggedIn)
	{
		std::cout << "[ Log in as a Client] \n";
		std::string username;
		std::string password;

		std::cout << "$ Insert username : ";
		getline(std::cin, username);
		std::cout << "$ Insert password : ";
		getline(std::cin, password);

		size_t numberOfAdmins = clients.size();
		for (size_t i = 0; i < numberOfAdmins; i++)
		{
			if (username == clients[i]->getAccount().getUsername())
			{
				if (password == clients[i]->getAccount().getPassword())
				{
					std::cout << "[ You have logged in successfully ] \n";
					loggedIn = true;
					egnOfLoggedIn = clients[i]->getEgn();
					return;
				}
				else
				{
					std::cout << "[ You have entered invalid password ] \n";
					loggedIn = false;
					egnOfLoggedIn = "1000000000";
					return;
				}
			}
		}
		std::cout << "[ You have entered invalid username ] \n";
		loggedIn = false;
		egnOfLoggedIn = "1000000000";
		return;
	}
}

void LogInHelpCommand()
{
	std::cout << "[ If you want to log in as an Admin type '$ loginAsAdmin' ] \n";
	std::cout << "[ If you want to log in as an Employee type '$ loginAsEmployee' ] \n";
	std::cout << "[ If you want to log in as a Client type '$ loginAsClient' ] \n";
}

size_t logInCommand()
{
	std::cout<<"[ Enter a log in type command ] \n ### If you need help type '$ logInHelp' ### \n";
	std::string logInCommand;
	getline(std::cin, logInCommand);
	if (logInCommand == "$ logInHelp")
		return 4;
	else if (logInCommand == "$ loginAsAdmin")
		return 1;
	else if (logInCommand == "$ loginAsEmployee")
		return 2;
	else if (logInCommand == "$ loginAsClient")
		return 3;
	else
	{
		std::cout << "[ You have entered invalid command for logging in ] \n";
		return 0;
	}
}
bool commandForAdmin(std::string& command)
{
	bool correctCommand = false;
	std::cout << "[ Enter a command ] \n ### If you need help type '$ help' ### \n";
	getline(std::cin, command);

	correctCommand = ((command == "$ help") || (command == "$ createNewEmployee") || (command == "$ deleteAnEmployee") || 
		(command == "$ logOut") || (command == "$ exit"));
	while (!correctCommand)
	{
		correctCommand = commandForAdmin(command);
	}
	return correctCommand;
}
bool commandForEmployees(std::string& command)
{
	bool correctCommand = false;
	std::cout << "[ Enter a command ] \n ### If you need help type '$ help' ### \n";
	getline(std::cin, command);

	correctCommand = ((command == "$ help") || (command == "$ createNewClient") || (command == "$ deleteClient") || (command == "$ createNewBankAccount") ||
		(command == "$ addANewCard") || (command == "$ deleteABankAccount") || (command == "$ deleteCard") || (command == "$ reportAllClients") ||
		(command == "$ reportAClient") || (command == "$ logOut") || (command == "$ exit"));
	while (!correctCommand)
	{
		correctCommand = commandForAdmin(command);
	}
	return correctCommand;
}
bool commandForClients(std::string& command)
{
	bool correctCommand = false;
	std::cout << "[ Enter a command ] \n ### If you need help type '$ help' ### \n";
	getline(std::cin, command);

	correctCommand = ((command == "$ help") || (command == "$ deposit") || (command == "$ withdraw") || (command == "$ checkBalance") ||
		(command == "$ logOut") || (command == "$ exit"));
	while (correctCommand)
	{
		correctCommand = commandForAdmin(command);
	}
	return correctCommand;
}

void adminHelpCommand()
{
	system("CLS");
	std::cout << "------List of command for admin------ \n";
	std::cout << "'$ help' \n";
	std::cout << "'$ createNewEmployee' \n";
	std::cout << "'$ deleteAnEmployee' \n";
	std::cout << "'$ logOut' \n";
	std::cout << "'$ exit' \n";
}
void employeeHelpCommand()
{
	system("CLS");
	std::cout << "------List of command for employee------ \n";
	std::cout << "'$ help' \n";
	std::cout << "'$ createNewClient' \n";
	std::cout << "'$ deleteClient' \n";
	std::cout << "'$ createNewBankAccount' \n";
	std::cout << "'$ addANewCard' \n";
	std::cout << "'$ deleteABankAccount' \n";
	std::cout << "'$ deleteCard' \n";
	std::cout << "'$ reportAllClients' \n";
	std::cout << "'$ reportAClient' \n";
	std::cout << "'$ logOut' \n";
	std::cout << "'$ exit' \n";
}
void clientHelpCommand()
{
	system("CLS");
	std::cout << "------List of command for client------ \n";
	std::cout << "'$ help' \n";
	std::cout << "'$ deposit' \n";
	std::cout << "'$ withdraw' \n";
	std::cout << "'$ checkBalance' \n";
	std::cout << "'$ logOut' \n";
	std::cout << "'$ exit' \n";
}

void createNewEmployee(DataBaseCollection& dataBase, const std::string& adminEgn)
{
	dataBase.addAnEmployee(adminEgn);
}
void deleteAnEmployee(DataBaseCollection& dataBase, const std::string& adminEgn)
{
	dataBase.deleteAnEmployee(adminEgn);
}

void createNewClient(DataBaseCollection& dataBase, const std::string& emmployeeEgn)
{
	dataBase.addAClient(emmployeeEgn);
}
void deleteClient(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.deleteAClient(employeeEgn);
}
void createNewBankAccount(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.addANewBankAccount(employeeEgn);
}
void addANewCard(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.addANewBankCard(employeeEgn);
}
void deleteABankAccount(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.closeABankAccount(employeeEgn);
}
void deleteCard(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.closeABankCard(employeeEgn);
}
void reportAllClients(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.reportOfClients(employeeEgn);
}
void reportAClient(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.reportAClient(employeeEgn);
}

void deposit(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.inputMoney(employeeEgn);
}
void withdraw(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.withdrawMoney(employeeEgn);
}
void checkBalance(DataBaseCollection& dataBase, const std::string& employeeEgn)
{
	dataBase.checkBalance(employeeEgn);
}

void system()
{
	DataBaseCollection dataBase;
	bool proggramIsRunning = true;
	system("CLS");
	while (proggramIsRunning)
	{
		bool loggedIn = false;
		std::string egnOfLoggedInPerson;
		size_t typeOfAccountOfLoggedInPerson = 0;;

		size_t logIn = logInCommand();
		if (logIn == 0)
		{
			loggedIn = false;
			continue;
		}
		else if (logIn == 4)
		{
			LogInHelpCommand();
			loggedIn = false;
			continue;
		}
		else if (logIn == 1)
		{
			logInAsAdmin(dataBase.getAdmins(), loggedIn, egnOfLoggedInPerson);
			typeOfAccountOfLoggedInPerson = 1;
		}
		else if (logIn == 2)
		{
			logInAsEmployee(dataBase.getEmployees(), loggedIn, egnOfLoggedInPerson);
			typeOfAccountOfLoggedInPerson = 2;
		}
		else
		{
			logInAsClient(dataBase.getClients(), loggedIn, egnOfLoggedInPerson);
			typeOfAccountOfLoggedInPerson = 3;
		}

		while (loggedIn)
		{
			if (typeOfAccountOfLoggedInPerson == 1)
			{
				std::string command;
				bool correctCommand = commandForAdmin(command);
				if (command == "$ help")
					adminHelpCommand();
				else if (command == "$ createNewEmployee")
					createNewEmployee(dataBase, egnOfLoggedInPerson);
				else if (command == "$ deleteAnEmployee")
					deleteAnEmployee(dataBase, egnOfLoggedInPerson);
				else if (command == "$ logOut")
				{
					loggedIn = false;
					continue;
				}
				else if (command == "$ exit")
				{
					loggedIn = false;
					proggramIsRunning = false;
					continue;
				}
			}
			else if (typeOfAccountOfLoggedInPerson == 2)
			{
				std::string command;
				bool correctCommand = commandForEmployees(command);
				if (command == "$ help")
					employeeHelpCommand();
				else if (command == "$ createNewClient")
					createNewClient(dataBase, egnOfLoggedInPerson);
				else if (command == "$ deleteClient")
					deleteClient(dataBase, egnOfLoggedInPerson);
				else if (command == "$ createNewBankAccount")
					createNewBankAccount(dataBase, egnOfLoggedInPerson);
				else if (command == "$ addANewCard")
					addANewCard(dataBase, egnOfLoggedInPerson);
				else if (command == "$ deleteABankAccount")
					deleteABankAccount(dataBase, egnOfLoggedInPerson);
				else if (command == "$ deleteCard")
					deleteCard(dataBase, egnOfLoggedInPerson);
				else if (command == "$ reportAllClients")
					reportAllClients(dataBase, egnOfLoggedInPerson);
				else if (command == "$ reportAClient")
					reportAClient(dataBase, egnOfLoggedInPerson);
				else if (command == "$ logOut")
				{
					loggedIn = false;
					continue;
				}
				else if (command == "$ exit")
				{
					loggedIn = false;
					proggramIsRunning = false;
					continue;
				}
			}
			else if (typeOfAccountOfLoggedInPerson == 3)
			{
				std::string command;
				bool correctCommand = commandForClients(command);
				if (command == "$ help")
					clientHelpCommand();
				else if (command == "$ deposit")
					deposit(dataBase, egnOfLoggedInPerson);
				else if (command == "$ withdraw")
					withdraw(dataBase, egnOfLoggedInPerson);
				else if (command == "$ checkBalance")
					checkBalance(dataBase, egnOfLoggedInPerson);
				else if (command == "$ logOut")
				{
					loggedIn = false;
					continue;
				}
				else if (command == "$ exit")
				{
					loggedIn = false;
					proggramIsRunning = false;
					continue;
				}

			}
		}
	}
}
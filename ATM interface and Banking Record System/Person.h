#pragma once
#include <iostream>
#include "DateOfBirth.h"
#include "Name.h"
#include "Account.h"

class Person
{
	Account account; 
	std::string egn; 
	Name name; 
	DateOfBirth dateOfBirth;
	size_t mobileNumber; 
	std::string adress; 


public:
	Person();
	Person(const char*, const char*, const char*, const char* , const char* , const char* , const size_t , const size_t , const size_t , const size_t ,
		const char*);
	Person(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, 
		const size_t, const size_t, const size_t, const size_t, const std::string&);
	Person(const Account&, const char*, const Name&, const DateOfBirth&, const size_t, const char*);

	Person(const Person&);	
	virtual ~Person() = default;

	const Account& getAccount() const;
	const std::string& getEgn() const;
	const Name& getName() const;
	const DateOfBirth& getDateOfBirth() const;
	const size_t getMobileNumber() const;
	const std::string& getAdress() const;

	void setAccount(const char*, const char*);
	void setAccount(const std::string&, const std::string&);
	void setAccount(const Account&);
	void setEgn(const char*);
	void setEgn(const std::string&);
	void setName(const char*, const char*, const char*);
	void setName(const std::string&, const std::string&, const std::string&);
	void setName(const Name&);
	void setDateOfBirth(const size_t, const size_t, const size_t);
	void setDateOfBirth(const DateOfBirth&);
	void setMobileNumber(const size_t);
	void setAdress(const char*);
	void setAdress(const std::string&);

	virtual void nothing() const = 0;
};
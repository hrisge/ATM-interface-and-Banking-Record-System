#pragma once
#include <iostream>
#include "Person.h"
#include "Employee.h"

struct Admin : public Person
{
	Admin();
	Admin(const char*, const char*, const char*, const char*, const char*, const char*, const size_t, const size_t, const size_t, const size_t, 
		const char*);
	Admin(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string, 
		const size_t, const size_t, const size_t, const size_t, std::string&);
	Admin(const Account&, const char*, const Name&, const DateOfBirth&, const size_t, const char*);
	Admin(const Admin&);

	const Admin& getAdmin() const;

	void addAnEmployee(const std::vector<Employee*>&, bool&, Employee&);

	void nothing() const override;


};
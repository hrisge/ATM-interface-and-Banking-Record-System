#pragma once
#include <iostream>

class DateOfBirth
{
	size_t day;
	size_t month;
	size_t year;

public:

	void setDay(size_t);
	void setMonth(size_t);
	void setYear(size_t);

	virtual size_t getDay() const = 0;
	virtual size_t getMonth() const = 0;
	virtual size_t getYear() const = 0;
};
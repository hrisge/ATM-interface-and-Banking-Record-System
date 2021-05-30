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

	const size_t getDay() const ;
	const size_t getMonth() const;
	const size_t getYear() const;

};
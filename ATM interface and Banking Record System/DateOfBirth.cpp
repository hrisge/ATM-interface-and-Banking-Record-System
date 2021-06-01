#include "DateOfBirth.h"

void DateOfBirth::setDay(size_t day)
{
	if (day < 1 || day>12)
		throw std::exception("Day of birth parameter is too small or too big");
	this->day = day;
}

void DateOfBirth::setMonth(size_t month)
{
	if (month < 1 || month>12)
		throw std::exception("Month of birth parameter is too small or too big");
	this->month = month;
}

void DateOfBirth::setYear(size_t year)
{
	if (year < 1900 || year>2021)
		throw std::exception("Year of birth parameter is too small or too big");
	this->year = year;
}

const size_t DateOfBirth::getDay() const
{
	return day;
}

const size_t DateOfBirth::getMonth() const
{
	return month;
}

const size_t DateOfBirth::getYear() const
{
	return year;
}
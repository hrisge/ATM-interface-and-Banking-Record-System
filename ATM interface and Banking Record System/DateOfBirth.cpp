#include "DateOfBirth.h"

void DateOfBirth::setDay(size_t day)
{
	this->day = day;
}

void DateOfBirth::setMonth(size_t month)
{
	this->month = month;
}

void DateOfBirth::setYear(size_t year)
{
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
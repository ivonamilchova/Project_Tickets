#include "Date.h"
#include <iostream>
#include <cstring>

void Date::initDate(const size_t dayParam, const size_t monthParam, const size_t yearParam)
{
	if (yearParam < CURRENT_YEAR) {
		std::cout << "Invalid year!\n";
		return;
	}
	if (monthParam < 1 || monthParam > 12) {
		std::cout << "Invalid month!\n";
		return;
	}
	if (monthParam == 1 || monthParam == 3 || monthParam == 5 || monthParam == 7 || monthParam == 8 || monthParam == 10 || monthParam == 12) {
		if (dayParam >= 1 && dayParam <= 31) {
			this->year = yearParam;
			this->month = monthParam;
			this->day = dayParam;
		}
		else {
			std::cout << "Invalid day!\n";
			return;
		}
	}
	else if (monthParam == 4 || monthParam == 6 || monthParam == 9 || monthParam == 11) {
		if (dayParam >= 1 && dayParam <= 30) {
			this->year = yearParam;
			this->month = monthParam;
			this->day = dayParam;
		}
		else {
			std::cout << "Invalid day!\n";
			return;
		}
	}
	else if (monthParam == 2 && (yearParam % 400) == 4) {
		if (dayParam >= 1 && dayParam <= 29) {
			this->year = yearParam;
			this->month = monthParam;
			this->day = dayParam;
		}
		else {
			std::cout << "Invalid day!\n";
			return;
		}
	}
	else if (monthParam == 2 && (yearParam % 400) != 4) {
		if (dayParam >= 1 && dayParam <= 28) {
			this->year = yearParam;
			this->month = monthParam;
			this->day = dayParam;
		}
		else {
			std::cout << "Invalid day!\n";
			return;
		}
	}
}

void Date::init()
{
	std::cout << "Input date:\n";
	size_t dayParam;
	std::cout << "day: ";
	std::cin >> dayParam;
	size_t monthParam;
	std::cout << "month: ";
	std::cin >> monthParam;
	size_t yearParam;
	std::cout << "year: ";
	std::cin >> yearParam;
	this->initDate(dayParam, monthParam, yearParam);

}

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(const size_t dayParam, const size_t monthParam, const size_t yearParam)
{
	this->initDate(dayParam, monthParam, yearParam);
}

Date::Date(const Date& other)
{
	this->initDate(other.day, other.month, other.year);
}

Date& Date::operator=(const Date& other)
{
	if (this != &other) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}

size_t Date::getDay() const
{
	return this->day;
}

size_t Date::getMonth() const
{
	return this->month;
}

size_t Date::getYear() const
{
	return this->year;
}



bool Date::operator==(const Date& other) const
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator>(const Date& other) const
{
	return this->year > other.year ||
		(this->year == other.year && this->month > other.month) ||
		(this->year == other.year && this->month == other.month && this->day > other.day);
}

bool Date::operator<(const Date& other) const
{
	return this->year < other.year ||
		(this->year == other.year && this->month < other.month) ||
		(this->year == other.year && this->month == other.month && this->day < other.day);
}

bool Date::operator>=(const Date& other) const
{
	return (*this > other) || (*this == other);
}

bool Date::operator<=(const Date& other) const
{
	return (*this < other) || (*this == other);
}


void Date::print() const
{
	std::cout << this->day << "." << this->month << "." << this->year << "\n";
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
	return out << d.day << "." << d.month << "." << d.year;
}

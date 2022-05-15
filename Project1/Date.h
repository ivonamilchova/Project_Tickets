#ifndef __DATE
#define __DATE
#define CURRENT_YEAR 2022
#include <iostream>

class Date {
private:
	size_t day;
	size_t month;
	size_t year;
	void initDate(const size_t dayParam, const size_t monthParam, const size_t yearParam);


public:
	void init();
	Date();
	Date(const size_t dayParam, const size_t monthParam, const size_t yearParam);
	Date(const Date& other);
	Date& operator=(const Date& other);
	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;


	bool operator== (const Date& other)const;
	bool operator> (const Date& other) const;
	bool operator< (const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<=(const Date& other) const;

	void print()const;
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
};


#endif // !__DATE

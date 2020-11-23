#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
class Date
{
	int _day;
	int _month;
	int _year;
public:
	Date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	};
	Date() {};
	~Date() {};
	int GetDay() const { return _day; };
	int GetMonth() const { return _month; };
	int GetYear() const { return _year; };
	void SetDay(int d) { _day = d; };
	void SetMonth(int m) { _month = m; };
	void SetYear(int y) { _year = y; };

	friend std::ostream& operator<<(std::ostream& os, const Date& date) {
		return os << date._day << " " << date._month << " " << date._year;
	};

	friend std::istream& operator>>(std::istream& is, Date& date) {
		return is >> date._day >> date._month >> date._year;
	};
};
#endif


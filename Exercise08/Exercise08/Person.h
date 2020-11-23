#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Address.h"
#include "Date.h"
class Person
{
private:
	std::string _name;
	std::string _surname;
	Address _address;
	Date _dateOfBirth;
public:
	Person(){};
	Person(std::string name, std::string surname, Address address, Date date) :
		_name(name), _surname(surname), _address(address), _dateOfBirth(date) {};
	~Person() {};
	std::string GetName() const { return _name; };
	std::string GetSurname() const { return _surname; };
	Address GetAddress() const { return _address; };
	Date GetDate() const { return _dateOfBirth; };
	void SetName(std::string name) { _name = name; };
	void SetSurname(std::string surname) { _surname = surname; };
	void SetAddress(Address a) { _address = a; };
	void SetDate(Date d) { _dateOfBirth = d; };
	friend std::ostream& operator<<(std::ostream& os, const Person& person) {
		return os << person._name << " " << person._surname << " " << person._address << " " << person._dateOfBirth;
	}
	friend std::istream& operator>>(std::istream& is, Person& person) {
		return is >> person._name >> person._surname >> person._address >> person._dateOfBirth;
	};

};
#endif


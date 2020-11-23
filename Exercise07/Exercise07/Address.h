#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
class Address
{
	std::string _street;
	std::string _city;
	std::string _zip;
public:
	Address(std::string street, std::string city, std::string zip) {
		_street = street;
		_city = city;
		_zip = zip;
	};
	Address() {};
	~Address() {};
	std::string GetStreet() const { return _street; };
	std::string GetCity() const { return _city; };
	std::string GetZip() const { return _zip; };
	void SetStreet(std::string s) { _street = s; };
	void SetCity(std::string c) { _city = c; };
	void SetZip(std::string z) { _zip = z; };
	friend std::ostream& operator<<(std::ostream& os, const Address& address) {
		return os << address._street << " " << address._city << " " << address._zip;
	};
	friend std::istream& operator>>(std::istream& is, Address& address) {
		return is >> address._street >> address._city >> address._zip;
	};
};
#endif


#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace Entity {
	class Person
	{
	private:
		std::string name;
		std::string phoneNumber;
		int id;
	public:
		Person(std::string name, std::string phoneNumber, int id);
		//Pro� mus� Person obsahovat bezparametrick� konstruktor? - jinak err na ��dku 23 v PhoneList.cpp
		Person();
		~Person();
		std::string GetName() const;
		std::string GetNumber() const;
		int GetId() const;
	};
}; 
#endif


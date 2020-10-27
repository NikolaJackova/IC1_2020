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
		~Person();
		std::string GetName() const;
		std::string GetNumber() const;
		int GetId() const;
	};
}; 
#endif


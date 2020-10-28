#pragma once
#ifndef PHONELIST_H
#define PHONELIST_H

#include "Person.h"

namespace Model {
	class PhoneList
	{
		class Node {
		public:
			Node* next;
			Entity::Person data;
		};
	private:
		Node* _start;
	public:
		PhoneList();
		~PhoneList();
		void addPerson(Entity::Person p);
		std::string findNumber(int id) const;
		std::string findNumber(std::string name) const;
	};
}
#endif


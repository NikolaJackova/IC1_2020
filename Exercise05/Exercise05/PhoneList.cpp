#include "PhoneList.h"

Model::PhoneList::PhoneList()
{
	_start = nullptr;
}

Model::PhoneList::~PhoneList()
{
	delete[] _start;
}

void Model::PhoneList::addPerson(Entity::Person p)
{
	Node* newNode = new Node{};
	newNode->data = p;
	newNode->next = this->_start;
	_start = newNode;
}

std::string Model::PhoneList::findNumber(int id) const
{
	return std::string();
}

std::string Model::PhoneList::findNumber(std::string name) const
{
	return std::string();
}

Model::PhoneList::Node* Model::PhoneList::GetStart() const
{
	return nullptr;
}

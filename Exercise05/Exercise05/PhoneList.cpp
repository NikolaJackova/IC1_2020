#include "PhoneList.h"
#include <stdexcept>
#include <iostream>

using namespace std;
Model::PhoneList::PhoneList()
{
	_start = nullptr;
}

Model::PhoneList::~PhoneList()
{
	//A value of type Model::PhoneList::Node* cannot be used to initialize an entity of type Model::PhoneList::Node*
	Node* node = _start;
	while (node != nullptr) {
		Node* tmp = node->next;
		delete node;
		node = tmp;
	}
}

void Model::PhoneList::addPerson(Entity::Person p)
{
	Node* newNode = new Node{};
	newNode->data = p;
	newNode->next = this->_start;
	_start = newNode;
}

string Model::PhoneList::findNumber(int id) const
{
	try {
		if (id < 0) {
			throw invalid_argument("Id is a negative number!");
		}
	}
	catch (invalid_argument& e) {
		return e.what();
	}
	Node* node = _start;
	try {
		while (node != nullptr) {
			if (node->data.GetId() == id) {
				return node->data.GetNumber();
			}
			node = node->next;
		}
		throw exception("Id is not in the list!");
	}
	catch (exception& e) {
		return e.what();
	}

}

string Model::PhoneList::findNumber(std::string name) const
{
	try {
		if (name.length() == 0) {
			throw invalid_argument("Name is empty!");
		}
	}
	catch (invalid_argument& e) {
		return e.what();
	}
	Node* node = _start;
	try {
		while (node != nullptr) {
			if (node->data.GetName() == name) {
				return node->data.GetNumber();
			}
			node = node->next;
		}
		throw exception("Name is not is the list!");
	}
	catch (exception& e) {
		return e.what();
	}
}

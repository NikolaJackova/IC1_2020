#include "Person.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Entity::Person::Person(std::string name, std::string phoneNumber, int id)
{
    try {
        if (id < 0 || name.length() == 0 || phoneNumber.length() == 0) {
            throw invalid_argument("Invalid arguments!");
        }
    }
    catch (invalid_argument& e) {
        cerr << e.what() << endl;
    }
    this->id = id;
    this->name = name;
    this->phoneNumber = phoneNumber;
}

Entity::Person::Person()
{
}

Entity::Person::~Person()
{
}

std::string Entity::Person::GetName() const
{
    return name;
}

std::string Entity::Person::GetNumber() const
{
    return phoneNumber;
}

int Entity::Person::GetId() const
{
    return id;
}

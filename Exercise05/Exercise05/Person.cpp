#include "Person.h"

Entity::Person::Person(std::string name, std::string phoneNumber, int id)
{
    this->id = id;
    this->name = name;
    this->phoneNumber = phoneNumber;
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

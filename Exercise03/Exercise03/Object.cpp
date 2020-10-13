#include "Object.h"

Object::Object(int id)
{
	this->id = id;
}

Object::~Object()
{
}

int Object::GetId() const
{
	return id;
}

double Object::GetX() const
{
	return x;
}

double Object::GetY() const
{
	return y;
}

void Object::SetX(double x)
{
	this->x = x;
}

void Object::SetY(double y)
{
	this->y = y;
}

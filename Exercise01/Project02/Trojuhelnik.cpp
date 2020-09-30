#include "Trojuhelnik.h"
#include <iostream>
using namespace std;

bool Trojuhelnik::lzeSestrojit()
{
	return ((this->a + this->b) > this->c && (this->a + this->c) > this->b && (this->b + this->c) > this->a);
}

void Trojuhelnik::setA(int a)
{
	this->a = a;
}

void Trojuhelnik::setB(int b)
{
	this->b = b;
}

void Trojuhelnik::setC(int c)
{
	this->c = c;
}

int Trojuhelnik::getA()
{
	return this->a;
}

int Trojuhelnik::getB()
{
	return this->b;
}

int Trojuhelnik::getC()
{
	return this->c;
}

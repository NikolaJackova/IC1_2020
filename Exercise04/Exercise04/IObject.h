#pragma once
#include <string>
#ifndef IOBJECT_H
#define IOBJECT_H

class IObject
{
public:
	virtual ~IObject();
	virtual std::string ToString() = 0;
};
#endif


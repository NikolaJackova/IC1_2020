#pragma once
#include "IObject.h"
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

class IComparable :
    public IObject
{
public: 
    virtual ~IComparable();
    virtual int CompareTo(IComparable* obj) const = 0;
    virtual std::string ToString() override = 0;
};
#endif


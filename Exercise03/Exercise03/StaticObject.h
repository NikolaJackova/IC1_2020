#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"

enum class TypeOfBarrier{Rock, SmallPlant, BigPlant};
class StaticObject :
    public Object
{
public:
    StaticObject(int id, TypeOfBarrier type);
    TypeOfBarrier GetType() const;
private: 
    TypeOfBarrier type;
};
#endif

